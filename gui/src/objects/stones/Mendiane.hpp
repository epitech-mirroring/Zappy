/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Mendiane
*/

#ifndef MENDIANE_HPP_
    #define MENDIANE_HPP_

    #include "objects/abstracts/AStone.hpp"

namespace GUI {
    class Mendiane : public AStone {
    public:
        /**
         * @brief Construct a new Mendiane object
         * @param tile Tile where the object is
         */
        Mendiane(Position tile = Position(0, 0));
        virtual ~Mendiane() noexcept = default;

        /**
         * @brief Get the Type of the object
         * @return std::string type of the object
         */
        [[nodiscard]] std::string getType() const noexcept final;
    };
} // namespace GUI //
#endif /* !MENDIANE_HPP_ */
