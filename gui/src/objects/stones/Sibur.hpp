/*
** File description:
** Sibur
*/

#ifndef SIBUR_HPP_
    #define SIBUR_HPP_

    #include "../abstracts/AStone.hpp"

namespace GUI {
    class Sibur : public AStone {
    public:
        /**
         * @brief Construct a new Sibur object
         */
        Sibur();
        /**
         * @brief Destroy the Sibur object
         */
        virtual ~Sibur() noexcept = default;
    };
} // namespace GUI //
#endif /* !SIBUR_HPP_ */
