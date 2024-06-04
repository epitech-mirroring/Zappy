/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** World
*/

#ifndef WORLD_HPP_
    #define WORLD_HPP_

    #include <list>
    #include "objects/interface/IObject.hpp"

namespace GUI {
    class World {
    public:
        /**
         * @brief Construct a new World object
         * @param width (width of the world x)
         * @param height (height of the world y)
        */
        World(unsigned int width, unsigned int height);
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
         * @brief Add an object to the world
         * @param object (object to add)
        */
        void addObject(IObject *object);
        /**
         * @brief Remove an object from the world
         * @param object (object to remove)
        */
        void removeObject(IObject *object);

        /**
         * @brief Get the list of objects in the world
         * @return std::list<IObject *> (list of objects)
        */
        [[nodiscard]] std::list<IObject *> getObjects() const;
        /**
         * @brief Get the list of objects at a specific tile
         * @param tile (Position object that contains uint X and unint Y as protected)
        */
        [[nodiscard]] std::list <IObject *> getObjectsAt(Position tile) const;

    protected:
        unsigned int _width;         // width of the world
        unsigned int _height;        // height of the world

        std::list<IObject *> _objects;  // list of objects in the world
    };
} // namespace GUI //
#endif /* !WORLD_HPP_ */
