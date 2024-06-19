/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Egg
*/

#ifndef EGG_HPP_
    #define EGG_HPP_

    #include <iostream>
    #include "objects/abstracts/AObject.hpp"

namespace GUI {
    class Egg : public AObject {
    public:
        /**
         * @brief Construct a new Egg object
         * @param std::string teamName
         * @param int ownerID
         * @param Position Tile where the object is
        */
        Egg(std::string teamName, int ownerID = -1,
            Position tile = Position(0, 0));
        /**
         * @brief Destroy the Egg object
        */
        ~Egg();

        /**
         * @brief Get the team name
         * @return std::string (team name)
        */
        [[nodiscard]] std::string getTeam() const;

        /**
         * @brief Get the owner ID
         * @return int (owner of the egg ID)
        */
        [[nodiscard]] int getOwnerID() const;

        /**
         * @brief Get the isEjected
         * @return bool (true if the egg is ejected, false if not)
        */
        [[nodiscard]] bool getIsEjected() const;

        /**
         * @brief Set the isEjected
         * @param bool isEjected
         * @return void (nothing to return)
        */
        void setIsEjected(bool isEjected);

    protected:
        std::string _teamName;      // team name
        int _ownerID;               // ownerID (player who laid it) default -1
        bool _isEjected;            // is egg ejected
    };
} // namespace GUI //
#endif /* !EGG_HPP_ */
