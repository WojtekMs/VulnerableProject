add_library(networking-lib src/utils.cpp src/Server.cpp src/Client.cpp)

target_include_directories(networking-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
