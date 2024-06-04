/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** get_objects_positions_spec
*/

#include <gtest/gtest.h>
#include <memory>
#include "position/Position.hpp"
#include "objects/stones/Deraumere.hpp"
#include "objects/stones/Linemate.hpp"
#include "objects/stones/Mendiane.hpp"
#include "objects/stones/Phiras.hpp"
#include "objects/stones/Sibur.hpp"
#include "objects/stones/Thystame.hpp"
#include "objects/food/Food.hpp"

TEST(set_objects_position, test1)
{
    GUI::Deraumere deraumere;
    deraumere.getPosition().setX(5);
    deraumere.getPosition().setY(10);
    ASSERT_EQ(5, deraumere.getPosition().getX());
    ASSERT_EQ(10, deraumere.getPosition().getY());
}

TEST(set_objects_position, test2)
{
    GUI::Linemate linemate;
    linemate.getPosition().setX(3);
    linemate.getPosition().setY(7);
    ASSERT_EQ(3, linemate.getPosition().getX());
    ASSERT_EQ(7, linemate.getPosition().getY());
}

TEST(set_objects_position, test3)
{
    GUI::Mendiane mendiane;
    mendiane.getPosition().setX(2);
    mendiane.getPosition().setY(4);
    ASSERT_EQ(2, mendiane.getPosition().getX());
    ASSERT_EQ(4, mendiane.getPosition().getY());
}

TEST(set_objects_position, test4)
{
    GUI::Phiras phiras;
    phiras.getPosition().setX(8);
    phiras.getPosition().setY(6);
    ASSERT_EQ(8, phiras.getPosition().getX());
    ASSERT_EQ(6, phiras.getPosition().getY());
}

TEST(set_objects_position, test5)
{
    GUI::Sibur sibur;
    sibur.getPosition().setX(1);
    sibur.getPosition().setY(1);
    ASSERT_EQ(1, sibur.getPosition().getX());
    ASSERT_EQ(1, sibur.getPosition().getY());
}

TEST(set_objects_position, test6)
{
    GUI::Thystame thystame;
    thystame.getPosition().setX(0);
    thystame.getPosition().setY(0);
    ASSERT_EQ(0, thystame.getPosition().getX());
    ASSERT_EQ(0, thystame.getPosition().getY());
}

TEST(set_objects_position, test7)
{
    GUI::Food food;
    food.getPosition().setX(10);
    food.getPosition().setY(20);
    ASSERT_EQ(10, food.getPosition().getX());
    ASSERT_EQ(20, food.getPosition().getY());
}

TEST(get_objects_position_ptr, test1)
{
    std::unique_ptr<GUI::AObject> deraumere_ptr = std::make_unique<GUI::Deraumere>();
    ASSERT_EQ(0, deraumere_ptr->getPosition().getX());
    ASSERT_EQ(0, deraumere_ptr->getPosition().getY());
}

TEST(set_objects_position_ptr, test1)
{
    std::unique_ptr<GUI::AObject> deraumere_ptr = std::make_unique<GUI::Deraumere>();
    deraumere_ptr->getPosition().setX(7);
    deraumere_ptr->getPosition().setY(14);
    ASSERT_EQ(7, deraumere_ptr->getPosition().getX());
    ASSERT_EQ(14, deraumere_ptr->getPosition().getY());
}
