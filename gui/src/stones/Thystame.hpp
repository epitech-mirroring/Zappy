/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Thystame
*/

#ifndef THYSTAME_HPP_
#define THYSTAME_HPP_

#include "abstract/AStone.hpp"

namespace GUI {
class Thystame : public AStone {
    public:
        Thystame();

        float getDensity() const noexcept override;

    protected:
};
} // namespace GUI //
#endif /* !THYSTAME_HPP_ */
