/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Linemate
*/

#ifndef LINEMATE_HPP_
#define LINEMATE_HPP_

#include "abstract/AStone.hpp"

namespace GUI {
class Linemate :public GUI::AStone{
    public:
        Linemate();

        float getDensity() const noexcept override;

    protected:
};
} // namespace GUI //
#endif /* !LINEMATE_HPP_ */
