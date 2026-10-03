cmake_minimum_required(VERSION 3.14)
project(ex1_telemetry CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

if(MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_library(telemetry src/telemetry.cpp)
target_include_directories(telemetry PUBLIC include)

enable_testing()

add_executable(test_public tests/test_public.cpp)
target_include_directories(test_public PRIVATE tests)
target_link_libraries(test_public PRIVATE telemetry)
add_test(NAME test_public COMMAND test_public)

# I valutatori copiano qui i test nascosti: se il file esiste viene compilato automaticamente.
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_hidden.cpp)
  add_executable(test_hidden tests/test_hidden.cpp)
  target_include_directories(test_hidden PRIVATE tests)
  target_link_libraries(test_hidden PRIVATE telemetry)
  add_test(NAME test_hidden COMMAND test_hidden)
endif()
