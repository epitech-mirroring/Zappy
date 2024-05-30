/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Phiras
*/

#ifndef PHIRAS_HPP_
#define PHIRAS_HPP_

#include "../abstracts/AStone.hpp"

namespace GUI {
class Phiras : public AStone {
    public:
        /**
         * @brief Construct a new Phiras object
         */
        Phiras();
        /**
         * @brief Destroy the Phiras object
         */
        virtual ~Phiras() noexcept = default;
};
} // namespace GUI //
#endif /* !PHIRAS_HPP_ */
