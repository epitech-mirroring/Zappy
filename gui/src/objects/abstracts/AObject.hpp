/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** AObject
*/

#ifndef AOBJECT_HPP_
    #define AOBJECT_HPP_

    #include "objects/interface/IObject.hpp"
    #include <string>

namespace GUI {
    class AObject : public IObject {
    public:
        /**
         * @brief Construct a new AObject object
         * @param quantity
         * @param tile
         */
        AObject(unsigned int quantity, Position tile);
        /**
         * @brief Destroy the AObject object
         */
        virtual ~AObject() noexcept = default;

        /**
         * @brief Get the Quantity object
         * @return unsigned int (Quantity of the object)
         */
        [[nodiscard]] unsigned int getQuantity() const noexcept final;

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
         * @return unsigned int (type of the object (follow the protocol))
         */
        [[nodiscard]] unsigned int getType() noexcept;

        /**
         * @brief Set the Quantity of the object
         * @param quantity (Quantity of the object)
         */
        virtual void setQuantity(unsigned int quantity) noexcept final;

        /**
         * @brief get the name of the object
         */
        [[nodiscard]] virtual std::string getName() const noexcept = 0;

    protected:
        Position _position;      // tile where the object is (x, y)
        unsigned int _quantity;  // quantity of the object
    };
}  // namespace GUI //
#endif /* !AOBJECT_HPP_ */
