/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Tile
*/

#ifndef TILE_HPP_
    #define TILE_HPP_

    #include <list>
    #include <string>
    #include <sstream>
    #include <vector>
    #include <iostream>
    #include <algorithm>
    #include <unordered_map>
    #include "position/Position.hpp"
    #include "objects/interface/IObject.hpp"
    #include "objects/food/Food.hpp"
    #include "objects/stones/Linemate.hpp"
    #include "objects/stones/Deraumere.hpp"
    #include "objects/stones/Sibur.hpp"
    #include "objects/stones/Mendiane.hpp"
    #include "objects/stones/Phiras.hpp"
    #include "objects/stones/Thystame.hpp"

namespace GUI {
    class Tile {
    public:
        enum ResourceType {
            FOOD,
            LINEMATE,
            DERAUMERE,
            SIBUR,
            MENDIANE,
            PHIRAS,
            THYSTAME,
            RESOURCE_COUNT
        };
        /**
         * @brief Construct a new Tile object
         * @param pos (position of the tile)
         */
        Tile(Position pos);
        /**
         * @brief Destroy the Tile object
         */
        ~Tile() = default;
        /**
         * @brief Get the Position of the tile
         * @return Position (position of the tile)
         */
        [[nodiscard]] Position getPosition() const;

        /**
         * @brief Add an object to the tile
         * @param object (object to add)
         */
        void addObject(IObject *object);

        /**
         * @brief Remove an object from the tile
         * @param object (object to remove)
         */
        void removeObject(IObject *object);

        /**
         * @brief Get the list of objects on the tile
         * @return std::list<IObject *> (list of objects)
         */
        [[nodiscard]] std::list<IObject *> getObjects() const;

        /**
         * @brief Clear all objects on the tile
         */
        void clearObjects();

        void updateTileContent(std::vector<std::string> tileContent);
        IObject* createObjectByType(ResourceType type, Position pos);

    protected:
        std::list<IObject *> _objects;  // list of objects on the tile
        Position _pos;                  // position of the tile
    };
} // namespace GUI
#endif // TILE_HPP_
