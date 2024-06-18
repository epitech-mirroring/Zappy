target_sources(zappy_gui_lib
  PRIVATE
    # ARGS
    ${CMAKE_CURRENT_SOURCE_DIR}/handle_args/HandleArgs.cpp
    # EXCEPTIONS
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/abstract/AException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/ArgsException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/SocketException.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/ClientException.cpp
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
    ${CMAKE_CURRENT_SOURCE_DIR}/trantorians/Teams.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/trantorians/Actions.cpp
    # WORLD / MAP
    ${CMAKE_CURRENT_SOURCE_DIR}/world/World.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tiles/Tile.cpp
    # POSITION
    ${CMAKE_CURRENT_SOURCE_DIR}/position/Position.cpp
    # NETWORK
    ${CMAKE_CURRENT_SOURCE_DIR}/network/socket/TCPSocket.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/Client.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/protocol_handler/ProtocolHandler.cpp
    ## COMMANDS
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/factory/CommandFactory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/bct/CommandBCT.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/tna/CommandTNA.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/pnw/CommandPNW.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/ppo/CommandPPO.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/plv/CommandPLV.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/msz/CommandMSZ.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/pin/CommandPIN.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/pex/CommandPEX.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/pbc/CommandPBC.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/pfk/CommandPFK.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/pie/CommandPIE.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/pic/CommandPIC.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/sst/CommandSST.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/sgt/CommandSGT.cpp
    # GUI
    ${CMAKE_CURRENT_SOURCE_DIR}/game/Game.cpp

  PUBLIC
    # ARGS
    ${CMAKE_CURRENT_SOURCE_DIR}/handle_args/HandleArgs.hpp
    # EXCEPTIONS
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/abstract/AException.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/ArgsException.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/SocketException.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/exception/ClientException.hpp
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
    ${CMAKE_CURRENT_SOURCE_DIR}/trantorians/Teams.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/position/Position.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/trantorians/Actions.hpp
    # WORLD / MAP
    ${CMAKE_CURRENT_SOURCE_DIR}/world/World.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tiles/Tile.hpp
    # POSITION
    ${CMAKE_CURRENT_SOURCE_DIR}/position/Position.hpp
    # NETWORK
    ${CMAKE_CURRENT_SOURCE_DIR}/network/socket/ASocket.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/socket/TCPSocket.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/Client.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/protocol_handler/ProtocolHandler.hpp
    ## COMMANDS
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/factory/CommandFactory.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/bct/CommandBCT.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/tna/CommandTNA.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/pnw/CommandPNW.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/ppo/CommandPPO.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/plv/CommandPLV.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/msz/CommandMSZ.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/pin/CommandPIN.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/pex/CommandPEX.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/pbc/CommandPBC.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/pfk/CommandPFK.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/pie/CommandPIE.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/pic/CommandPIC.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/sst/CommandSST.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/network/commands/sgt/CommandSGT.hpp
    # GUI
    ${CMAKE_CURRENT_SOURCE_DIR}/game/Game.hpp
)
