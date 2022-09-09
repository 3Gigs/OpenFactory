cmake_minimum_required(VERSION 3.20)
project(Untitled_Game)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME} src/main.c)

find_package(raylib 3.0 REQUIRED)
target_link_libraries(${PROJECT_NAME} raylib)
target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_INCLUDE_DIRS})

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()