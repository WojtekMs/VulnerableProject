add_executable(client client_main.cpp)
add_executable(server server_main.cpp)

target_link_libraries(client networking-lib)
target_link_libraries(server networking-lib)
