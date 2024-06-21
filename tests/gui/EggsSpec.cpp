/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** eggs_spec
*/

#include <gtest/gtest.h>
#include "mocks/MockEgg.hpp"

using namespace GUI;

TEST(MockEggTest, ConstructorAndGetters) {
    Position pos(0, 0);
    MockEgg egg("TeamA", "42", pos);

    EXPECT_EQ(egg.getTeam(), "TeamA");
    EXPECT_EQ(egg.getOwnerID(), "42");
    EXPECT_EQ(egg.getPosition().getX(), 0);
    EXPECT_EQ(egg.getPosition().getY(), 0);
}

TEST(MockEggTest, SetAndGetIsEjected) {
    Position pos(0, 0);
    MockEgg egg("TeamA", "42", pos);

    egg.setIsEjected(true);
    EXPECT_TRUE(egg.getIsEjected());

    egg.setIsEjected(false);
    EXPECT_FALSE(egg.getIsEjected());
}

TEST(MockEggTest, DefaultOwnerID) {
    Position pos(0, 0);
    MockEgg egg("TeamA");

    EXPECT_EQ(egg.getOwnerID(), "-1");
}

TEST(MockEggTest, DifferentTeam) {
    Position pos(0, 0);
    MockEgg egg("TeamB", "10", pos);

    EXPECT_EQ(egg.getTeam(), "TeamB");
    EXPECT_EQ(egg.getOwnerID(), "10");
}

TEST(MockEggTest, SetAndGetTeam) {
    Position pos(0, 0);
    MockEgg egg("TeamA", "42", pos);

    EXPECT_EQ(egg.getTeam(), "TeamA");
}

TEST(MockEggTest, DefaultValues) {
    Position pos(0, 0);
    MockEgg egg("TeamA");

    EXPECT_EQ(egg.getOwnerID(), "-1");
    EXPECT_FALSE(egg.getIsEjected());
}

TEST(MockEggTest, ModifiedValues) {
    Position pos(0, 0);
    MockEgg egg("TeamA", "10", pos);
    egg.setIsEjected(true);
    EXPECT_TRUE(egg.getIsEjected());

    EXPECT_EQ(egg.getTeam(), "TeamA");
}

TEST(MockEggTest, Destructor) {
    Position pos(0, 0);
    MockEgg* egg = new MockEgg("TeamA", "42", pos);
    delete egg;
}

TEST(MockEggTest, ConstGetters) {
    Position pos(0, 0);
    const MockEgg egg("TeamA", "42", pos);

    EXPECT_EQ(egg.getTeam(), "TeamA");
    EXPECT_EQ(egg.getOwnerID(), "42");
    EXPECT_FALSE(egg.getIsEjected());
}

TEST(MockEggTest, BooleanValues) {
    Position pos(0, 0);
    MockEgg egg("TeamA", "42", pos);

    egg.setIsEjected(true);
    EXPECT_TRUE(egg.getIsEjected());

    egg.setIsEjected(false);
    std::cout << "zozo" << std::endl;
    EXPECT_FALSE(egg.getIsEjected());
}
