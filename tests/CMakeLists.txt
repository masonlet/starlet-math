add_executable(${PROJECT_NAME}_tests
  vec2_test.cpp
  vec3_test.cpp
  vec4_test.cpp
)

target_link_libraries(${PROJECT_NAME}_tests
  PRIVATE
    ${PROJECT_NAME}
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_tests)
