/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Tile
*/

#ifndef TILE_HPP_
    #define TILE_HPP_

    #include <list>
    #include "objects/interface/IObject.hpp"
    #include "position/Position.hpp"

namespace GUI {
    class Tile {
    public:
        Tile(Position pos);
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

    protected:
        std::list<IObject *> _objects;  // list of objects on the tile
        Position _pos;                  // position of the tile
    };
} // namespace GUI
#endif // TILE_HPP_
