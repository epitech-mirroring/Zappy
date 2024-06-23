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
    class Trantorian {
        public:
            enum Action {
                NONE = -1,
                BROADCAST,
                EXPULSION,
                COLLECT,
                DROP,
                INCANTATION_S,
                INCANTATION_E
            };
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
             * @brief Create trantorian object
             */
            Trantorian(std::string id = "null", int x = 0, int y = 0, float orientation = NORTH,
                int level = 1);
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
            [[nodiscard]] const GUI::Position& getPosition() const;

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
            void setAction(Action action);
            /**
             * @brief Get trantorian action
             * @return Action (corresponding to current action)
             */
            [[nodiscard]] Action getAction();
            /**
             * @brief Set time when action start
             * @param float action start time
             * @return void (nothing to return)
             */
            void setActionStartTime(float time);
            /**
             * @brief Get action start time
             * @return float (time when action start)
             */
            [[nodiscard]] float getActionStartTime() const;

            /**
             * @brief Set trantorian id
             * @param std::string
             */
            void setId(std::string id);
            /**
             * @brief Get trantorian id
             * @return int representing player's id
             */
            [[nodiscard]] std::string getId() const;

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
            void setOrientation(float orientation);

            /**
             * @brief Get trantorian orientation
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

            /**
             * @brief Get the Model object
             */
            [[nodiscard]] Model getModel() const;
            /**
             * @brief Get the Texture object
             */
            [[nodiscard]] Texture2D getTexture() const;

            /**
             * @brief Get the pex Model object
             */
            [[nodiscard]] Model getPexModel() const;
            /**
             * @brief Get the pbc Model object
             */
            [[nodiscard]] Model getPbcModel() const;
            /**
             * @brief Get the pdr Model object
             */
            [[nodiscard]] Model getPdrModel() const;
            /**
             * @brief Get the pgt Model object
             */
            [[nodiscard]] Model getPgtModel() const;
            /**
             * @brief Get the pic Model object
             */
            [[nodiscard]] Model getPicModel() const;
            /**
             * @brief Get the pie Model object
             */
            [[nodiscard]] Model getPieModel() const;

        private:
            GUI::Position _position;
            int _lifetimeRemaining;
            bool _alive;
            Action _action;
            float _actionStartTime;
            std::string _id;
            int _level;
            float _orientation;
            std::list<IObject *> _inventory;
            Model _trantorianModel;
            Texture2D _trantorianTexture;
            Model _pexModel;
            Texture2D _pexTexture;
            Model _pbcModel;
            Texture2D _pbcTexture;
            Model _pdrModel;
            Texture2D _pdrTexture;
            Model _pgtModel;
            Texture2D _pgtTexture;
            Model _picModel;
            Texture2D _picTexture;
            Model _pieModel;
            Texture2D _pieTexture;

    };
} // namespace GUI  //
#endif // TRANTORIAN_
