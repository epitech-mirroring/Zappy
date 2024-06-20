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
    #include "position/Position.hpp"
    #include "raylib.h"

namespace GUI {
    class Egg : public AObject {
    public:
        /**
         * @brief Construct a new Egg object
         * @param string teamName
         * @param string ownerID
         * @param Position Tile where the object is
        */
        Egg(std::string teamName, std::string ownerID = "-1",
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
         * @return std::string (owner of the egg ID)
        */
        [[nodiscard]] std::string getOwnerID() const;

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

        /**
         * @brief Set egg position
         * @param int x position and y position
         * @return void (nothing to return)
        */
        void setPosition(int x, int y);

        /**
         * @brief Get egg position
         * @return Position
        */
        [[nodiscard]] Position& getPosition() noexcept;

        /**
         * @brief Get egg 3d model
         * @return Model type from raylib
        */
        [[nodiscard]] Model getModel();

    protected:
        std::string _teamName;      // team name
        std::string _ownerID;               // ownerID (player who laid it) default -1
        bool _isEjected;            // is egg ejected
        Position _position;         // position of the egg
        Model _eggModel;            // 3d model for the egg
        Texture _eggTexture;        // 3d texture for the egg
    };
} // namespace GUI //
#endif /* !EGG_HPP_ */
