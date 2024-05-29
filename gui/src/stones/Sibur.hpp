/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Sibur
*/

#ifndef SIBUR_HPP_
#define SIBUR_HPP_

#include "abstract/AStone.hpp"

namespace GUI {
class Sibur : public AStone {
    public:
        Sibur();

        float getDensity() const noexcept override;

    protected:
};
} // namespace GUI //
#endif /* !SIBUR_HPP_ */
