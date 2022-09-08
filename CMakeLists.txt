cmake_minimum_required(VERSION 3.20)
project(OpenFactory)

set(CMAKE_C_STANDARD 11)

add_executable(OpenFactory src/main.c)

find_package(raylib 3.0 REQUIRED)
target_link_libraries(OpenFactory raylib)
target_include_directories(OpenFactory PRIVATE ${raylib_INCLUDE_DIRS})

if (APPLE)
    target_link_libraries(OpenFactory "-framework IOKit")
    target_link_libraries(OpenFactory "-framework Cocoa")
    target_link_libraries(OpenFactory "-framework OpenGL")
endif()