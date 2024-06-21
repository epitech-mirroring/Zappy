cmake_minimum_required(VERSION 3.20)

# Tests
include(GoogleTest)
enable_testing()
add_executable(zappy_tests main.cpp)

add_subdirectory(server)
add_subdirectory(gui)

set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET)
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

gtest_discover_tests(zappy_tests)
target_include_directories(zappy_tests PRIVATE /usr/local/include)
target_link_directories(zappy_tests PRIVATE /usr/local/lib)
target_link_libraries(zappy_tests PRIVATE zappy_server_lib zappy_gui_lib gtest_main gtest raylib)
target_include_directories(zappy_tests PRIVATE ${CMAKE_SOURCE_DIR}/server/include)
