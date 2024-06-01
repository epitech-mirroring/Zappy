/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Deraumere
*/

#ifndef DERAUMERE_HPP_
    #define DERAUMERE_HPP_

    #include "../abstracts/AStone.hpp"

namespace GUI {
    class Deraumere : public AStone {
    public:
        /**
         * @brief Construct a new Deraumere object
         */
        Deraumere();
        /**
         * @brief Destroy the Deraumere object
         */
        virtual ~Deraumere() noexcept = default;
    };
} // namespace GUI //
#endif /* !DERAUMERE_HPP_ */
