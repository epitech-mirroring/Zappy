/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TrantorianMethods
*/

#include <gtest/gtest.h>
#include <climits>
#include "trantorians/Trantorian.hpp"
#include "trantorians/Teams.hpp"
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
    Teams team1("Epitech");
    Teams team2("Zappy");
    Trantorian player;

    player.setTeam(&team1);
    EXPECT_EQ(player.getTeam()->getName(), team1.getName());
    player.setTeam(&team2);
    EXPECT_EQ(player.getTeam()->getName(), team2.getName());
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
    player.setIsAlive(true);
    EXPECT_EQ(player.getIsAlive(), new_res);
}

TEST(trantorian_methods, IdSetterAndGetters) {
    Trantorian player;
    int res = 4242;
    int new_res = 8484;

    player.setId(4242);
    EXPECT_EQ(player.getId(), res);
    player.setId(8484);
    EXPECT_EQ(player.getId(), new_res);
}

TEST(trantorian_methods, ActionSetterAndGetters) {
    Trantorian player;
    bool res = true;
    bool new_res = false;

    player.setAction(true);
    EXPECT_EQ(player.getAction(), res);
    player.setAction(false);
    EXPECT_EQ(player.getAction(), new_res);
}

TEST(trantorian_methods, NegativeLifetime) {
    Trantorian player;
    player.setLifetime(-42);
    EXPECT_EQ(player.getLifetime(), -42);
}

TEST(trantorian_methods, PositionBoundaryValues) {
    Trantorian player;
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
    Trantorian player;
    player.setLevel(INT_MAX);
    EXPECT_EQ(player.getLevel(), INT_MAX);

    player.setLevel(INT_MIN);
    EXPECT_EQ(player.getLevel(), INT_MIN);
}

TEST(trantorian_methods, IsAliveDefault) {
    Trantorian player;
    EXPECT_EQ(player.getIsAlive(), true);
}

TEST(trantorian_methods, PositionDefault) {
    Trantorian player;
    Position default_res(0, 0);
    EXPECT_EQ(player.getPosition().getX(), default_res.getX());
    EXPECT_EQ(player.getPosition().getY(), default_res.getY());
}

TEST(trantorian_methods, TeamDefault) {
    Trantorian player;
    EXPECT_EQ(player.getTeam(), nullptr);
}

TEST(trantorian_methods, MultipleProperties) {
    Teams team("Zappy");
    Trantorian player;
    player.setTeam(&team);
    player.setLevel(5);
    player.setIsAlive(false);

    EXPECT_EQ(player.getTeam()->getName(), "Zappy");
    EXPECT_EQ(player.getLevel(), 5);
    EXPECT_EQ(player.getIsAlive(), false);
}
