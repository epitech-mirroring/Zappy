/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Food
*/

#ifndef FOOD_HPP_
#define FOOD_HPP_

namespace GUI {
class Food {
    public:
        Food(float density = 0.5);
        ~Food();

        float getDensity() const noexcept;
    protected:
        float _density;
};
} // namespace GUI //
#endif /* !FOOD_HPP_ */
