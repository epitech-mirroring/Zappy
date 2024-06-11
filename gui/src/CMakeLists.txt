target_sources(zappy_gui_lib
  PRIVATE
    # ARGS
    ${CMAKE_CURRENT_SOURCE_DIR}/handle_args/HandleArgs.cpp
    # EXCEPTIONS
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/abstract/AException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/ArgsException.cpp
    # OBJECTS
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/abstracts/AObject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/abstracts/AStone.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/stones/Deraumere.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/stones/Linemate.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/stones/Mendiane.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/stones/Phiras.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/stones/Sibur.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/stones/Thystame.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/food/Food.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/eggs/Egg.cpp
    # TRANTORIAN
    ${CMAKE_CURRENT_SOURCE_DIR}/trantorians/Trantorian.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/trantorians/Tribes.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/trantorians/Actions.cpp
    # WORLD / MAP
    ${CMAKE_CURRENT_SOURCE_DIR}/world/World.cpp
    # POSITION
    ${CMAKE_CURRENT_SOURCE_DIR}/position/Position.cpp
    # DISPLAY
    ${CMAKE_CURRENT_SOURCE_DIR}/display/Window.cpp

  PUBLIC
    # ARGS
    ${CMAKE_CURRENT_SOURCE_DIR}/handle_args/HandleArgs.hpp
    # EXCEPTIONS
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/abstract/AException.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/ArgsException.hpp
    # OBJECTS
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/abstracts/AStone.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/abstracts/AStone.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/stones/Deraumere.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/stones/Linemate.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/stones/Mendiane.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/stones/Phiras.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/stones/Sibur.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/stones/Thystame.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/food/Food.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/objects/eggs/Egg.hpp
    #TRANTORIAN
    ${CMAKE_CURRENT_SOURCE_DIR}/trantorians/Trantorian.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/trantorians/Tribes.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/position/Position.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/trantorians/Actions.hpp
    # WORLD / MAP
    ${CMAKE_CURRENT_SOURCE_DIR}/world/World.hpp
    # POSITION
    ${CMAKE_CURRENT_SOURCE_DIR}/position/Position.hpp
    # DISPLAY
    ${CMAKE_CURRENT_SOURCE_DIR}/display/Window.hpp
)
