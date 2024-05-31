/*
** File description:
** GUI-main
*/

#include <iostream>
#include "handle_args/HandleArgs.hpp"

using namespace GUI;

int main(int ac, char **av)
{
    GUI::HandleArgs args;

    if (args.checkArgs(ac, av))
        return 84;
    return 0;
}
