/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** WorldTest
*/

#include <gtest/gtest.h>
#include <memory>
#include "world/World.hpp"
#include "objects/stones/Deraumere.hpp"
#include "objects/stones/Linemate.hpp"

TEST(WorldTest, Constructor) {
    GUI::World world(100, 200);
    ASSERT_EQ(100, world.getWidth());
    ASSERT_EQ(200, world.getHeight());
}

TEST(WorldTest, SetWidth) {
    GUI::World world(100, 200);
    world.setWidth(300);
    ASSERT_EQ(300, world.getWidth());
}

TEST(WorldTest, SetHeight) {
    GUI::World world(100, 200);
    world.setHeight(400);
    ASSERT_EQ(400, world.getHeight());
}

TEST(WorldTest, AddObject) {
    GUI::World world(100, 200);
    GUI::Deraumere deraumere;
    world.addObject(&deraumere);
    ASSERT_EQ(1, world.getObjects().size());
}

TEST(WorldTest, RemoveObject) {
    GUI::World world(100, 200);
    GUI::Deraumere deraumere;
    world.addObject(&deraumere);
    world.removeObject(&deraumere);
    ASSERT_EQ(0, world.getObjects().size());
}

TEST(WorldTest, GetObjectsAt) {
    GUI::World world(100, 200);
    GUI::Deraumere deraumere;
    deraumere.getPosition().setX(10);
    deraumere.getPosition().setY(20);
    world.addObject(&deraumere);
    auto objectsAt = world.getObjectsAt(GUI::Position(10, 20));
    ASSERT_EQ(1, objectsAt.size());
}

TEST(WorldTest, NoObjectsAt) {
    GUI::World world(100, 200);
    GUI::Deraumere deraumere;
    deraumere.getPosition().setX(10);
    deraumere.getPosition().setY(20);
    world.addObject(&deraumere);
    auto objectsAt = world.getObjectsAt(GUI::Position(30, 40));
    ASSERT_EQ(0, objectsAt.size());
}

TEST(WorldTest, MultipleObjectsAt) {
    GUI::World world(100, 200);
    GUI::Deraumere deraumere;
    GUI::Linemate linemate;
    deraumere.getPosition().setX(10);
    deraumere.getPosition().setY(20);
    linemate.getPosition().setX(10);
    linemate.getPosition().setY(20);
    world.addObject(&deraumere);
    world.addObject(&linemate);
    auto objectsAt = world.getObjectsAt(GUI::Position(10, 20));
    ASSERT_EQ(2, objectsAt.size());
}

TEST(WorldTest, GetObjects) {
    GUI::World world(100, 200);
    GUI::Deraumere deraumere;
    GUI::Linemate linemate;
    world.addObject(&deraumere);
    world.addObject(&linemate);
    auto objects = world.getObjects();
    ASSERT_EQ(2, objects.size());
}

TEST(WorldTest, AddAndRemoveMultipleObjects) {
    GUI::World world(100, 200);
    GUI::Deraumere deraumere;
    GUI::Linemate linemate;
    world.addObject(&deraumere);
    world.addObject(&linemate);
    ASSERT_EQ(2, world.getObjects().size());
    world.removeObject(&deraumere);
    ASSERT_EQ(1, world.getObjects().size());
    world.removeObject(&linemate);
    ASSERT_EQ(0, world.getObjects().size());
}
