cmake_minimum_required(VERSION 3.20)
project(OpenFactory)

set(CMAKE_C_STANDARD 11)

add_executable(main src/main.c)

find_package(raylib 3.0 REQUIRED)
target_link_libraries(main raylib)
target_include_directories(main PRIVATE ${raylib_INCLUDE_DIRS})

if (APPLE)
    target_link_libraries(main "-framework IOKit")
    target_link_libraries(main "-framework Cocoa")
    target_link_libraries(main "-framework OpenGL")
endif()