/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Trantorian
*/

#ifndef TRANTORIAN_
    #define TRANTORIAN_

    #include <iostream>
    #include <utility>
    #include <vector>
    #include <list>
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
    class Teams; // Forward declaration

    class Trantorian {
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
            /**
             * @brief Create trantorian object
             */
            Trantorian(std::string id = "null", int x = 0, int y = 0, int oritentation = 1,
                int level = 1, std::string teamName = "");
            /**
             * @brief Destroy trantorian object
             */
            ~Trantorian() = default;

            /**
             * @brief Set trantorian position
             * @param postion (int x, int y)
             */
            void setPosition(int x, int y);
            /**
             * @brief Get trantorian postion
             * @return pair of ints
             */
            [[nodiscard]] GUI::Position getPosition();

            /**
             * @brief Set trantorian team
             * @param team
             */
            void setTeam(Teams* team);
            /**
             * @brief Get trantorian team
             * @return Teams* pointer to team
             */
            [[nodiscard]] Teams* getTeam();

            /**
             * @brief Set trantorian's lifetime
             * @param lifetime
             */
            void setLifetime(int lifetime);
            /**
             * @brief Get trantorian lifetime
             * @return int representing life time remaining
             */
            [[nodiscard]] int getLifetime();

            /**
             * @brief Set trantorian alive
             * @param bool
             */
            void setIsAlive(bool isAlive);
            /**
             * @brief Get trantorian alive
             * @return false if dead, true if alive
             */
            [[nodiscard]] bool getIsAlive();

            /**
             * @brief Set trantorian action
             * @param bool
             */
            void setAction(bool Action);
            /**
             * @brief Get trantorian action
             * @return true if doing an action, false if not
             */
            [[nodiscard]] bool getAction();

            /**
             * @brief Set trantorian id
             * @param std::string
             */
            void setId(std::string id);
            /**
             * @brief Get trantorian id
             * @return int representing player's id
             */
            [[nodiscard]] std::string getId();

            /**
             * @brief Set trantorian level
             * @param level
             */
            void setLevel(int level);
            /**
             * @brief Get trantorian level
             * @return int representing player's level
             */
            [[nodiscard]] int getLevel();

            /**
             * @brief Compare two trantorians
             * @param other
             * @return true if equal, false if not
             */
            [[nodiscard]]
            bool operator==(const Trantorian& other) const;

            /**
             * @brief Set trantorian orientation
             * @param orientation
             */
            void setOrientation(int orientation);

            /**
            * @brief Get the object by type
            * @param type (type of the object)
            * @param pos (Position of the TILE where the object is supposed to be created)
            * @return IObject* (object)
            */
            IObject* createObjectByType(ResourceType type, Position pos);

            /**
             * @brief Set the trantorian's inventory
             * @param inventory (vector of strings)
             * @return void
             */
            void setInventory(std::vector<std::string> inventory);

            /**
             * @brief Clear the trantorian's inventory
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
            Teams* _team;
            int _lifetimeRemaining;
            bool _alive;
            bool _action;
            std::string _id;
            int _level;
            int _orientation;
            std::list<IObject *> _inventory;
    };
} // namespace GUI

#endif // TRANTORIAN_
