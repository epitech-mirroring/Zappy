cmake_minimum_required(VERSION 3.21)

project(Zappy)

option(SERVER "Build the server" ON)
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