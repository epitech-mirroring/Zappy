/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Deraumere
*/

#ifndef DERAUMERE_HPP_
#define DERAUMERE_HPP_

#include "abstract/AStone.hpp"

namespace GUI {
class Deraumere : public GUI::AStone {
    public:
        Deraumere();

        float getDensity() const noexcept override;

    protected:
        float _density;
};
} // namespace GUI //
#endif /* !DERAUMERE_HPP_ */
