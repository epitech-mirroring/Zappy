target_sources(zappy_gui_lib
  PRIVATE
    # ARGS
    ${CMAKE_CURRENT_SOURCE_DIR}/handle_args/HandleArgs.cpp
    # EXCEPTIONS
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/abstract/AException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/ArgsException.cpp
    # STONES
    ${CMAKE_CURRENT_SOURCE_DIR}/stones/abstract/AStone.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stones/Deraumere.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stones/Linemate.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stones/Mendiane.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stones/Phiras.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stones/Sibur.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stones/Thystame.cpp
    # FOOD
    ${CMAKE_CURRENT_SOURCE_DIR}/food/Food.cpp
  PUBLIC
    # ARGS
    ${CMAKE_CURRENT_SOURCE_DIR}/handle_args/HandleArgs.hpp
    # EXCEPTIONS
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/abstract/AException.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/ArgsException.hpp
    # STONES
    ${CMAKE_CURRENT_SOURCE_DIR}/stones/abstract/AStone.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stones/Deraumere.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stones/Linemate.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stones/Mendiane.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stones/Phiras.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stones/Sibur.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stones/Thystame.hpp
    # FOOD
    ${CMAKE_CURRENT_SOURCE_DIR}/food/Food.hpp
)
