cmake_minimum_required(VERSION 3.20)

set(MATH_NAME starlet_math)
set(MATH_INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/inc")

if(NOT TARGET ${MATH_NAME})
  add_library(${MATH_NAME} INTERFACE)

  target_include_directories(${MATH_NAME} 
    INTERFACE 
    $<BUILD_INTERFACE:${MATH_INC_DIR}>
    $<INSTALL_INTERFACE:include>
  )
endif()
