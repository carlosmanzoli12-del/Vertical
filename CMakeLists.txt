cmake_minimum_required(VERSION 3.20)
project(StreamForge VERSION 0.1.0 LANGUAGES CXX)

option(STREAMFORGE_BUILD_TESTS "Build StreamForge tests" ON)

add_library(streamforge_core STATIC src/core/stream_target.cpp)
target_include_directories(streamforge_core PUBLIC include)
target_compile_features(streamforge_core PUBLIC cxx_std_20)
set_target_properties(streamforge_core PROPERTIES POSITION_INDEPENDENT_CODE ON)

if(MSVC)
  target_compile_options(streamforge_core PRIVATE /W4 /permissive-)
else()
  target_compile_options(streamforge_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(STREAMFORGE_BUILD_TESTS)
  enable_testing()
  add_executable(streamforge_core_tests tests/core_tests.cpp)
  target_link_libraries(streamforge_core_tests PRIVATE streamforge_core)
  add_test(NAME streamforge_core_tests COMMAND streamforge_core_tests)
endif()
