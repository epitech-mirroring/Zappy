target_sources(zappy_gui_lib
  PRIVATE
    # ARGS
    ${CMAKE_CURRENT_SOURCE_DIR}/handle_args/HandleArgs.cpp
    # EXCEPTIONS
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/abstract/AException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/ArgsException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/SocketException.cpp
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
    # WORLD / MAP
    ${CMAKE_CURRENT_SOURCE_DIR}/world/World.cpp
    # POSITION
    ${CMAKE_CURRENT_SOURCE_DIR}/position/Position.cpp
    # NETWORK
    ${CMAKE_CURRENT_SOURCE_DIR}/network/client/Client.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/protocol/ProtocolHandler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/socket/TCPSocket.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/command/factory/CommandFactory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/command/CommandMapSize.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/command/CommandMapSizeResponse.cpp
  PUBLIC
    # ARGS
    ${CMAKE_CURRENT_SOURCE_DIR}/handle_args/HandleArgs.hpp
    # EXCEPTIONS
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/abstract/AException.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/ArgsException.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/SocketException.hpp
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
    # WORLD / MAP
    ${CMAKE_CURRENT_SOURCE_DIR}/world/World.hpp
    # POSITION
    ${CMAKE_CURRENT_SOURCE_DIR}/position/Position.hpp
    # NETWORK
    ${CMAKE_CURRENT_SOURCE_DIR}/network/client/Client.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/protocol/ProtocolHandler.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/socket/TCPSocket.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/command/factory/CommandFactory.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/command/interface/ICommand.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/command/CommandMapSize.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/command/CommandMapSizeResponse.hpp

)
