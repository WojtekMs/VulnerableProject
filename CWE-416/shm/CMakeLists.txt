cmake_minimum_required(VERSION 3.13)
project(shm)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SRC 
    alcohol.cpp 
    cargo.cpp 
    coordinates.cpp 
    fruit.cpp
    Game.cpp 
    island.cpp 
    item.cpp 
    Map.cpp 
    Menu.cpp
    player.cpp 
    ship.cpp 
    Storable.cpp 
    Store.cpp 
    Time.cpp)
    
set(FLAGS -Wall -Wextra -Werror -Wconversion -O3)

add_library(${PROJECT_NAME}-lib STATIC ${SRC})
add_executable(${PROJECT_NAME} main.cpp ${SRC})

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

set_target_properties(${PROJECT_NAME} PROPERTIES
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED ON)                  
set_target_properties(${PROJECT_NAME}-lib PROPERTIES
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED ON)



