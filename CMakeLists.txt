cmake_minimum_required(VERSION 3.20)
project(Untitled_Game)

add_subdirectory(src/game)
add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} Game)
target_include_directories(${PROJECT_NAME} PUBLIC Game)