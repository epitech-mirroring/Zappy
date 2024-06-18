cmake_minimum_required(VERSION 3.21)

# Tests
include(GoogleTest)
enable_testing()
add_executable(zappy_tests main.cpp)

add_subdirectory(server)
add_subdirectory(gui)

find_package(raylib 3.0 REQUIRED)

gtest_discover_tests(zappy_tests)
target_include_directories(zappy_tests PRIVATE /usr/local/include)
target_link_directories(zappy_tests PRIVATE /usr/local/lib)
target_link_libraries(zappy_tests PRIVATE zappy_server_lib zappy_gui_lib gtest_main gtest raylib)
target_include_directories(zappy_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/include)
