/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Linemate
*/

#ifndef LINEMATE_HPP_
    #define LINEMATE_HPP_

    #include "objects/abstracts/AStone.hpp"

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
#endif /* !LINEMATE_HPP_ */
