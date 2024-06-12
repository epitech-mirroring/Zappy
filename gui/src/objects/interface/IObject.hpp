/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** IObject
*/

#ifndef IOBJECT_HPP_
    #define IOBJECT_HPP_

    #include "position/Position.hpp"
    #include <string>

namespace GUI {
    class IObject {
    public:
        /**
         * @brief Get the Density object
         * @return float
         */
        IObject() noexcept = default;
        /**
         * @brief Destroy the IObject object
         */
        virtual ~IObject() noexcept = default;

        /**
         * @brief Get the Density of the object
         * @return float (density of the object)
         */
        [[nodiscard]] virtual float getDensity() const noexcept = 0;

        /**
         * @brief Get the Position of the tile where the object is
         * @return const Position& tile where the object is (read-only)
         */
        [[nodiscard]] virtual const Position& getPosition() const noexcept = 0;

        /**
         * @brief Get the Position of the tile where the object is
         * @return Position& tile where the object is (modifiable)
         */
        [[nodiscard]] virtual Position& getPosition() noexcept = 0;

        /**
         * @brief Get the Type of the object
         * @return std::string type of the object
         */
        [[nodiscard]] virtual std::string getType() const noexcept = 0;
    };
}  // namespace GUI
#endif /* !IOBJECT_HPP_ */
