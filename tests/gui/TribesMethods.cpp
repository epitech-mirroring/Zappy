/*
** File description:
** trantorian_methods tests
*/

#include <gtest/gtest.h>
#include "trantorians/Tribes.hpp"
#include "trantorians/Trantorian.hpp"

using namespace GUI;

TEST(TribesTest, SetNameAndGetName) {
    Tribes tribe;
    std::string name = "TribeName";

    tribe.setName(name);
    EXPECT_EQ(tribe.getName(), name);
}

TEST(TribesTest, AddAndGetTrantorian) {
    Tribes tribe;
    Trantorian trantorian1;
    Trantorian trantorian2;

    tribe.addTrantorian(trantorian1);
    tribe.addTrantorian(trantorian2);

    std::list<Trantorian> trantorians = tribe.getTrantorianList();
    ASSERT_EQ(trantorians.size(), 2);
}

TEST(tribes_methods, GetTrantorianListEmpty) {
    Tribes tribe;
    std::list<Trantorian> trantorians = tribe.getTrantorianList();

    ASSERT_TRUE(trantorians.empty());
}

TEST(TribesTest, AddTrantorianAndCheckDetails) {
    Tribes tribe;
    Trantorian trantorian;
    trantorian.setTeam("TeamA");
    trantorian.setLevel(5);

    tribe.addTrantorian(trantorian);
    std::list<Trantorian> trantorians = tribe.getTrantorianList();

    ASSERT_EQ(trantorians.size(), 1);
    EXPECT_EQ(trantorians.front().getTeam(), "TeamA");
    EXPECT_EQ(trantorians.front().getLevel(), 5);
}

TEST(TribesTest, SetNameEmpty) {
    Tribes tribe;
    std::string name = "";

    tribe.setName(name);
    EXPECT_EQ(tribe.getName(), name);
}

TEST(TribesTest, AddTrantorianToMultipleTribes) {
    Tribes tribe1;
    Tribes tribe2;
    Trantorian trantorian;

    tribe1.addTrantorian(trantorian);
    tribe2.addTrantorian(trantorian);

    ASSERT_EQ(tribe1.getTrantorianList().size(), 1);
    ASSERT_EQ(tribe2.getTrantorianList().size(), 1);
}
