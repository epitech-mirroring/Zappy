/*
** File description:
** trantorian_methods tests
*/

#include <gtest/gtest.h>
#include "trantorians/Trantorian.hpp"
#include "position/Position.hpp"

using namespace GUI;

TEST(trantorian_methods, PositionSetterAndGetters) {
    Trantorian player;
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
    Trantorian player;
    std::string res = "Epitech";
    std::string new_res = "Zappy";

    player.setTeam("Epitech");
    EXPECT_EQ(player.getTeam(), res);
    player.setTeam("Zappy");
    EXPECT_EQ(player.getTeam(), new_res);
}

TEST(trantorian_methods, LifetimeSetterAndGetters) {
    Trantorian player;
    int res = 42;
    int new_res = 84;

    player.setLifetime(42);
    EXPECT_EQ(player.getLifetime(), res);
    player.setLifetime(84);
    EXPECT_EQ(player.getLifetime(), new_res);
}

TEST(trantorian_methods, LevelSetterAndGetters) {
    Trantorian player;
    int res = 42;
    int new_res = 84;

    player.setLevel(42);
    EXPECT_EQ(player.getLevel(), res);
    player.setLevel(84);
    EXPECT_EQ(player.getLevel(), new_res);
}

TEST(trantorian_methods, IsAliveSetterAndGetters) {
    Trantorian player;
    bool res = false;
    bool new_res = true;

    player.setIsAlive(false);
    EXPECT_EQ(player.getIsAlive(), res);
    player.setLifetime(true);
    EXPECT_EQ(player.getLifetime(), new_res);
}

TEST(trantorian_methods, IdSetterAndGetters) {
    Trantorian player;
    int res = 4242;
    int new_res = 8484;

    player.setId(4242);
    EXPECT_EQ(player.getId(), res);
    player.setLifetime(8484);
    EXPECT_EQ(player.getLifetime(), new_res);
}

TEST(trantorian_methods, ActionSetterAndGetters) {
    Trantorian player;
    bool res = true;
    bool new_res = false;

    player.setAction(true);
    EXPECT_EQ(player.getAction(), res);
    player.setLifetime(false);
    EXPECT_EQ(player.getLifetime(), new_res);
}
