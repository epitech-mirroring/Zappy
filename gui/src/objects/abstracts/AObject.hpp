/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AObject
*/

#ifndef AOBJECT_HPP_
    #define AOBJECT_HPP_

    #include "objects/interface/IObject.hpp"

namespace GUI {
    class AObject : public IObject {
    public:
        /**
         * @brief Construct a new AObject object
         * @param density
         * @param tile
         */
        AObject(float density, Position tile);
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
         * @return const Position& tile where the object is (read-only)
         */
        [[nodiscard]] const Position& getPosition() const noexcept final;

        /**
         * @brief Get the Position of the tile where the object is
         * @return Position& tile where the object is (modifiable)
         */
        [[nodiscard]] Position& getPosition() noexcept;

        /**
         * @brief Get the Type of the object
         * @return std::string type of the object
         */
        [[nodiscard]] virtual std::string getType() const noexcept = 0;

    protected:
        float _density;         // density of the object
        Position _position;     // tile where the object is (x, y)
    };
}  // namespace GUI //
#endif /* !AOBJECT_HPP_ */
