/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** World
*/

#ifndef WORLD_HPP_
    #define WORLD_HPP_

    #include <vector>
    #include "tiles/Tile.hpp"

namespace GUI {
    class World {
    public:
        /**
         * @brief Construct a new World object
         * @param width (width of the world x)
         * @param height (height of the world y)
        */
        World(unsigned int width = 0, unsigned int height = 0);

        /**
         * @brief Destroy the World object
        */
        ~World() = default;

        /**
         * @brief Set the Width of the world
         * @param width (width of the world x)
        */
        void setWidth(unsigned int width);

        /**
         * @brief Set the Height of the world
         * @param height (height of the world y)
        */
        void setHeight(unsigned int height);

        /**
         * @brief Get the Width of the world
         * @return unsigned int (width of the world x)
        */
        [[nodiscard]] unsigned int getWidth() const;

        /**
         * @brief Get the Height of the world
         * @return unsigned int (height of the world y)
        */
        [[nodiscard]] unsigned int getHeight() const;

        /**
         * @brief Add an object to the world at a specific position
         * @param object (object to add)
         * @param pos (position to add the object)
        */
        void addObject(IObject *object, Position pos);

        /**
         * @brief Remove an object from the world
         * @param object (object to remove)
         */
        void removeObject(IObject *object, Position pos);

        /**
         * @brief Get the list of objects in the world
         * @return std::list<IObject *> (list of objects)
         */
        [[nodiscard]] std::list<IObject *> getObjects() const;

        /**
         * @brief Get the list of objects at a specific tile
         * @param tile (Position object that contains uint X and uint Y as protected)
         */
        [[nodiscard]] std::list<IObject *> getObjectsAt(Position tile) const;

        /**
         * @brief Set the size of the world and initialize tiles
         * @param width (width of the world x)
         * @param height (height of the world y)
         */
        void setWorldSize(unsigned int width, unsigned int height);

        /**
         * @brief Get the tiles of the world
         * @return const std::vector<std::vector<Tile>>& (2D vector of tiles)
         */
        [[nodiscard]] std::vector<std::vector<Tile>>& getTiles();

        /**
         * @brief Get the tile at the specified position
         * @param x (x coordinate)
         * @param y (y coordinate)
         * @return Tile& (reference to the tile)
         */
        [[nodiscard]] Tile& getTileAt(unsigned int x, unsigned int y);

        /**
         * @brief Add a tile to the world
         * @param tile (tile to add)
         */
        void addTile(Tile tile);

    protected:
        unsigned int _width;  // width of the world
        unsigned int _height; // height of the world
        std::vector<std::vector<Tile>> _tiles;  // 2D vector of tiles
    };
} // namespace GUI
#endif /* !WORLD_HPP_ */
