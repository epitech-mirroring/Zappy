add_library(zappy_server_lib STATIC)

target_include_directories(zappy_server_lib PUBLIC include)
if (APPLE)
    target_include_directories(zappy_server_lib PRIVATE /usr/local/include)
    target_link_directories(zappy_server_lib PRIVATE /usr/local/lib)
else ()
    target_link_libraries(zappy_server_lib PRIVATE uuid)
endif ()
target_link_libraries(zappy_server_lib PRIVATE m)
add_subdirectory(src)
add_subdirectory(include)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wshadow")

if (TESTS)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -g")
    target_link_options(zappy_server_lib PUBLIC "--coverage")
endif ()

add_executable(zappy_server src/main.c)
target_link_libraries(zappy_server zappy_server_lib)
