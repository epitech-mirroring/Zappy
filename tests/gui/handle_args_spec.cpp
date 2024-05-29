/*
** EPITECH PROJECT, 2024
** Zappy [WSL: kali-linux]
** File description:
** hello_world_spec
*/

#include <gtest/gtest.h>
#include "handle_args/HandleArgs.hpp"

using namespace GUI;

TEST(HandleArgsTest, CheckArgsHelp) {
    char *argv[] = { (char*)"./zappy_gui", (char*)"-help" };
    HandleArgs ha;
    int result = ha.checkArgs(2, argv);
    ASSERT_EQ(result, 0);
}

TEST(HandleArgsTest, CheckArgsInvalidNumberOfArgs) {
    char *argv[] = { (char*)"./zappy_gui" };
    HandleArgs ha;
    int result = ha.checkArgs(1, argv);
    ASSERT_EQ(result, 84);
}

TEST(HandleArgsTest, CheckArgsInvalidPort) {
    char *argv[] = { (char*)"./zappy_gui",
        (char*)"invalid_port", (char*)"127.0.0.1" };
    HandleArgs ha;
    int result = ha.checkArgs(3, argv);
    ASSERT_EQ(result, 84);
}

TEST(HandleArgsTest, CheckArgsInvalidHostname) {
    char *argv[] = { (char*)"./zappy_gui", (char*)"1234",
        (char*)"invalid_hostname" };
    HandleArgs ha;
    int result = ha.checkArgs(3, argv);
    ASSERT_EQ(result, 84);
}

TEST(HandleArgsTest, CheckArgsValid) {
    char *argv[] = { (char*)"./zappy_gui", (char*)"1234",
        (char*)"192.168.1.1" };
    HandleArgs ha;
    int result = ha.checkArgs(3, argv);
    ASSERT_EQ(result, 0);
}

TEST(HandleArgsTest, CheckPortValid) {
    HandleArgs ha;
    int result = ha.checkPort("1234");
    ASSERT_EQ(result, 0);
}

TEST(HandleArgsTest, CheckPortInvalid) {
    HandleArgs ha;
    int result = ha.checkPort("invalid_port");
    ASSERT_EQ(result, 84);
}

TEST(HandleArgsTest, CheckPortOutOfRange) {
    HandleArgs ha;
    int result = ha.checkPort("70000");
    ASSERT_EQ(result, 84);
}

TEST(HandleArgsTest, CheckHostnameValid) {
    HandleArgs ha;
    int result = ha.checkHostname("192.168.1.1");
    ASSERT_EQ(result, 0);
}

TEST(HandleArgsTest, CheckHostnameInvalidFormat) {
    HandleArgs ha;
    int result = ha.checkHostname("192.168.1");
    ASSERT_EQ(result, 84);
}

TEST(HandleArgsTest, CheckHostnameInvalidCharacter) {
    HandleArgs ha;
    int result = ha.checkHostname("192.168.1.invalid");
    ASSERT_EQ(result, 84);
}

TEST(HandleArgsTest, CheckHostnameOutOfRange) {
    HandleArgs ha;
    int result = ha.checkHostname("192.168.1.300");
    ASSERT_EQ(result, 84);
}
