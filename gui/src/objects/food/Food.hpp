/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Food
*/

#ifndef FOOD_HPP_
#define FOOD_HPP_

#include "../abstracts/AObject.hpp"

namespace GUI {
class Food : public AObject {
    public:
        /**
         * @brief Construct a new Food object
        */
        Food();
        /**
         * @brief Destroy the Food object
        */
        virtual ~Food() noexcept = default;
};
} // namespace GUI //
#endif /* !FOOD_HPP_ */
