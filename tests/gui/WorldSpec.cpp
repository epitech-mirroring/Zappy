#include <gtest/gtest.h>
#include <memory>
#include "world/World.hpp"
#include "tiles/Tile.hpp"
#include "objects/stones/Deraumere.hpp"

TEST(WorldTest, Constructor) {
    GUI::World world(10, 10);
    ASSERT_EQ(world.getWidth(), 10);
    ASSERT_EQ(world.getHeight(), 10);
}

TEST(WorldTest, SetWidth) {
    GUI::World world(10, 10);
    world.setWidth(20);
    ASSERT_EQ(world.getWidth(), 20);
}

TEST(WorldTest, SetHeight) {
    GUI::World world(10, 10);
    world.setHeight(20);
    ASSERT_EQ(world.getHeight(), 20);
}

TEST(WorldTest, AddObject) {
    GUI::World world(10, 10);
    GUI::Deraumere deraumere;
    GUI::Position pos(5, 5);

    world.addObject(&deraumere, pos);

    auto objectsAtTile = world.getObjectsAt(pos);
    ASSERT_EQ(objectsAtTile.size(), 1);
    ASSERT_EQ(objectsAtTile.front(), &deraumere);
}

TEST(WorldTest, RemoveObject) {
    GUI::World world(10, 10);
    GUI::Deraumere deraumere;
    GUI::Position pos(5, 5);

    world.addObject(&deraumere, pos);
    world.removeObject(&deraumere, pos);

    auto objectsAtTile = world.getObjectsAt(pos);
    ASSERT_EQ(objectsAtTile.size(), 0);
}

TEST(WorldTest, GetObjects) {
    GUI::World world(10, 10);
    GUI::Deraumere deraumere1;
    GUI::Deraumere deraumere2;
    GUI::Position pos1(5, 5);
    GUI::Position pos2(6, 6);

    world.addObject(&deraumere1, pos1);
    world.addObject(&deraumere2, pos2);

    auto objects = world.getObjects();
    ASSERT_EQ(objects.size(), 2);
    ASSERT_NE(std::find(objects.begin(), objects.end(), &deraumere1), objects.end());
    ASSERT_NE(std::find(objects.begin(), objects.end(), &deraumere2), objects.end());
}

TEST(WorldTest, SetWorldSize) {
    GUI::World world(5, 5);
    world.setWorldSize(10, 10);

    ASSERT_EQ(world.getWidth(), 10);
    ASSERT_EQ(world.getHeight(), 10);

    GUI::Deraumere deraumere;
    GUI::Position pos(9, 9);
    world.addObject(&deraumere, pos);

    auto objectsAtTile = world.getObjectsAt(pos);
    ASSERT_EQ(objectsAtTile.size(), 1);
    ASSERT_EQ(objectsAtTile.front(), &deraumere);
}

TEST(TileTest, Constructor) {
    GUI::Position pos(1, 1);
    GUI::Tile tile(pos);

    ASSERT_EQ(tile.getPosition().getX(), 1);
    ASSERT_EQ(tile.getPosition().getY(), 1);
}

TEST(TileTest, AddObject) {
    GUI::Position pos(1, 1);
    GUI::Tile tile(pos);
    GUI::Deraumere deraumere;

    tile.addObject(&deraumere);

    auto objects = tile.getObjects();
    ASSERT_EQ(objects.size(), 1);
    ASSERT_EQ(objects.front(), &deraumere);
}

TEST(TileTest, RemoveObject) {
    GUI::Position pos(1, 1);
    GUI::Tile tile(pos);
    GUI::Deraumere deraumere;

    tile.addObject(&deraumere);
    tile.removeObject(&deraumere);

    auto objects = tile.getObjects();
    ASSERT_EQ(objects.size(), 0);
}

TEST(TileTest, GetObjects) {
    GUI::Position pos(1, 1);
    GUI::Tile tile(pos);
    GUI::Deraumere deraumere1;
    GUI::Deraumere deraumere2;

    tile.addObject(&deraumere1);
    tile.addObject(&deraumere2);

    auto objects = tile.getObjects();
    ASSERT_EQ(objects.size(), 2);
    ASSERT_NE(std::find(objects.begin(), objects.end(), &deraumere1), objects.end());
    ASSERT_NE(std::find(objects.begin(), objects.end(), &deraumere2), objects.end());
}

TEST(TileTest, AddMultipleObjects) {
    GUI::Position pos(1, 1);
    GUI::Tile tile(pos);
    GUI::Deraumere deraumere1;
    GUI::Deraumere deraumere2;

    tile.addObject(&deraumere1);
    tile.addObject(&deraumere2);

    auto objects = tile.getObjects();
    ASSERT_EQ(objects.size(), 2);
    ASSERT_NE(std::find(objects.begin(), objects.end(), &deraumere1), objects.end());
    ASSERT_NE(std::find(objects.begin(), objects.end(), &deraumere2), objects.end());
}

TEST(TileTest, RemoveObjectNotPresent) {
    GUI::Position pos(1, 1);
    GUI::Tile tile(pos);
    GUI::Deraumere deraumere1;
    GUI::Deraumere deraumere2;

    tile.addObject(&deraumere1);
    tile.removeObject(&deraumere2);

    auto objects = tile.getObjects();
    ASSERT_EQ(objects.size(), 1);
    ASSERT_EQ(objects.front(), &deraumere1);
}

TEST(TileTest, AddAndRemoveMultipleObjects) {
    GUI::Position pos(1, 1);
    GUI::Tile tile(pos);
    GUI::Deraumere deraumere1;
    GUI::Deraumere deraumere2;
    GUI::Deraumere deraumere3;

    tile.addObject(&deraumere1);
    tile.addObject(&deraumere2);
    tile.addObject(&deraumere3);

    tile.removeObject(&deraumere2);

    auto objects = tile.getObjects();
    ASSERT_EQ(objects.size(), 2);
    ASSERT_NE(std::find(objects.begin(), objects.end(), &deraumere1), objects.end());
    ASSERT_NE(std::find(objects.begin(), objects.end(), &deraumere3), objects.end());
    ASSERT_EQ(std::find(objects.begin(), objects.end(), &deraumere2), objects.end());
}

TEST(TileTest, RemoveAllObjects) {
    GUI::Position pos(1, 1);
    GUI::Tile tile(pos);
    GUI::Deraumere deraumere1;
    GUI::Deraumere deraumere2;

    tile.addObject(&deraumere1);
    tile.addObject(&deraumere2);

    tile.removeObject(&deraumere1);
    tile.removeObject(&deraumere2);

    auto objects = tile.getObjects();
    ASSERT_EQ(objects.size(), 0);
}

TEST(TileTest, AddSameObjectMultipleTimes) {
    GUI::Position pos(1, 1);
    GUI::Tile tile(pos);
    GUI::Deraumere deraumere;

    tile.addObject(&deraumere);
    tile.addObject(&deraumere);

    auto objects = tile.getObjects();
    ASSERT_EQ(objects.size(), 2);
    ASSERT_EQ(std::count(objects.begin(), objects.end(), &deraumere), 2);
}
