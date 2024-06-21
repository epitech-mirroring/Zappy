/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TrantorianMethods
*/

#include <gtest/gtest.h>
#include <climits>
#include "mocks/MockTrantorians.hpp"
#include "mocks/MockTeams.hpp"
#include "position/Position.hpp"

using namespace GUI;

TEST(trantorian_methods, PositionSetterAndGetters) {
    MockTrantorians player;
    Position res(42, 84);
    Position new_res(-42, -84);


    player.setPosition(42, 84);
    EXPECT_EQ(player.getPosition().getX(), res.getX());
    EXPECT_EQ(player.getPosition().getY(), res.getY());
    player.setPosition(-42, -84);
    EXPECT_EQ(player.getPosition().getX(), new_res.getX());
    EXPECT_EQ(player.getPosition().getY(), new_res.getY());
}

TEST(trantorian_methods, TeamSetterAndGetters) {
    MockTeams team1("Epitech");
    MockTeams team2("Zappy");
    MockTrantorians player;

    player.setTeam(&team1);
    EXPECT_EQ(player.getTeam()->getName(), team1.getName());
    player.setTeam(&team2);
    EXPECT_EQ(player.getTeam()->getName(), team2.getName());
}

TEST(trantorian_methods, LifetimeSetterAndGetters) {
    MockTrantorians player;
    int res = 42;
    int new_res = 84;

    player.setLifetime(42);
    EXPECT_EQ(player.getLifetime(), res);
    player.setLifetime(84);
    EXPECT_EQ(player.getLifetime(), new_res);
}

TEST(trantorian_methods, LevelSetterAndGetters) {
    MockTrantorians player;
    int res = 42;
    int new_res = 84;

    player.setLevel(42);
    EXPECT_EQ(player.getLevel(), res);
    player.setLevel(84);
    EXPECT_EQ(player.getLevel(), new_res);
}

TEST(trantorian_methods, IsAliveSetterAndGetters) {
    MockTrantorians player;
    bool res = false;
    bool new_res = true;

    player.setIsAlive(false);
    EXPECT_EQ(player.getIsAlive(), res);
    player.setIsAlive(true);
    EXPECT_EQ(player.getIsAlive(), new_res);
}

TEST(trantorian_methods, IdSetterAndGetters) {
    MockTrantorians player;
    std::string res = "4242";
    std::string new_res = "8484";

    player.setId("4242");
    EXPECT_EQ(player.getId(), res);
    player.setId("8484");
    EXPECT_EQ(player.getId(), new_res);
}

TEST(trantorian_methods, ActionSetterAndGetters) {
    MockTrantorians player;
    bool res = true;
    bool new_res = false;

    player.setAction(true);
    EXPECT_EQ(player.getAction(), res);
    player.setAction(false);
    EXPECT_EQ(player.getAction(), new_res);
}

TEST(trantorian_methods, NegativeLifetime) {
    MockTrantorians player;
    player.setLifetime(-42);
    EXPECT_EQ(player.getLifetime(), -42);
}

TEST(trantorian_methods, PositionBoundaryValues) {
    MockTrantorians player;
    Position max_res(INT_MAX, INT_MAX);
    Position min_res(INT_MIN, INT_MIN);

    player.setPosition(INT_MAX, INT_MAX);
    EXPECT_EQ(player.getPosition().getX(), max_res.getX());
    EXPECT_EQ(player.getPosition().getY(), max_res.getY());

    player.setPosition(INT_MIN, INT_MIN);
    EXPECT_EQ(player.getPosition().getX(), min_res.getX());
    EXPECT_EQ(player.getPosition().getY(), min_res.getY());
}

TEST(trantorian_methods, LevelBoundaryValues) {
    MockTrantorians player;
    player.setLevel(INT_MAX);
    EXPECT_EQ(player.getLevel(), INT_MAX);

    player.setLevel(INT_MIN);
    EXPECT_EQ(player.getLevel(), INT_MIN);
}

TEST(trantorian_methods, IsAliveDefault) {
    MockTrantorians player;
    EXPECT_EQ(player.getIsAlive(), true);
}

TEST(trantorian_methods, PositionDefault) {
    MockTrantorians player;
    Position default_res(0, 0);
    EXPECT_EQ(player.getPosition().getX(), default_res.getX());
    EXPECT_EQ(player.getPosition().getY(), default_res.getY());
}

TEST(trantorian_methods, TeamDefault) {
    MockTrantorians player;
    EXPECT_EQ(player.getTeam(), nullptr);
}

TEST(trantorian_methods, MultipleProperties) {
    MockTeams team("Zappy");
    MockTrantorians player;
    player.setTeam(&team);
    player.setLevel(5);
    player.setIsAlive(false);

    EXPECT_EQ(player.getTeam()->getName(), "Zappy");
    EXPECT_EQ(player.getLevel(), 5);
    EXPECT_EQ(player.getIsAlive(), false);
}

TEST(trantorian_methods, setInventory_AddObjects) {
    std::vector<std::string> objs = {"12", "X", "Y", "1", "0", "1", "0", "0", "0", "0"};
    MockTrantorians player("12", 0, 0, 1, 1, "Zappy");

    player.setInventory(objs);
    auto objects = player.getInventory();
    EXPECT_EQ(objects.size(), 2);

    int foodCount = 0;
    int deraumerecount = 0;

    for (auto obj : objects) {
        if (obj->getType() == MockTrantorians::FOOD) {
            foodCount++;
        } else if (obj->getType() == MockTrantorians::DERAUMERE) {
            deraumerecount++;
        }
        delete obj;
    }

    EXPECT_EQ(foodCount, 1);
    EXPECT_EQ(deraumerecount, 1);
}

TEST(trantorian_methods, setInventory_RemoveObjects) {
    MockTrantorians player("12", 0, 0, 1, 1, "Zappy");
    IObject* food = new Food(Position(0, 0));
    IObject* linemate = new Linemate(Position(0, 0));
    player.addObject(food);
    player.addObject(linemate);

    std::vector<std::string> objs = {"12", "X", "Y", "0", "0", "0", "0", "0", "0", "0"};
    player.setInventory(objs);

    auto objects = player.getInventory();
    EXPECT_EQ(objects.size(), 0);
}

TEST(trantorian_methods, setInventory_MixedChanges) {
    MockTrantorians player("12", 0, 0, 1, 1, "Zappy");
    IObject* food = new Food(Position(0, 0));
    IObject* linemate = new Linemate(Position(0, 0));
    player.addObject(food);
    player.addObject(linemate);

    std::vector<std::string> objs = {"12", "X", "Y", "1", "0", "1", "0", "0", "0", "0"};
    player.setInventory(objs);

    auto objects = player.getInventory();
    EXPECT_EQ(objects.size(), 2);

    int foodCount = 0;
    int deraumerecount = 0;

    for (auto obj : objects) {
        if (obj->getType() == MockTrantorians::FOOD) {
            foodCount++;
        } else if (obj->getType() == MockTrantorians::DERAUMERE) {
            deraumerecount++;
        }
        delete obj;
    }

    EXPECT_EQ(foodCount, 1);
    EXPECT_EQ(deraumerecount, 1);
}
