/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** IObject
*/

#ifndef IOBJECT_HPP_
#define IOBJECT_HPP_

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
         * @return float
         */
        virtual float getDensity() const noexcept = 0;
};
}  // namespace GUI
#endif /* !IOBJECT_HPP_ */
