/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Thystame
*/

#ifndef THYSTAME_HPP_
    #define THYSTAME_HPP_

    #include "../abstracts/AStone.hpp"

namespace GUI {
    class Thystame : public AStone {
    public:
        /**
         * @brief Construct a new Thystame object
         * @param tile Tile where the object is
         */
        Thystame(Position tile = Position(0, 0));
        /**
         * @brief Destroy the Thystame object
         */
        virtual ~Thystame() noexcept = default;
    };
} // namespace GUI //
#endif /* !THYSTAME_HPP_ */
