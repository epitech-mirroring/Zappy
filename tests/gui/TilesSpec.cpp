/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TilesSpec
*/

#include <gtest/gtest.h>
#include "tiles/Tile.hpp"
#include "objects/food/Food.hpp"
#include "objects/stones/Linemate.hpp"
#include "objects/stones/Deraumere.hpp"
#include "objects/stones/Sibur.hpp"
#include "objects/stones/Mendiane.hpp"
#include "objects/stones/Phiras.hpp"
#include "objects/stones/Thystame.hpp"

using namespace GUI;

class TileTest : public ::testing::Test {
protected:
    TileTest() : tile(Position(0, 0)) {}

    Tile tile;
};

TEST_F(TileTest, GetPosition) {
    Position pos = tile.getPosition();
    EXPECT_EQ(pos.getX(), 0);
    EXPECT_EQ(pos.getY(), 0);

    Tile tile2(Position(5, 10));
    Position pos2 = tile2.getPosition();
    EXPECT_EQ(pos2.getX(), 5);
    EXPECT_EQ(pos2.getY(), 10);
}

TEST_F(TileTest, AddObject) {
    IObject* food = new Food(Position(0, 0));
    tile.addObject(food);
    auto objects = tile.getObjects();
    EXPECT_EQ(objects.size(), 1);
    EXPECT_EQ(objects.front(), food);

    IObject* linemate = new Linemate(Position(0, 0));
    tile.addObject(linemate);
    objects = tile.getObjects();
    EXPECT_EQ(objects.size(), 2);
    EXPECT_EQ(objects.back(), linemate);

    delete food;
    delete linemate;
}

TEST_F(TileTest, RemoveObject) {
    IObject* food = new Food(Position(0, 0));
    IObject* linemate = new Linemate(Position(0, 0));
    tile.addObject(food);
    tile.addObject(linemate);

    tile.removeObject(food);
    auto objects = tile.getObjects();
    EXPECT_EQ(objects.size(), 1);
    EXPECT_EQ(objects.front(), linemate);

    tile.removeObject(linemate);
    objects = tile.getObjects();
    EXPECT_EQ(objects.size(), 0);

    delete food;
    delete linemate;
}

TEST_F(TileTest, ClearObjects) {
    IObject* food = new Food(Position(0, 0));
    IObject* linemate = new Linemate(Position(0, 0));
    IObject* dera = new Deraumere(Position(0, 0));
    tile.addObject(food);
    tile.addObject(linemate);
    tile.addObject(dera);

    tile.clearObjects();
    auto objects = tile.getObjects();
    EXPECT_EQ(objects.size(), 0);

    delete food;
    delete linemate;
    delete dera;
}

TEST_F(TileTest, CreateObjectByType) {
    IObject* food = tile.createObjectByType(Tile::FOOD, Position(0, 0));
    EXPECT_NE(food, nullptr);
    EXPECT_EQ(food->getType(), Tile::FOOD);
    delete food;

    IObject* linemate = tile.createObjectByType(Tile::LINEMATE, Position(1, 1));
    EXPECT_NE(linemate, nullptr);
    EXPECT_EQ(linemate->getType(), Tile::LINEMATE);
    delete linemate;

    IObject* sibur = tile.createObjectByType(Tile::SIBUR, Position(2, 2));
    EXPECT_NE(sibur, nullptr);
    EXPECT_EQ(sibur->getType(), Tile::SIBUR);
    delete sibur;
}

TEST_F(TileTest, UpdateTileContent_AddObjects) {
    std::vector<std::string> tileContent = {"1", "0", "1", "0", "0", "0", "0"};
    tile.updateTileContent(tileContent);

    auto objects = tile.getObjects();
    EXPECT_EQ(objects.size(), 2);

    int foodCount = 0;
    int deraumerecount = 0;

    for (auto obj : objects) {
        if (obj->getType() == Tile::FOOD) {
            foodCount++;
        } else if (obj->getType() == Tile::DERAUMERE) {
            deraumerecount++;
        }
        delete obj;
    }

    EXPECT_EQ(foodCount, 1);
    EXPECT_EQ(deraumerecount, 1);
}

TEST_F(TileTest, UpdateTileContent_RemoveObjects) {
    IObject* food = new Food(Position(0, 0));
    IObject* linemate = new Linemate(Position(0, 0));
    tile.addObject(food);
    tile.addObject(linemate);

    std::vector<std::string> tileContent = {"0", "0", "0", "0", "0", "0", "0"};
    tile.updateTileContent(tileContent);

    auto objects = tile.getObjects();
    EXPECT_EQ(objects.size(), 0);
}

TEST_F(TileTest, UpdateTileContent_MixedChanges) {
    std::vector<std::string> initialContent = {"0", "1", "1", "0", "0", "0", "0"};
    tile.updateTileContent(initialContent);

    std::list<IObject*> obj = tile.getObjects();
    EXPECT_EQ(obj.size(), 2);

    std::vector<std::string> newContent = {"0", "2", "0", "1", "0", "0", "0"};
    tile.updateTileContent(newContent);

    auto objects = tile.getObjects();
    EXPECT_EQ(objects.size(), 2);
}

TEST_F(TileTest, GetObjects) {
    IObject* food = new Food(Position(0, 0));
    IObject* linemate = new Linemate(Position(0, 0));
    tile.addObject(food);
    tile.addObject(linemate);

    auto objects = tile.getObjects();
    EXPECT_EQ(objects.size(), 2);
    EXPECT_TRUE(std::find(objects.begin(), objects.end(), food) != objects.end());
    EXPECT_TRUE(std::find(objects.begin(), objects.end(), linemate) != objects.end());

    delete food;
    delete linemate;
}
