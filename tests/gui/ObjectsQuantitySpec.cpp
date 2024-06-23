/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_objects_density_spec
*/

#include <gtest/gtest.h>
#include <memory>
#include "objects/stones/Deraumere.hpp"
#include "objects/stones/Linemate.hpp"
#include "objects/stones/Mendiane.hpp"
#include "objects/stones/Phiras.hpp"
#include "objects/stones/Sibur.hpp"
#include "objects/stones/Thystame.hpp"
#include "objects/food/Food.hpp"

TEST(get_objects_density, test1)
{
    GUI::Deraumere deraumere;
    ASSERT_EQ(1, deraumere.getQuantity());
}

TEST(get_objects_density, test2)
{
    GUI::Linemate linemate;
    ASSERT_EQ(1, linemate.getQuantity());
}

TEST(get_objects_density, test3)
{
    GUI::Mendiane mendiane;
    ASSERT_EQ(1, mendiane.getQuantity());
}

TEST(get_objects_density, test4)
{
    GUI::Phiras phiras;
    ASSERT_EQ(1, phiras.getQuantity());
}

TEST(get_objects_density, test5)
{
    GUI::Sibur sibur;
    ASSERT_EQ(1, sibur.getQuantity());
}

TEST(get_objects_density, test6)
{
    GUI::Thystame thystame;
    ASSERT_EQ(1, thystame.getQuantity());
}

TEST(get_objects_density, test7)
{
    GUI::Food food;
    ASSERT_EQ(1, food.getQuantity());
}

TEST(get_object_density, test7)
{
    GUI::Deraumere deraumere;

    std::unique_ptr<GUI::AStone> deraumere_ptr =
        std::make_unique<GUI::Deraumere>();
    ASSERT_EQ(1, deraumere_ptr->getQuantity());
}

TEST(get_object_density, test8)
{
    GUI::Linemate linemate;

    std::unique_ptr<GUI::AStone> linemate_ptr =
        std::make_unique<GUI::Linemate>();
    ASSERT_EQ(1, linemate_ptr->getQuantity());
}

TEST(get_object_density, test9)
{
    GUI::Mendiane mendiane;

    std::unique_ptr<GUI::AStone> mendiane_ptr =
        std::make_unique<GUI::Mendiane>();
    ASSERT_EQ(1, mendiane_ptr->getQuantity());
}

TEST(get_object_density, test10)
{
    GUI::Phiras phiras;

    std::unique_ptr<GUI::AStone> phiras_ptr =
        std::make_unique<GUI::Phiras>();
    ASSERT_EQ(1, phiras_ptr->getQuantity());
}

TEST(get_object_density, test11)
{
    GUI::Sibur sibur;

    std::unique_ptr<GUI::AStone> sibur_ptr =
        std::make_unique<GUI::Sibur>();
    ASSERT_EQ(1, sibur_ptr->getQuantity());
}

TEST(get_object_density, test12)
{
    GUI::Thystame thystame;

    std::unique_ptr<GUI::AStone> thystame_ptr =
        std::make_unique<GUI::Thystame>();
    ASSERT_EQ(1, thystame_ptr->getQuantity());
}

TEST(get_object_density, test13)
{
    GUI::Food food;

    std::unique_ptr<GUI::Food> food_ptr =
        std::make_unique<GUI::Food>();
    ASSERT_EQ(1, food_ptr->getQuantity());
}
