/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Food
*/

#ifndef FOOD_HPP_
    #define FOOD_HPP_

    #include "objects/abstracts/AObject.hpp"

namespace GUI {
    class Food : public AObject {
    public:
        /**
         * @brief Construct a new Food object
         * @param tile Tile where the object is
        */
        Food(Position tile = Position(0, 0));
        /**
         * @brief Destroy the Food object
        */
        virtual ~Food() noexcept = default;

        /**
         * @brief Get the Type of the object
         * @return std::string type of the object
        */
        [[nodiscard]] std::string getType() const noexcept final;
    };
} // namespace GUI //
#endif /* !FOOD_HPP_ */
