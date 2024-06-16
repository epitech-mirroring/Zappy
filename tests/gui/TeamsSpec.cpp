/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TrantorianMethods
*/

#include <gtest/gtest.h>
#include "trantorians/Teams.hpp"
#include "trantorians/Trantorian.hpp"

using namespace GUI;

TEST(TeamsMethods, TeamNameSetterAndGetter) {
    Teams team;
    std::string name = "Epitech";
    team.setName(name);
    EXPECT_EQ(team.getName(), name);
}

TEST(TeamsMethods, AddTrantorianToTeam) {
    Teams team("Epitech");
    Trantorian player1;
    Trantorian player2;

    team.addTrantorian(player1);
    team.addTrantorian(player2);

    std::list<Trantorian> trantorians = team.getTrantorianList();
    EXPECT_EQ(trantorians.size(), 2);
}

TEST(TeamsMethods, GetTrantorianFromTeam) {
    Teams team("Epitech");
    Trantorian player1;
    Trantorian player2;

    team.addTrantorian(player1);
    team.addTrantorian(player2);

    auto trantorians = team.getTrantorianList();
    auto it = trantorians.begin();

    EXPECT_EQ(it->getTeam()->getName(), "Epitech");
    ++it;
    EXPECT_EQ(it->getTeam()->getName(), "Epitech");
}

TEST(TeamsMethods, AddTeamToTeamsList) {
    Teams team1("Epitech");
    Teams team2("Zappy");

    Teams::addTeamToTeamsList(team1);
    Teams::addTeamToTeamsList(team2);

    auto teamsList = Teams::getTeamsList();
    EXPECT_EQ(teamsList.size(), 2);
}

TEST(TeamsMethods, GetTeamByName) {
    Teams team1("Epitech");
    Teams team2("Zappy");

    Teams::addTeamToTeamsList(team1);
    Teams::addTeamToTeamsList(team2);

    Teams* foundTeam = Teams::getTeamByName("Zappy");
    EXPECT_NE(foundTeam, nullptr);
    EXPECT_EQ(foundTeam->getName(), "Zappy");
}

TEST(TeamsMethods, GetNonExistentTeamByName) {
    Teams team1("Epitech");

    Teams::addTeamToTeamsList(team1);

    Teams* foundTeam = Teams::getTeamByName("NonExistent");
    EXPECT_EQ(foundTeam, nullptr);
}

TEST(TeamsMethods, RemoveTrantorianFromTeam) {
    Teams team("Epitech");
    Trantorian player1(1, 1, 1, 1, 1, "Epitech");
    Trantorian player2(2, 1, 1, 1, 1, "Epitech");

    team.addTrantorian(player1);
    team.addTrantorian(player2);

    auto trantorians = team.getTrantorianList();
    trantorians.remove(player1);

    EXPECT_EQ(trantorians.size(), 1);
}

TEST(TeamsMethods, ComplexTrantorianManagement) {
    Teams team("Epitech");
    Trantorian player1;
    Trantorian player2;
    Trantorian player3;

    team.addTrantorian(player1);
    team.addTrantorian(player2);
    team.addTrantorian(player3);

    auto trantorians = team.getTrantorianList();
    EXPECT_EQ(trantorians.size(), 3);

    for (auto& trantorian : trantorians) {
        trantorian.setLevel(5);
        trantorian.setLifetime(100);
        trantorian.setIsAlive(true);
    }

    for (auto& trantorian : trantorians) {
        EXPECT_EQ(trantorian.getLevel(), 5);
        EXPECT_EQ(trantorian.getLifetime(), 100);
        EXPECT_EQ(trantorian.getIsAlive(), true);
    }
}

TEST(TeamsMethods, TeamDefaultName) {
    Teams team;
    EXPECT_EQ(team.getName(), "");
}

TEST(TeamsMethods, TrantorianDefaultTeam) {
    Trantorian player;
    EXPECT_EQ(player.getTeam(), nullptr);
}

TEST(TeamsMethods, AddMultipleTeams) {
    Teams team1("Epitech");
    Teams team2("Zappy");
    Teams team3("Rocket");

    Teams::addTeamToTeamsList(team1);
    Teams::addTeamToTeamsList(team2);
    Teams::addTeamToTeamsList(team3);

    auto teamsList = Teams::getTeamsList();
    EXPECT_EQ(teamsList.size(), 3);
}

TEST(TeamsMethods, ClearTeamsList) {
    Teams team1("Epitech");
    Teams team2("Zappy");

    Teams::addTeamToTeamsList(team1);
    Teams::addTeamToTeamsList(team2);

    auto& teamsList = Teams::getTeamsList();
    teamsList.clear();

    EXPECT_EQ(teamsList.size(), 0);
}

TEST(TeamsMethods, CheckTrantorianTeamAfterAddition) {
    Teams team("Epitech");
    Trantorian player1;

    team.addTrantorian(player1);

    EXPECT_EQ(player1.getTeam()->getName(), "Epitech");
}

TEST(TeamsMethods, AddTrantorianWithDifferentPositions) {
    Teams team("Epitech");
    Trantorian player1, player2, player3;

    player1.setPosition(10, 20);
    player2.setPosition(30, 40);
    player3.setPosition(50, 60);

    team.addTrantorian(player1);
    team.addTrantorian(player2);
    team.addTrantorian(player3);

    auto trantorians = team.getTrantorianList();
    auto it = trantorians.begin();

    EXPECT_EQ(it->getPosition().getX(), 10);
    EXPECT_EQ(it->getPosition().getY(), 20);
    ++it;
    EXPECT_EQ(it->getPosition().getX(), 30);
    EXPECT_EQ(it->getPosition().getY(), 40);
    ++it;
    EXPECT_EQ(it->getPosition().getX(), 50);
    EXPECT_EQ(it->getPosition().getY(), 60);
}

