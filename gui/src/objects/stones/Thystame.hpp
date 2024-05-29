/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Thystame
*/

#ifndef THYSTAME_HPP_
#define THYSTAME_HPP_

#include "../abstracts/AStone.hpp"

namespace GUI {
class Thystame : public AStone {
    public:
        Thystame();
        virtual ~Thystame() noexcept = default;
};
} // namespace GUI //
#endif /* !THYSTAME_HPP_ */
