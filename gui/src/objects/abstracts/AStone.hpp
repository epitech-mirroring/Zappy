/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** AStone
*/

#ifndef ASTONE_HPP_
#define ASTONE_HPP_

#include "AObject.hpp"

namespace GUI {
class AStone : public AObject {
    public:
        /**
         * @brief Construct a new AStone object
         * @param density
         */
        AStone(float density);
        /**
         * @brief Destroy the AStone object
         */
        virtual ~AStone() noexcept = default;
};
} // namespace GUI
#endif /* !ASTONE_HPP_ */
