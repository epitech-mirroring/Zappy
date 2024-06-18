/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** MockTrantorians
*/

#ifndef MOCKTRANTORIAN_
    #define MOCKTRANTORIAN_

    #include <iostream>
    #include <utility>
    #include <vector>
    #include <list>
    #include <raylib.h>
    #include "position/Position.hpp"
    #include "objects/interface/IObject.hpp"
    #include "objects/interface/IObject.hpp"
    #include "objects/food/Food.hpp"
    #include "objects/stones/Linemate.hpp"
    #include "objects/stones/Deraumere.hpp"
    #include "objects/stones/Sibur.hpp"
    #include "objects/stones/Mendiane.hpp"
    #include "objects/stones/Phiras.hpp"
    #include "objects/stones/Thystame.hpp"

namespace GUI {
    class MockTeams; // Forward declaration

    class MockTrantorians {
        public:
          enum ResourceType {
                FOOD,
                LINEMATE,
                DERAUMERE,
                SIBUR,
                MENDIANE,
                PHIRAS,
                THYSTAME,
                RESOURCE_COUNT
            };
            enum Orientation {
                NORTH = 1,
                EAST = 2,
                SOUTH = 3,
                WEST = 4
            };
            /**
             * @brief Create MockTrantorians object
             */
            MockTrantorians(std::string id = "null", int x = 0, int y = 0, float orientation = NORTH,
                int level = 1, std::string teamName = "");
            /**
             * @brief Destroy MockTrantorians object
             */
            ~MockTrantorians() = default;

            /**
             * @brief Set MockTrantorians position
             * @param postion (int x, int y)
             */
            void setPosition(int x, int y);
            /**
             * @brief Get MockTrantorians postion
             * @return pair of ints
             */
            [[nodiscard]] GUI::Position getPosition();

            /**
             * @brief Set MockTrantorians team
             * @param team
             */
            void setTeam(MockTeams* team);
            /**
             * @brief Get MockTrantorians team
             * @return MockTeams* pointer to team
             */
            [[nodiscard]] MockTeams* getTeam();

            /**
             * @brief Set MockTrantorians's lifetime
             * @param lifetime
             */
            void setLifetime(int lifetime);
            /**
             * @brief Get MockTrantorians lifetime
             * @return int representing life time remaining
             */
            [[nodiscard]] int getLifetime();

            /**
             * @brief Set MockTrantorians alive
             * @param bool
             */
            void setIsAlive(bool isAlive);
            /**
             * @brief Get MockTrantorians alive
             * @return false if dead, true if alive
             */
            [[nodiscard]] bool getIsAlive();

            /**
             * @brief Set MockTrantorians action
             * @param bool
             */
            void setAction(bool Action);
            /**
             * @brief Get MockTrantorians action
             * @return true if doing an action, false if not
             */
            [[nodiscard]] bool getAction();

            /**
             * @brief Set MockTrantorians id
             * @param std::string
             */
            void setId(std::string id);
            /**
             * @brief Get MockTrantorians id
             * @return int representing player's id
             */
            [[nodiscard]] std::string getId();

            /**
             * @brief Set MockTrantorians level
             * @param level
             */
            void setLevel(int level);
            /**
             * @brief Get MockTrantorians level
             * @return int representing player's level
             */
            [[nodiscard]] int getLevel();

            /**
             * @brief Compare two MockTrantorianss
             * @param other
             * @return true if equal, false if not
             */
            [[nodiscard]]
            bool operator==(const MockTrantorians& other) const;

            /**
             * @brief Set MockTrantorians orientation
             * @param orientation
             */
            void setOrientation(float orientation);

            /**
             * @brief Get MockTrantorians orientation
             */
            [[nodiscard]] float getOrientation();

            /**
            * @brief Get the object by type
            * @param type (type of the object)
            * @param pos (Position of the TILE where the object is supposed to be created)
            * @return IObject* (object)
            */
            IObject* createObjectByType(ResourceType type, Position pos);

            /**
             * @brief Set the MockTrantorians's inventory
             * @param inventory (vector of strings)
             * @return void
             */
            void setInventory(std::vector<std::string> inventory);

            /**
             * @brief Clear the MockTrantorians's inventory
             * @return void
             */
            void clearInventory();
            /**
             * @brief Add an object to the tile
             * @param object (object to add)
             */
            void addObject(IObject *object);
            /**
             * @brief Remove an object from the tile
             * @param object (object to remove)
             */
            void removeObject(IObject *object);
            /**
             * @brief Get the inventory of the player
             * @return list of IObject*
             */
            [[nodiscard]] std::list<IObject *> getInventory() const;

        private:
            GUI::Position _position;
            MockTeams* _team;
            int _lifetimeRemaining;
            bool _alive;
            bool _action;
            std::string _id;
            int _level;
            float _orientation;
            std::list<IObject *> _inventory;
    };
} // namespace GUI  //
#endif // MockTrantorians_
