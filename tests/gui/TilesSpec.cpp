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

TEST(TileMethods, GetPosition) {
    Position pos(10, 20);
    Tile tile(pos);
    EXPECT_EQ(tile.getPosition().getX(), 10);
    EXPECT_EQ(tile.getPosition().getY(), 20);
}

TEST(TileMethods, AddObject) {
    Position pos(0, 0);
    Tile tile(pos);
    IObject* food = new Food(pos);
    tile.addObject(food);
    auto objects = tile.getObjects();
    EXPECT_EQ(objects.size(), 1);
    EXPECT_EQ(objects.front(), food);
    delete food;
}

TEST(TileMethods, RemoveObject) {
    Position pos(0, 0);
    Tile tile(pos);
    IObject* food = new Food(pos);
    tile.addObject(food);
    tile.removeObject(food);
    auto objects = tile.getObjects();
    EXPECT_EQ(objects.size(), 0);
    delete food;
}

TEST(TileMethods, ClearObjects) {
    Position pos(0, 0);
    Tile tile(pos);
    IObject* food = new Food(pos);
    IObject* linemate = new Linemate(pos);
    tile.addObject(food);
    tile.addObject(linemate);
    tile.clearObjects();
    auto objects = tile.getObjects();
    EXPECT_EQ(objects.size(), 0);
    delete food;
    delete linemate;
}

TEST(TileMethods, CreateObjectByType) {
    Position pos(0, 0);
    Tile tile(pos);
    IObject* food = tile.createObjectByType(Tile::FOOD, pos);
    EXPECT_EQ(food->getType(), 0);
    delete food;

    IObject* linemate = tile.createObjectByType(Tile::LINEMATE, pos);
    EXPECT_EQ(linemate->getType(), 1);
    delete linemate;
}

TEST(TileMethods, UpdateTileContent_AddObjects) {
    Position pos(0, 0);
    Tile tile(pos);
    std::string content = "1 2 0 0 0 0 0";
    tile.updateTileContent(content);

    auto objects = tile.getObjects();
    std::unordered_map<int, int> countMap;
    for (auto& obj : objects) {
        countMap[obj->getType()]++;
    }

    EXPECT_EQ(countMap[0], 1);
    EXPECT_EQ(countMap[1], 2);
    EXPECT_EQ(countMap[2], 0);
}

TEST(TileMethods, UpdateTileContent_RemoveObjects) {
    Position pos(0, 0);
    Tile tile(pos);
    IObject* food = new Food(pos);
    IObject* linemate1 = new Linemate(pos);
    IObject* linemate2 = new Linemate(pos);
    tile.addObject(food);
    tile.addObject(linemate1);
    tile.addObject(linemate2);

    std::string content = "1 1 0 0 0 0 0";
    tile.updateTileContent(content);

    auto objects = tile.getObjects();
    std::unordered_map<int, int> countMap;
    for (auto& obj : objects) {
        countMap[obj->getType()]++;
    }

    EXPECT_EQ(countMap[0], 1);
    EXPECT_EQ(countMap[1], 1);
    EXPECT_EQ(countMap[2], 0);

    for (auto& obj : objects) {
        delete obj;
    }
}

TEST(TileMethods, GetObjects_EmptyTile) {
    Position pos(0, 0);
    Tile tile(pos);
    auto objects = tile.getObjects();
    EXPECT_EQ(objects.size(), 0);
}

TEST(TileMethods, AddAndRemoveMultipleObjects) {
    Position pos(0, 0);
    Tile tile(pos);
    IObject* food = new Food(pos);
    IObject* linemate = new Linemate(pos);
    IObject* deraumere = new Deraumere(pos);

    tile.addObject(food);
    tile.addObject(linemate);
    tile.addObject(deraumere);
    tile.removeObject(linemate);

    auto objects = tile.getObjects();
    EXPECT_EQ(objects.size(), 2);
    EXPECT_NE(std::find(objects.begin(), objects.end(), food), objects.end());
    EXPECT_EQ(std::find(objects.begin(), objects.end(), linemate), objects.end());
    EXPECT_NE(std::find(objects.begin(), objects.end(), deraumere), objects.end());

    delete food;
    delete linemate;
    delete deraumere;
}

TEST(TileMethods, ClearObjects_MultipleCalls) {
    Position pos(0, 0);
    Tile tile(pos);
    IObject* food = new Food(pos);
    IObject* linemate = new Linemate(pos);

    tile.addObject(food);
    tile.addObject(linemate);
    tile.clearObjects();
    tile.clearObjects();

    auto objects = tile.getObjects();
    EXPECT_EQ(objects.size(), 0);

    delete food;
    delete linemate;
}
