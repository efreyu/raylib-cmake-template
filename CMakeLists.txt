cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME raylib-template)

option(
        AUTOFORMAT_SRC_ON_CONFIGURE
        "If enabled, clang-format will be used to format all sources in src/ during configuration"
        ON
)

# Default Android settings, not tested yet
# Use $ANDROID_NDK_ROOT/build/cmake/android.toolchain.cmake toolchain
if (CMAKE_SYSTEM_NAME STREQUAL Android)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{ANDROID_NDK_ROOT}/build/cmake/android.toolchain.cmake" CACHE FILEPATH "Android NDK's CMake toolchain file")
    set(ANDROID_PLATFORM android-21 CACHE STRING "Android target platform API level")
    # armeabi-v7a arm64-v8a x86_64 x86
    #    set(ANDROID_ABI armeabi-v7a CACHE STRING "Android target ABI architecture")
    set(ANDROID_TOOLCHAIN clang)
    set(ANDROID_STL c++_shared)
    set(ANDROID ON)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    set(CMAKE_SYSTEM_VERSION 21)
endif ()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)
set(CMAKE_MESSAGE_LOG_LEVEL STATUS)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

project("${PROJECT_NAME}"
        LANGUAGES
        C CXX
        VERSION
        0.1.0
)

# =======================================================================
# Compiler identification
# =======================================================================

set(compiler_is_clang "$<OR:$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:Clang>>")
set(compiler_is_gnu "$<CXX_COMPILER_ID:GNU>")
set(compiler_is_msvc "$<CXX_COMPILER_ID:MSVC>")

# =======================================================================
# Executable setup/configuration
# =======================================================================

# add library sources
file(GLOB_RECURSE project_sources
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.[hc]"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.[hc]pp"
)

# add the executable
add_executable(${PROJECT_NAME}
        ${project_sources}
)

# set compiler options for the executable based on the compiler being used
target_compile_options(${PROJECT_NAME} PUBLIC
        $<${compiler_is_msvc}:
        /EHsc
        /utf-8
        /Zc:preprocessor
        $<$<CONFIG:Debug>:
        /MDd
        >
        $<$<CONFIG:Release>:
        /MD
        /O2
        /W4
        >
        >
        $<$<NOT:${compiler_is_msvc}>:
        -g
        -Wall
        -Wno-unused-value
        $<${compiler_is_gnu}:
        -Wno-attributes
        -Wno-attributes=bt::
        >
        $<${compiler_is_clang}:
        -Wno-ignored-attributes
        -Wno-unknown-attributes
        >
        $<$<CONFIG:Debug>:
        -fno-omit-frame-pointer
        -O0
        >
        $<$<CONFIG:Release>:
        -O3
        >
        >
)

if (NOT APPLE)
    # linker options
    target_link_options(${PROJECT_NAME} PRIVATE
            $<$<NOT:${compiler_is_msvc}>:
            -static-libgcc
            -static-libstdc++
            -Wl,-R,'$$ORIGIN'
            >
    )
endif ()

# =======================================================================
# Optional configuration / build features
# =======================================================================

if (AUTOFORMAT_SRC_ON_CONFIGURE MATCHES ON)
    include(clang-format)
endif ()

# =======================================================================
# Dependency linkage
# =======================================================================

include(raylib-configuration)

# dependency linkage
target_link_libraries(${PROJECT_NAME}
        PRIVATE raylib
)

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        CMAKE_EXPORT_COMPILE_COMMANDS ON
        CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON
        COMPILE_WARNING_AS_ERROR ON
)

file(COPY resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})