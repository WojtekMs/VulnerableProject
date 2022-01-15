cmake_minimum_required(VERSION 3.13)

project(networking)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(COMPILE_FLAGS -Wall -Wextra -pedantic -Wconversion)
add_compile_options(${COMPILE_FLAGS})

add_subdirectory(networking-src)
add_subdirectory(networking-exe)

install(
  TARGETS client server
  DESTINATION ${CMAKE_BINARY_DIR}
  COMPONENT networking
  EXCLUDE_FROM_ALL)
