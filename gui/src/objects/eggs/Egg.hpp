/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** Egg
*/

#ifndef EGG_HPP_
#define EGG_HPP_


#include <iostream>
#include "../abstracts/AObject.hpp"

namespace GUI {
class Egg : public AObject {
    public:
        /**
         * @brief Construct a new Egg object
         * @param std::string teamName
         * @param int ownerID
        */
        Egg(std::string teamName, int ownerID = -1);
        /**
         * @brief Destroy the Egg object
        */
        ~Egg();

        /**
         * @brief Get the team name
         * @return std::string
        */
        std::string getTeam() const;

        /**
         * @brief Get the owner ID
         * @return int
        */
        int getOwnerID() const;

        /**
         * @brief Get the isEjected
         * @return bool
        */
        bool getIsEjected() const;

        /**
         * @brief Set the isEjected
         * @param bool isEjected
        */
        void setIsEjected(bool isEjected);

    protected:
        std::string _teamName;      // team name
        int _ownerID;           // ownerID (player whol laid it) -1 if no owner
        bool _isEjected;        // is egg ejected

};
} // namespace GUI //
#endif /* !EGG_HPP_ */
