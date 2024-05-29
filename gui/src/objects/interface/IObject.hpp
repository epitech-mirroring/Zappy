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
        IObject() noexcept = default;
        virtual ~IObject() noexcept = default;

        virtual float getDensity() const noexcept = 0;
};
}  // namespace GUI
#endif /* !IOBJECT_HPP_ */