TEST(TeamsMethods, TrantorianAttributesAfterAddition) {
    Teams team("Epitech");
    Trantorian player1;
    player1.setLevel(3);
    player1.setLifetime(200);
    player1.setIsAlive(false);

    team.addTrantorian(player1);

    auto trantorians = team.getTrantorianList();
    auto it = trantorians.begin();

    EXPECT_EQ(it->getLevel(), 3);
    EXPECT_EQ(it->getLifetime(), 200);
    EXPECT_EQ(it->getIsAlive(), false);
}

TEST(TeamsMethods, AddTrantorianWithExistingTeam) {
    Teams team1("Epitech");
    Teams team2("Zappy");
    Trantorian player1;

    team1.addTrantorian(player1);
    EXPECT_EQ(player1.getTeam()->getName(), "Epitech");

    team2.addTrantorian(player1);
    EXPECT_EQ(player1.getTeam()->getName(), "Zappy");
}

TEST(TeamsMethods, VerifyTrantorianListContent) {
    Teams team("Epitech");
    Trantorian player1, player2, player3;

    team.addTrantorian(player1);
    team.addTrantorian(player2);
    team.addTrantorian(player3);

    auto trantorians = team.getTrantorianList();
    EXPECT_NE(std::find(trantorians.begin(), trantorians.end(), player1), trantorians.end());
    EXPECT_NE(std::find(trantorians.begin(), trantorians.end(), player2), trantorians.end());
    EXPECT_NE(std::find(trantorians.begin(), trantorians.end(), player3), trantorians.end());
}

TEST(TeamsMethods, TrantorianNotFoundAfterRemoval) {
    Teams team("Epitech");
    Trantorian player1, player2;

    team.addTrantorian(player1);
    team.addTrantorian(player2);

    auto trantorians = team.getTrantorianList();
    trantorians.remove(player1);

    EXPECT_EQ(std::find(trantorians.begin(), trantorians.end(), player1), trantorians.end());
}

TEST(TeamsMethods, GetTeamsListAfterMultipleAdditions) {
    Teams team1("Epitech");
    Teams team2("Zappy");
    Teams team3("Rocket");

    Teams::addTeamToTeamsList(team1);
    Teams::addTeamToTeamsList(team2);
    Teams::addTeamToTeamsList(team3);

    auto teamsList = Teams::getTeamsList();
    EXPECT_EQ(teamsList.size(), 3);
}

TEST(TeamsMethods, GetTeamsListAfterClear) {
    Teams team1("Epitech");
    Teams team2("Zappy");

    Teams::addTeamToTeamsList(team1);
    Teams::addTeamToTeamsList(team2);

    auto& teamsList = Teams::getTeamsList();
    teamsList.clear();

    EXPECT_EQ(teamsList.size(), 0);
}

TEST(TeamsMethods, FindTeamInEmptyTeamsList) {
    auto& teamsList = Teams::getTeamsList();
    teamsList.clear();

    Teams* foundTeam = Teams::getTeamByName("NonExistent");
    EXPECT_EQ(foundTeam, nullptr);
}

TEST(TeamsMethods, ComplexTeamAndTrantorianInteraction) {
    Teams team1("Epitech");
    Teams team2("Zappy");

    Trantorian player1, player2, player3, player4;

    player1.setId(1);
    player2.setId(2);
    player3.setId(3);
    player4.setId(4);

    team1.addTrantorian(player1);
    team1.addTrantorian(player2);

    team2.addTrantorian(player3);
    team2.addTrantorian(player4);

    auto trantorians1 = team1.getTrantorianList();
    auto trantorians2 = team2.getTrantorianList();

    EXPECT_EQ(trantorians1.size(), 2);
    EXPECT_EQ(trantorians2.size(), 2);

    EXPECT_NE(std::find_if(trantorians1.begin(), trantorians1.end(), [](Trantorian& t) { return t.getId() == 1; }), trantorians1.end());
    EXPECT_NE(std::find_if(trantorians2.begin(), trantorians2.end(), [](Trantorian& t) { return t.getId() == 3; }), trantorians2.end());
}

TEST(TeamsMethods, GetTrantorianById) {
    Teams team1("Epitech");
    Teams team2("Zappy");

    Trantorian player1, player2, player3, player4;

    player1.setId(1);
    player2.setId(2);
    player3.setId(3);
    player4.setId(4);

    team1.addTrantorian(player1);
    team1.addTrantorian(player2);

    team2.addTrantorian(player3);
    team2.addTrantorian(player4);

    Trantorian foundPlayer = team1.getTrantorianById(1);
    EXPECT_EQ(foundPlayer.getId(), 1);
}

TEST(TeamsMethods, GetNonExistentTrantorianById) {
    Teams team1("Epitech");
    Teams team2("Zappy");

    Trantorian player1, player2, player3, player4;

    player1.setId(1);
    player2.setId(2);
    player3.setId(3);
    player4.setId(4);

    team1.addTrantorian(player1);
    team1.addTrantorian(player2);

    team2.addTrantorian(player3);
    team2.addTrantorian(player4);

    Trantorian foundPlayer = team1.getTrantorianById(5);
    EXPECT_EQ(foundPlayer.getId(), -1);
}
