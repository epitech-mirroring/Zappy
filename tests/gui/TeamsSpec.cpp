/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** TeamsSpec
*/

#include <gtest/gtest.h>
#include "mocks/MockTrantorians.hpp"
#include "mocks/MockTeams.hpp"

using namespace GUI;

TEST(TeamsMethods, TeamNameSetterAndGetter) {
    MockTeams team;
    std::string name = "Epitech";
    team.setName(name);
    EXPECT_EQ(team.getName(), name);
}

TEST(TeamsMethods, AddTrantorianToTeam) {
    MockTeams team("Epitech");
    MockTrantorians player1;
    MockTrantorians player2;

    team.addMockTrantorians(player1);
    team.addMockTrantorians(player2);

    std::list<MockTrantorians> trantorians = team.getMockTrantoriansList();
    EXPECT_EQ(trantorians.size(), 2);
}

TEST(TeamsMethods, GetTrantorianFromTeam) {
    MockTeams team("Epitech");
    MockTrantorians player1;
    MockTrantorians player2;

    team.addMockTrantorians(player1);
    team.addMockTrantorians(player2);

    auto trantorians = team.getMockTrantoriansList();
    auto it = trantorians.begin();

    EXPECT_EQ(it->getTeam()->getName(), "Epitech");
    ++it;
    EXPECT_EQ(it->getTeam()->getName(), "Epitech");
}

TEST(TeamsMethods, AddTeamToTeamsList) {
    MockTeams team1("Epitech");
    MockTeams team2("Zappy");

    MockTeams::addMockTeamToMockTeamsList(team1);
    MockTeams::addMockTeamToMockTeamsList(team2);

    auto teamsList = MockTeams::getMockTeamsList();
    EXPECT_EQ(teamsList.size(), 2);
}

TEST(TeamsMethods, GetTeamByName) {
    MockTeams team1("Epitech");
    MockTeams team2("Zappy");

    MockTeams::addMockTeamToMockTeamsList(team1);
    MockTeams::addMockTeamToMockTeamsList(team2);

    MockTeams* foundTeam = MockTeams::getTeamByName("Zappy");
    EXPECT_NE(foundTeam, nullptr);
    EXPECT_EQ(foundTeam->getName(), "Zappy");
}

TEST(TeamsMethods, GetNonExistentTeamByName) {
    MockTeams team1("Epitech");

    MockTeams::addMockTeamToMockTeamsList(team1);

    MockTeams* foundTeam = MockTeams::getTeamByName("NonExistent");
    EXPECT_EQ(foundTeam, nullptr);
}

TEST(TeamsMethods, RemoveTrantorianFromTeam) {
    MockTeams team("Epitech");
    MockTrantorians player1("1", 1, 1, 1, 1, "Epitech");
    MockTrantorians player2("2", 1, 1, 1, 1, "Epitech");

    team.addMockTrantorians(player1);
    team.addMockTrantorians(player2);

    auto trantorians = team.getMockTrantoriansList();
    trantorians.remove(player1);

    EXPECT_EQ(trantorians.size(), 1);
}

TEST(TeamsMethods, ComplexTrantorianManagement) {
    MockTeams team("Epitech");
    MockTrantorians player1;
    MockTrantorians player2;
    MockTrantorians player3;

    team.addMockTrantorians(player1);
    team.addMockTrantorians(player2);
    team.addMockTrantorians(player3);

    auto trantorians = team.getMockTrantoriansList();
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
    MockTeams team;
    EXPECT_EQ(team.getName(), "");
}

TEST(TeamsMethods, TrantorianDefaultTeam) {
    MockTrantorians player;
    EXPECT_EQ(player.getTeam(), nullptr);
}

TEST(TeamsMethods, AddMultipleTeams) {
    MockTeams team1("Epitech");
    MockTeams team2("Zappy");
    MockTeams team3("Rocket");

    MockTeams::addMockTeamToMockTeamsList(team1);
    MockTeams::addMockTeamToMockTeamsList(team2);
    MockTeams::addMockTeamToMockTeamsList(team3);

    auto teamsList = MockTeams::getMockTeamsList();
    EXPECT_EQ(teamsList.size(), 3);
}

TEST(TeamsMethods, ClearTeamsList) {
    MockTeams team1("Epitech");
    MockTeams team2("Zappy");

    MockTeams::addMockTeamToMockTeamsList(team1);
    MockTeams::addMockTeamToMockTeamsList(team2);

    auto& teamsList = MockTeams::getMockTeamsList();
    teamsList.clear();

    EXPECT_EQ(teamsList.size(), 0);
}

TEST(TeamsMethods, CheckTrantorianTeamAfterAddition) {
    MockTeams team("Epitech");
    MockTrantorians player1;

    team.addMockTrantorians(player1);

    EXPECT_EQ(player1.getTeam()->getName(), "Epitech");
}

TEST(TeamsMethods, AddTrantorianWithDifferentPositions) {
    MockTeams team("Epitech");
    MockTrantorians player1, player2, player3;

    player1.setPosition(10, 20);
    player2.setPosition(30, 40);
    player3.setPosition(50, 60);

    team.addMockTrantorians(player1);
    team.addMockTrantorians(player2);
    team.addMockTrantorians(player3);

    auto trantorians = team.getMockTrantoriansList();
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
    MockTeams team("Epitech");
    MockTrantorians player1;
    player1.setLevel(3);
    player1.setLifetime(200);
    player1.setIsAlive(false);

    team.addMockTrantorians(player1);

    auto trantorians = team.getMockTrantoriansList();
    auto it = trantorians.begin();

    EXPECT_EQ(it->getLevel(), 3);
    EXPECT_EQ(it->getLifetime(), 200);
    EXPECT_EQ(it->getIsAlive(), false);
}

