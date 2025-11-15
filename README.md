# Starlet Math

![Tests](https://github.com/masonlet/starlet-math/actions/workflows/test.yml/badge.svg)
[![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg)](https://isocpp.org/std/the-standard)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](./LICENSE)

A lightweight header-only math library for **Starlet** projects.

⚠️ **Note**
This is **NOT** intended to be a complete math library!
It's minimal and straightforward to make the math operations easier to understand and extend.
This makes it perfect for learning, experimentation, but not a drop-in replacement for full-fledged math libraries.

## Features

- Basic vector types: `Vec2`, `Vec3`, `Vec4`
- `Transform` struct for position, rotation, scale
- `Mat4` 4x4 matrix with:
    - Identity, transpose, inverse
    - Translation, rotation, scaling
    - `lookAt` and `perspective` helpers
    - Composition with `Transform`
- Constants and helpers:
    `pi`, `radians()`, `degrees()`
- **Starlet** Project Constants


<br/>


## Prerequisites
- C++20 or later
- CMake 3.20+

## Using as a Dependency
```cmake
include(FetchContent)

FetchContent_Declare(starlet_math
  GIT_REPOSITORY https://github.com/masonlet/starlet-math.git 
  GIT_TAG main
)
FetchContent_MakeAvailable(starlet_math)

target_link_libraries(app_name PRIVATE starlet_math)
```

<br/>

## Building and Testing
```bash
# 1. Clone starlet-math
git clone https://github.com/masonlet/starlet-math.git
cd starlet-math

# 2. Create a Build Directory and Generate Build Files
mkdir build
cd build
cmake -DBUILD_TESTS=ON ..

# 3. Build and run tests
cmake --build .
ctest
```

<br/>

## License
MIT License — see [LICENSE](./LICENSE) for details.