/*
** File description:
** Tribes
*/

#ifndef TRIBES_
    #define TRIBES_

    #include <iostream>
    #include <list>
    #include "Trantorian.hpp"

namespace GUI
{
    class Tribes
    {
        public:
            /**
             * @brief Create Tribe object
             */
            Tribes();
            /**
             * @brief Create Tribe object
             */
            ~Tribes();

            /**
             * @brief Set name of the tribe
             * @param name std::string of tribe's name
             */
            void setName(std::string name);
            /**
             * @brief Get tribe's name
             * @return std::string of tribe's name
             */
            [[nodiscard]] std::string getName();

            /**
             * @brief Add new trantorian to tribe
             * @param Trantorian object
             */
            void addTrantorian(GUI::Trantorian trantorian);
            /**
             * @brief Get list of trantorian in the tribe
             * @return list of trantorian objects
             */
            [[nodiscard]] std::list<GUI::Trantorian> getTrantorianList();

        private:
            std::string _name;
            std::list<GUI::Trantorian> _trantorians;
    };
} // namespace GUI

#endif // TRIBES_
