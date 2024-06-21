/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Thystame
*/

#ifndef THYSTAME_HPP_
    #define THYSTAME_HPP_

    #include "objects/abstracts/AStone.hpp"

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

        /**
         * @brief Get the Type of the object
         * @return unsigned int (type of the object (follow the protocol))
         */
        [[nodiscard]] unsigned int getType() noexcept final;

        /**
         * @brief Get the name of the object
         */
        [[nodiscard]] std::string getName() const noexcept final;
    };
} // namespace GUI //
#endif /* !THYSTAME_HPP_ */
