/*
** File description:
** Mendiane
*/

#ifndef MENDIANE_HPP_
    #define MENDIANE_HPP_

    #include "../abstracts/AStone.hpp"

namespace GUI {
    class Mendiane : public AStone {
    public:
        /**
         * @brief Construct a new Mendiane object
         */
        Mendiane();
        virtual ~Mendiane() noexcept = default;
    };
} // namespace GUI //
#endif /* !MENDIANE_HPP_ */