TEST(TeamsMethods, AddTrantorianWithExistingTeam) {
    MockTeams team1("Epitech");
    MockTeams team2("Zappy");
    MockTrantorians player1;

    team1.addMockTrantorians(player1);
    EXPECT_EQ(player1.getTeam()->getName(), "Epitech");

    team2.addMockTrantorians(player1);
    EXPECT_EQ(player1.getTeam()->getName(), "Zappy");
}

TEST(TeamsMethods, VerifyTrantorianListContent) {
    MockTeams team("Epitech");
    MockTrantorians player1, player2, player3;

    team.addMockTrantorians(player1);
    team.addMockTrantorians(player2);
    team.addMockTrantorians(player3);

    auto trantorians = team.getMockTrantoriansList();
    EXPECT_NE(std::find(trantorians.begin(), trantorians.end(), player1), trantorians.end());
    EXPECT_NE(std::find(trantorians.begin(), trantorians.end(), player2), trantorians.end());
    EXPECT_NE(std::find(trantorians.begin(), trantorians.end(), player3), trantorians.end());
}

TEST(TeamsMethods, TrantorianNotFoundAfterRemoval) {
    MockTeams team("Epitech");
    MockTrantorians player1, player2;

    team.addMockTrantorians(player1);
    team.addMockTrantorians(player2);

    auto trantorians = team.getMockTrantoriansList();
    trantorians.remove(player1);

    EXPECT_EQ(std::find(trantorians.begin(), trantorians.end(), player1), trantorians.end());
}

TEST(TeamsMethods, GetTeamsListAfterMultipleAdditions) {
    MockTeams team1("Epitech");
    MockTeams team2("Zappy");
    MockTeams team3("Rocket");

    MockTeams::addMockTeamToMockTeamsList(team1);
    MockTeams::addMockTeamToMockTeamsList(team2);
    MockTeams::addMockTeamToMockTeamsList(team3);

    auto teamsList = MockTeams::getMockTeamsList();
    EXPECT_EQ(teamsList.size(), 3);
}

TEST(TeamsMethods, GetTeamsListAfterClear) {
    MockTeams team1("Epitech");
    MockTeams team2("Zappy");

    MockTeams::addMockTeamToMockTeamsList(team1);
    MockTeams::addMockTeamToMockTeamsList(team2);

    auto& teamsList = MockTeams::getMockTeamsList();
    teamsList.clear();

    EXPECT_EQ(teamsList.size(), 0);
}

TEST(TeamsMethods, FindTeamInEmptyTeamsList) {
    auto& teamsList = MockTeams::getMockTeamsList();
    teamsList.clear();

    MockTeams* foundTeam = MockTeams::getTeamByName("NonExistent");
    EXPECT_EQ(foundTeam, nullptr);
}

TEST(TeamsMethods, ComplexTeamAndTrantorianInteraction) {
    MockTeams team1("Epitech");
    MockTeams team2("Zappy");

    MockTrantorians player1, player2, player3, player4;

    player1.setId("1");
    player2.setId("2");
    player3.setId("3");
    player4.setId("4");

    team1.addMockTrantorians(player1);
    team1.addMockTrantorians(player2);

    team2.addMockTrantorians(player3);
    team2.addMockTrantorians(player4);

    auto trantorians1 = team1.getMockTrantoriansList();
    auto trantorians2 = team2.getMockTrantoriansList();

    EXPECT_EQ(trantorians1.size(), 2);
    EXPECT_EQ(trantorians2.size(), 2);

    EXPECT_NE(std::find_if(trantorians1.begin(), trantorians1.end(), [](MockTrantorians& t) { return t.getId() == "1"; }), trantorians1.end());
    EXPECT_NE(std::find_if(trantorians2.begin(), trantorians2.end(), [](MockTrantorians& t) { return t.getId() == "3"; }), trantorians2.end());
}

TEST(TeamsMethods, GetTrantorianById) {
    MockTeams team1("Epitech");
    MockTeams team2("Zappy");

    MockTrantorians player1, player2, player3, player4;

    player1.setId("1");
    player2.setId("2");
    player3.setId("3");
    player4.setId("4");

    team1.addMockTrantorians(player1);
    team1.addMockTrantorians(player2);

    team2.addMockTrantorians(player3);
    team2.addMockTrantorians(player4);

    MockTrantorians foundPlayer = team1.getMockTrantoriansById("1");
    EXPECT_EQ(foundPlayer.getId(), "1");
}

TEST(TeamsMethods, GetNonExistentTrantorianById) {
    MockTeams team1("Epitech");
    MockTeams team2("Zappy");

    MockTrantorians player1, player2, player3, player4;

    player1.setId("1");
    player2.setId("2");
    player3.setId("3");
    player4.setId("4");

    team1.addMockTrantorians(player1);
    team1.addMockTrantorians(player2);

    team2.addMockTrantorians(player3);
    team2.addMockTrantorians(player4);

    MockTrantorians foundPlayer = team1.getMockTrantoriansById("5");
    EXPECT_EQ(foundPlayer.getId(), "null");
}
