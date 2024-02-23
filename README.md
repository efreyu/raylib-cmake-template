# Raylib project template with CMake support #

## Motivation ##

This project based on [RayLib](https://github.com/raysan5/raylib) and the main idea was to bring the posibility to use CMake as the main build system for the RayLib projects.

## Project structure ##
- src/ - source code
- resources/ - your game resources
- cmake/ - CMake modules and scripts

## Features

Added Clang format support for the project.

## Status

- [x] Basic CMake support
- [ ] Project generation
  - [ ] Windows
  - [ ] Linux
  - [x] MacOS

## How to install and compile
Make sure on your workstation you have installed **cmake** and **git** (**clang-format** is optional).
For Windows users need to install **Visual Studio** with C++ development tools.
For macOS users need to install **XCode**.

#### Build and configure project files ####
First you need to fork this project and clone it.

### MacOS
```bash
$ cmake -B build-mac -G Xcode -DCMAKE_BUILD_TYPE=Debug
``` 

### Windows
```bash
$ cmake -B build-win -G"Visual Studio 17 2022"  -DCMAKE_BUILD_TYPE=Debug
```

### Building in CLI
```bash
$ cmake -B build-cli -DCMAKE_BUILD_TYPE=Debug
$ cd build-cli
$ make install
```

## Credits
inspired by [SasLuca's raylib-cmake-template](https://github.com/SasLuca/raylib-cmake-template) and [Asmaloney's GDExtensionTemplate](https://github.com/asmaloney/GDExtensionTemplate)

