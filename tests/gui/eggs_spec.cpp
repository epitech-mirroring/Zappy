/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** eggs_spec
*/

#include <gtest/gtest.h>
#include "objects/eggs/Egg.hpp"

using namespace GUI;

TEST(EggTest, ConstructorAndGetters) {
    Egg egg("TeamA", 42);

    EXPECT_EQ(egg.getTeam(), "TeamA");
    EXPECT_EQ(egg.getOwnerID(), 42);
    EXPECT_EQ(egg.getDensity(), 0);
}

TEST(EggTest, SetAndGetIsEjected) {
    Egg egg("TeamA");

    egg.setIsEjected(true);
    EXPECT_TRUE(egg.getIsEjected());

    egg.setIsEjected(false);
    EXPECT_FALSE(egg.getIsEjected());
}

TEST(EggTest, DefaultOwnerID) {
    Egg egg("TeamA");

    EXPECT_EQ(egg.getOwnerID(), -1);
}

TEST(EggTest, DifferentTeam) {
    Egg egg("TeamB", 10);

    EXPECT_EQ(egg.getTeam(), "TeamB");
    EXPECT_EQ(egg.getOwnerID(), 10);
}

TEST(EggTest, SetAndGetTeam) {
    Egg egg("TeamA", 42);

    EXPECT_EQ(egg.getTeam(), "TeamA");
}

TEST(EggTest, DefaultValues) {
    Egg egg("TeamA");

    EXPECT_EQ(egg.getDensity(), 0);
    EXPECT_EQ(egg.getOwnerID(), -1);
    EXPECT_FALSE(egg.getIsEjected());
}

TEST(EggTest, ModifiedValues) {
    Egg egg("TeamA", 10);
    egg.setIsEjected(true);
    EXPECT_TRUE(egg.getIsEjected());

    egg.getTeam() = "TeamA";
    EXPECT_EQ(egg.getTeam(), "TeamA");
}

TEST(EggTest, Destructor) {
    Egg* egg = new Egg("TeamA", 42);
    delete egg;
}

TEST(EggTest, ConstGetters) {
    const Egg egg("TeamA", 42);

    EXPECT_EQ(egg.getTeam(), "TeamA");
    EXPECT_EQ(egg.getOwnerID(), 42);
    EXPECT_EQ(egg.getDensity(), 0);
    EXPECT_FALSE(egg.getIsEjected());
}

TEST(EggTest, BooleanValues) {
    Egg egg("TeamA", 42);

    egg.setIsEjected(true);
    EXPECT_TRUE(egg.getIsEjected());

    egg.setIsEjected(false);
    EXPECT_FALSE(egg.getIsEjected());
}
