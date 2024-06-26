/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Sibur
*/

#ifndef SIBUR_HPP_
    #define SIBUR_HPP_

    #include "objects/abstracts/AStone.hpp"

namespace GUI {
    class Sibur : public AStone {
    public:
        /**
         * @brief Construct a new Sibur object
         * @param tile Tile where the object is
         */
        Sibur(Position tile = Position(0, 0));
        /**
         * @brief Destroy the Sibur object
         */
        virtual ~Sibur() noexcept = default;

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
#endif /* !SIBUR_HPP_ */
