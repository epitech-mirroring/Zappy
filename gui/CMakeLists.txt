cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(zappy_gui
        LANGUAGES CXX
        VERSION 0.1.0
        DESCRIPTION "GUI for the Zappy project"
        HOMEPAGE_URL "https://github.com/epitech-mirroring/zappy"
)

add_compile_options(-Wall -Wextra -Wpedantic)

add_library(${PROJECT_NAME}_sources)

add_subdirectory(src)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_sources)
