/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Phiras
*/

#ifndef PHIRAS_HPP_
#define PHIRAS_HPP_

#include "abstract/AStone.hpp"

namespace GUI {
class Phiras : public GUI::AStone {
    public:
        Phiras();

        float getDensity() const noexcept override;

    protected:
        float _density;
};
} // namespace GUI //
#endif /* !PHIRAS_HPP_ */
