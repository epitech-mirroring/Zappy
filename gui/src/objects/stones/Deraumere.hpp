/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Deraumere
*/

#ifndef DERAUMERE_HPP_
    #define DERAUMERE_HPP_

    #include "objects/abstracts/AStone.hpp"

namespace GUI {
    class Deraumere : public AStone {
    public:
        /**
         * @brief Construct a new Deraumere object
         * @param tile Tile where the object is
         */
        Deraumere(Position tile = Position(0, 0));
        /**
         * @brief Destroy the Deraumere object
         */
        virtual ~Deraumere() noexcept = default;
    };
} // namespace GUI //
#endif /* !DERAUMERE_HPP_ */
