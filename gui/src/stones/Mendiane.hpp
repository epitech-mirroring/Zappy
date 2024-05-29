/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Mendiane
*/

#ifndef MENDIANE_HPP_
#define MENDIANE_HPP_

#include "abstract/AStone.hpp"

namespace GUI {
class Mendiane : public GUI::AStone {
    public:
        Mendiane();
        ~Mendiane();

        float getDensity() const noexcept override;

    protected:
        float _density;
};
} // namespace GUI //
#endif /* !MENDIANE_HPP_ */
