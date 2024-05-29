/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** AStone
*/

#ifndef ASTONE_HPP_
#define ASTONE_HPP_

namespace GUI {
class AStone {
    public:
        AStone(float density);
        virtual ~AStone() = default;

        virtual float getDensity() const noexcept = 0;

    protected:
        float _density;
};
} // namespace GUI
#endif /* !ASTONE_HPP_ */
