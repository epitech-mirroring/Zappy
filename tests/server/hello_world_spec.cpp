/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include <gtest/gtest.h>
#include "server.h"

TEST(HelloWorldTest, HelloWorldTest)
{
    testing::internal::CaptureStdout();
    hello_world();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Hello, World!\n");
}
