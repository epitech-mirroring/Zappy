add_library(zappy_gui_lib STATIC)

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

target_include_directories(zappy_gui_lib PUBLIC src)
target_include_directories(zappy_gui_lib PUBLIC ${raylib_SOURCE_DIR}/src)
add_subdirectory(src)

if (TESTS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -g")
    target_link_options(zappy_gui_lib PUBLIC "--coverage")
endif ()

add_executable(zappy_gui src/main.cpp)
target_link_libraries(zappy_gui zappy_gui_lib raylib)


if (APPLE)
    target_link_libraries(zappy_gui "-framework IOKit")
    target_link_libraries(zappy_gui "-framework Cocoa")
    target_link_libraries(zappy_gui "-framework OpenGL")
endif()
