/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Phiras
*/

#ifndef PHIRAS_HPP_
    #define PHIRAS_HPP_

    #include "objects/abstracts/AStone.hpp"

namespace GUI {
    class Phiras : public AStone {
    public:
        /**
         * @brief Construct a new Phiras object
         * @param tile Tile where the object is
         */
        Phiras(Position tile = Position(0, 0));
        /**
         * @brief Destroy the Phiras object
         */
        virtual ~Phiras() noexcept = default;
    };
} // namespace GUI //
#endif /* !PHIRAS_HPP_ */
