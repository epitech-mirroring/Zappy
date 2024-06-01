/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** World
*/

#ifndef WORLD_HPP_
#define WORLD_HPP_

namespace GUI {
class World {
    public:
        World(unsigned int width, unsigned int height);
        ~World();

        void setWidth(unsigned int width);
        void setHeight(unsigned int height);

        unsigned int getWidth() const;
        unsigned int getHeight() const;

    protected:
        unsigned int _width;
        unsigned int _height;
};
} // namespace GUI //
#endif /* !WORLD_HPP_ */
