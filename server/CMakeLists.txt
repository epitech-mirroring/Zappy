add_library(zappy_server_lib STATIC)

add_subdirectory(src)
add_subdirectory(include)

if (TESTS)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -g")
    target_link_libraries(zappy_server_lib gcov)
endif ()

add_executable(zappy_server src/main.c)
target_include_directories(zappy_server PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(zappy_server zappy_server_lib)
