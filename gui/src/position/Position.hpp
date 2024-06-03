/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Position
*/

#ifndef POSITION_HPP_
    #define POSITION_HPP_

namespace GUI {
    class Position {
    public:
        /**
         * @brief Construct a new Position object
         * @param x (x position) default is 0
         * @param y (y position) default is 0
        */
        Position(unsigned int x = 0, unsigned int y = 0);
        ~Position();

        /**
         * @brief Get the X position
         * @return unsigned int (x position)
        */
        [[nodiscard]] unsigned int getX() const noexcept;
        /**
         * @brief Get the Y position
         * @return unsigned int (y position)
        */
        [[nodiscard]] unsigned int getY() const noexcept;

        /**
         * @brief Set the X position
         * @param x (x position)
        */
        void setX(unsigned int x) noexcept;
        /**
         * @brief Set the Y position
         * @param y (y position)
        */
        void setY(unsigned int y) noexcept;

    protected:
        unsigned int _x;    //position x
        unsigned int _y;    //position y
    private:
    };
} // namespace GUI //
#endif /* !POSITION_HPP_ */
