#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include "Core/MainCore.h" // core of the game
#include "Player/player.h"
#include "Bot/bot.h"

#include "settings/settings.hpp"


int main()
{
    Core core;
    Player player;
    Bot bot;

    core.examine(player, bot);

    char userInput;
    printf("Choose what do you want\n\tc - continue\n\tn - new game\n");
    scanf("%c", &userInput);


    if (userInput == 'c')
    {
        std::string data = core.GetJson();
        std::string botData = core.GetJson(1);

        core.ParseAndSetAttr(player, bot, data, botData, Settings::__dict__);
    } // если n, то атрибуты будут по молчанию

    while (Settings::RunGame)
    {
        core.MainGameLogic(player, bot);

        if ((core.examine(player, bot) == 0) || (core.examine(player, bot) == 0))
            break;
    }


    return 0;
}
//g++ -o main.exe main.cpp Core/MainCore.cpp Bot/bot.cpp Player/player.cpp