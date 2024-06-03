/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** IObject
*/

#ifndef IOBJECT_HPP_
    #define IOBJECT_HPP_

    #include <utility>

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
         * @brief Get the Position of the object
         * @return std::pair<unsigned int (x), unsigned int (y)> tile where the object is
         */
        [[nodiscard]] virtual std::pair<unsigned int, unsigned int> getPosition() const noexcept = 0;
    };
}  // namespace GUI
#endif /* !IOBJECT_HPP_ */
