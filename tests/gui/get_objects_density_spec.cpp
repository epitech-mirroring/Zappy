/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** get_objects_density
*/

#include <gtest/gtest.h>
#include <memory>
#include "stones/Deraumere.hpp"
#include "stones/Linemate.hpp"
#include "stones/Mendiane.hpp"
#include "stones/Phiras.hpp"
#include "stones/Sibur.hpp"
#include "stones/Thystame.hpp"
#include "food/Food.hpp"

TEST(get_objects_density, test1)
{
    GUI::Deraumere deraumere;
    ASSERT_FLOAT_EQ(0.15, deraumere.getDensity());
}

TEST(get_objects_density, test2)
{
    GUI::Linemate linemate;
    ASSERT_FLOAT_EQ(0.3, linemate.getDensity());
}

TEST(get_objects_density, test3)
{
    GUI::Mendiane mendiane;
    ASSERT_FLOAT_EQ(0.1, mendiane.getDensity());
}

TEST(get_objects_density, test4)
{
    GUI::Phiras phiras;
    ASSERT_FLOAT_EQ(0.08, phiras.getDensity());
}

TEST(get_objects_density, test5)
{
    GUI::Sibur sibur;
    ASSERT_FLOAT_EQ(0.1, sibur.getDensity());
}

TEST(get_objects_density, test6)
{
    GUI::Thystame thystame;
    ASSERT_FLOAT_EQ(0.05, thystame.getDensity());
}

TEST(get_objects_density, test7)
{
    GUI::Food food;
    ASSERT_FLOAT_EQ(0.5, food.getDensity());
}

// NOW TESTS WITH UNIQUE PTS OBJECTS //

TEST(get_object_density, test7)
{
    GUI::Deraumere deraumere;

    std::unique_ptr<GUI::AStone> deraumere_ptr =
        std::make_unique<GUI::Deraumere>();
    ASSERT_FLOAT_EQ(0.15, deraumere_ptr->getDensity());
}

TEST(get_object_density, test8)
{
    GUI::Linemate linemate;

    std::unique_ptr<GUI::AStone> linemate_ptr =
        std::make_unique<GUI::Linemate>();
    ASSERT_FLOAT_EQ(0.3, linemate_ptr->getDensity());
}

TEST(get_object_density, test9)
{
    GUI::Mendiane mendiane;

    std::unique_ptr<GUI::AStone> mendiane_ptr =
        std::make_unique<GUI::Mendiane>();
    ASSERT_FLOAT_EQ(0.1, mendiane_ptr->getDensity());
}

TEST(get_object_density, test10)
{
    GUI::Phiras phiras;

    std::unique_ptr<GUI::AStone> phiras_ptr =
        std::make_unique<GUI::Phiras>();
    ASSERT_FLOAT_EQ(0.08, phiras_ptr->getDensity());
}

TEST(get_object_density, test11)
{
    GUI::Sibur sibur;

    std::unique_ptr<GUI::AStone> sibur_ptr =
        std::make_unique<GUI::Sibur>();
    ASSERT_FLOAT_EQ(0.1, sibur_ptr->getDensity());
}

TEST(get_object_density, test12)
{
    GUI::Thystame thystame;

    std::unique_ptr<GUI::AStone> thystame_ptr =
        std::make_unique<GUI::Thystame>();
    ASSERT_FLOAT_EQ(0.05, thystame_ptr->getDensity());
}

TEST(get_object_density, test13)
{
    GUI::Food food;

    std::unique_ptr<GUI::Food> food_ptr =
        std::make_unique<GUI::Food>();
    ASSERT_FLOAT_EQ(0.5, food_ptr->getDensity());
}
