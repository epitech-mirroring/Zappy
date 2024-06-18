cmake_minimum_required(VERSION 3.20)

project(Zappy
    VERSION 0.1.0
    DESCRIPTION "Zappy project"
    LANGUAGES CXX C
    HOMEPAGE_URL "https://github.com/epitech-mirroring/zappy"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

option(SERVER "Build the server" ON)
option(TESTS "Build the tests" ON)
option(GUI "Build the GUI" ON)

if (SERVER)
    add_subdirectory(server)
endif()

if (GUI)
    add_subdirectory(gui)
endif ()

if (TESTS)
    add_subdirectory(tests)
endif ()
