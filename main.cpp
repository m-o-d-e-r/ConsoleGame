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

    char userInput;
    printf("Choose what do you want\n\tc - continue\n\tn - new game\n");
    scanf("%c", &userInput);


    if (userInput == 'c')
    {
        std::string data = core.GetJson();

        core.ParseAndSetAttr(player, bot, data, Settings::__dict__);
    } // если n, то атрибуты будут по молчанию

    printf("-%i-\n", player.getHp());

    while (Settings::RunGame)
    {
        core.MainGameLogic(player, bot);
    }


    return 0;
}
//g++ -o main.exe main.cpp Core/MainCore.cpp Bot/bot.cpp Player/player.cpp