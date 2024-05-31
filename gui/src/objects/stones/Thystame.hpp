/*
** File description:
** Thystame
*/

#ifndef THYSTAME_HPP_
    #define THYSTAME_HPP_

    #include "../abstracts/AStone.hpp"

namespace GUI {
    class Thystame : public AStone {
    public:
        /**
         * @brief Construct a new Thystame object
         */
        Thystame();
        /**
         * @brief Destroy the Thystame object
         */
        virtual ~Thystame() noexcept = default;
    };
} // namespace GUI //
#endif /* !THYSTAME_HPP_ */
