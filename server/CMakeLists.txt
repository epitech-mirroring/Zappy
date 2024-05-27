cmake_minimum_required(VERSION 3.21)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(zappy_server
        LANGUAGES C CXX
        VERSION 0.1.0
        DESCRIPTION "Server for the Zappy project"
        HOMEPAGE_URL "https://github.com/epitech-mirroring/zappy"
)

add_compile_options(-Wall -Wextra -Wpedantic)

add_library(${PROJECT_NAME}_sources OBJECT)

add_subdirectory(src)
add_subdirectory(include)
target_include_directories(${PROJECT_NAME}_sources PUBLIC include)

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_sources)

# Tests
include(GoogleTest)
enable_testing()
add_executable(${PROJECT_NAME}_tests tests/main.cpp)

add_subdirectory(tests)

gtest_discover_tests(${PROJECT_NAME}_tests)
target_include_directories(${PROJECT_NAME}_tests PRIVATE /usr/local/include)
target_link_directories(${PROJECT_NAME}_tests PRIVATE /usr/local/lib)
target_link_libraries(${PROJECT_NAME}_tests PRIVATE ${PROJECT_NAME}_sources gtest_main gtest)
