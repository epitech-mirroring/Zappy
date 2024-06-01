/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** WorldTest
*/

#include <gtest/gtest.h>
#include <memory>
#include "world/World.hpp"

TEST(WorldTest, Constructor) {
    GUI::World world(10, 20);
    ASSERT_EQ(10, world.getWidth());
    ASSERT_EQ(20, world.getHeight());
}

TEST(WorldTest, SetWidth) {
    GUI::World world(10, 20);
    world.setWidth(30);
    ASSERT_EQ(30, world.getWidth());
}

TEST(WorldTest, SetHeight) {
    GUI::World world(10, 20);
    world.setHeight(40);
    ASSERT_EQ(40, world.getHeight());
}

TEST(WorldTest, GetWidth) {
    GUI::World world(50, 60);
    ASSERT_EQ(50, world.getWidth());
}

TEST(WorldTest, GetHeight) {
    GUI::World world(70, 80);
    ASSERT_EQ(80, world.getHeight());
}

TEST(WorldTest, UniquePtrSetWidth) {
    std::unique_ptr<GUI::World> world = std::make_unique<GUI::World>(10, 20);
    world->setWidth(30);
    ASSERT_EQ(30, world->getWidth());
}

TEST(WorldTest, UniquePtrSetHeight) {
    std::unique_ptr<GUI::World> world = std::make_unique<GUI::World>(10, 20);
    world->setHeight(40);
    ASSERT_EQ(40, world->getHeight());
}

TEST(WorldTest, UniquePtrGetWidth) {
    std::unique_ptr<GUI::World> world = std::make_unique<GUI::World>(50, 60);
    ASSERT_EQ(50, world->getWidth());
}

TEST(WorldTest, UniquePtrGetHeight) {
    std::unique_ptr<GUI::World> world = std::make_unique<GUI::World>(70, 80);
    ASSERT_EQ(80, world->getHeight());
}
