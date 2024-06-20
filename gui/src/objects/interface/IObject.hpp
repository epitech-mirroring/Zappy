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
         * @brief Construct a new IObject object
         */
        IObject() noexcept = default;
        /**
         * @brief Destroy the IObject object
         */
        virtual ~IObject() noexcept = default;

        /**
         * @brief Get the Quantity of the object
         * @return unsinged int (Quantity of the object)
         */
        [[nodiscard]] virtual unsigned int getQuantity() const noexcept = 0;

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
         * @return unsigned int (type of the object (follow the protocol))
         */
        [[nodiscard]] virtual unsigned int getType() noexcept = 0;

        /**
         * @brief Set the Quantity of the object
         * @param quantity (Quantity of the object)
         */
        virtual void setQuantity(unsigned int quantity) noexcept = 0;

        /**
         * @brief get the name of the object
         */
        [[nodiscard]] virtual std::string getName() const noexcept = 0;
    };
}  // namespace GUI
#endif /* !IOBJECT_HPP_ */
