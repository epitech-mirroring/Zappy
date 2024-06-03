/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AObject
*/

#ifndef AOBJECT_HPP_
    #define AOBJECT_HPP_

    #include "../interface/IObject.hpp"

namespace GUI {
    class AObject : public IObject {
    public:
        /**
         * @brief Construct a new AObject object
         * @param density
         */
        AObject(float density);
        /**
         * @brief Destroy the AObject object
         */
        virtual ~AObject() noexcept = default;

        /**
         * @brief Get the Density object
         * @return float (density of the object)
         */
        [[nodiscard]] float getDensity() const noexcept final;

        /**
         * @brief Get the Position of the tile where the object is
         * @return std::pair<unsigned int (x), unsigned int (y)> tile where the object is
        */
        [[nodiscard]] std::pair<unsigned int, unsigned int> getPosition() const noexcept final;

    protected:
        float _density;         // density of the object
        std::pair<unsigned int, unsigned int> _position; // tile where the object is (x, y)
    };
}  // namespace GUI //
#endif /* !AOBJECT_HPP_ */
