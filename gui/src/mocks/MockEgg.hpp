/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** MockEgg
*/

#ifndef MockEgg_HPP_
    #define MockEgg_HPP_

    #include <iostream>
    #include "objects/abstracts/AObject.hpp"
    #include "position/Position.hpp"

namespace GUI {
    class MockEgg : public AObject {
    public:
        /**
         * @brief Construct a new MockEgg object
         * @param string teamName
         * @param string ownerID
         * @param Position Tile where the object is
        */
        MockEgg(std::string teamName, std::string ownerID = "-1",
            Position tile = Position(0, 0));
        /**
         * @brief Destroy the MockEgg object
        */
        ~MockEgg();

        /**
         * @brief Get the team name
         * @return std::string (team name)
        */
        [[nodiscard]] std::string getTeam() const;

        /**
         * @brief Get the owner ID
         * @return std::string (owner of the MockEgg ID)
        */
        [[nodiscard]] std::string getOwnerID() const;

        /**
         * @brief Get the isEjected
         * @return bool (true if the MockEgg is ejected, false if not)
        */
        [[nodiscard]] bool getIsEjected() const;

        /**
         * @brief Set the isEjected
         * @param bool isEjected
         * @return void (nothing to return)
        */
        void setIsEjected(bool isEjected);

        /**
         * @brief Set MockEgg position
         * @param int x position and y position
         * @return void (nothing to return)
        */
        void setPosition(int x, int y);

        /**
         * @brief Get MockEgg position
         * @return Position
        */
        [[nodiscard]] Position& getPosition() noexcept;

    protected:
        std::string _teamName;      // team name
        std::string _ownerID;               // ownerID (player who laid it) default -1
        bool _isEjected;            // is MockEgg ejected
        Position _position;         // position of the MockEgg
    };
} // namespace GUI //
#endif /* !MockEgg_HPP_ */
