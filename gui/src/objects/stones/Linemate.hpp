/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Linemate
*/

#ifndef LINEMATE_HPP_
#define LINEMATE_HPP_

#include "../abstracts/AStone.hpp"

namespace GUI {
class Linemate :public GUI::AStone{
    public:
        Linemate();
        virtual ~Linemate() noexcept = default;
};
} // namespace GUI //
#endif /* !LINEMATE_HPP_ */
