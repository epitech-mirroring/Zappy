/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** AObject
*/

#ifndef AOBJECT_HPP_
#define AOBJECT_HPP_

#include "../interface/IObject.hpp"

namespace GUI {
class AObject : public IObject {
    public:
        AObject(float density);
        virtual ~AObject() noexcept = default;

        float getDensity() const noexcept override final;
    protected:
        float _density;
};
}  // namespace GUI //
#endif /* !AOBJECT_HPP_ */
