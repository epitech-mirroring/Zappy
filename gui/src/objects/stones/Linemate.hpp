/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Linemate
*/

#ifndef LINEMATE_HPP_
    #define LINEMATE_HPP_

    #include "../abstracts/AStone.hpp"

namespace GUI {
    class Linemate : public AStone{
    public:
        /**
         * @brief Construct a new Linemate object
         * @param tile Tile where the object is
         */
        Linemate(Position tile = Position(0, 0));
        /**
         * @brief Destroy the Linemate object
         */
        virtual ~Linemate() noexcept = default;
    };
} // namespace GUI //
#endif /* !LINEMATE_HPP_ */
