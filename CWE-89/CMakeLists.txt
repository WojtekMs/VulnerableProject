cmake_minimum_required(VERSION 3.13)

project(sql-injection)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE /usr/include/mysql++ /usr/include/mysql)
target_link_libraries(${PROJECT_NAME} mysqlpp mysqlclient)
