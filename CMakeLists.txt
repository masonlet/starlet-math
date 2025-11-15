cmake_minimum_required(VERSION 3.20)
project(starlet_math VERSION 1.0.0)

set(PROJECT_INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/inc")

if(NOT TARGET ${PROJECT_NAME})
  add_library(${PROJECT_NAME} INTERFACE)

  target_include_directories(${PROJECT_NAME} 
    INTERFACE 
    $<BUILD_INTERFACE:${PROJECT_INC_DIR}>
    $<INSTALL_INTERFACE:include>
  )
  target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)
endif()

option(BUILD_TESTS "Build unit tests" OFF)

if(BUILD_TESTS)
  if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
  endif()

  enable_testing()

  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
  )

  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)
  add_subdirectory(tests)
endif()
