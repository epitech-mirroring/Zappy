add_library(zappy_gui_lib STATIC)

target_include_directories(zappy_gui_lib PUBLIC src)
add_subdirectory(src)

if (TESTS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -g")
    target_link_options(zappy_gui_lib PUBLIC "--coverage")
endif ()

add_executable(zappy_gui src/main.cpp)
target_link_libraries(zappy_gui zappy_gui_lib)
