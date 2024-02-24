# Raylib CMake Template #

## Introduction ##

This project provides a CMake-supported template for [RayLib](https://github.com/raysan5/raylib) projects, aiming to simplify and standardize the build process across different platforms. It leverages CMake's powerful cross-platform build system capabilities to enhance Raylib project development.

## Features ##

- CMake Support: Simplifies building and compiling Raylib projects across Windows, Linux, and MacOS.
- Clang Format: Ensures consistent code style across your project.
- Project Structure: Organized folders for source code (src/), game resources (resources/), and CMake modules (cmake/).

## Requirements ##
- CMake
- Git
- Clang-format (optional)
- Visual Studio with C++ development tools (Windows)
- XCode (macOS)

## Status

- [x] Basic CMake support
- [ ] Project generation
  - [ ] Windows
  - [ ] Linux
  - [x] MacOS

## Installation Guide ##
Fork and Clone: Start by forking this project and cloning it to your local machine.

#### Building on MacOS
```bash
$ cmake -B build-mac -G Xcode -DCMAKE_BUILD_TYPE=Debug
``` 

#### Building on Windows
```bash
$ cmake -B build-win -G"Visual Studio 17 2022"  -DCMAKE_BUILD_TYPE=Debug
```

#### Building in CLI
```bash
$ cmake -B build-cli -DCMAKE_BUILD_TYPE=Debug
$ cd build-cli
$ make -j$(nproc)
```

### Usage ###
After building the project, you can start developing your project with Raylib by adding your source files to the src/ directory and resources to resources/. The CMake scripts are designed to handle the rest.

## Acknowledgments ##
- Inspiration and base configuration adapted from [SasLuca's raylib-cmake-template](https://github.com/SasLuca/raylib-cmake-template) and [Asmaloney's GDExtensionTemplate](https://github.com/asmaloney/GDExtensionTemplate).
- Special thanks to the Raylib community for their support and contributions.

