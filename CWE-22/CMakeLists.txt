cmake_minimum_required(VERSION 3.13)

project(tstat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(COMPILE_FLAGS -Wall -pedantic -Wconversion -Wextra)
add_compile_options(${COMPILE_FLAGS})

enable_testing()

add_subdirectory(submodules/networking)
add_subdirectory(src/tstat)
add_subdirectory(executables/tstat)
add_subdirectory(test)

install(TARGETS tstat tstat_daemon DESTINATION ${CMAKE_BINARY_DIR} COMPONENT tstat)


