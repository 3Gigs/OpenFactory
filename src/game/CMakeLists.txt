cmake_minimum_required(VERSION 3.20)
project(Game)
set(CMAKE_C_STANDARD 11)

add_library(Game STATIC game.c events.c controls.c world.c)
target_include_directories(Game PUBLIC game.h)

find_package(raylib 3.0 REQUIRED)
target_link_libraries(Game raylib)
target_include_directories(Game PRIVATE ${raylib_INCLUDE_DIRS})

if (APPLE)
    target_link_libraries(Game "-framework IOKit")
    target_link_libraries(Game "-framework Cocoa")
    target_link_libraries(Game "-framework OpenGL")
endif()

