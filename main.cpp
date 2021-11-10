#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "Core/MainCore.h" // core of the game
#include "Player/player.h"
#include "Bot/bot.h"

#include "settings/settings.hpp"




int main()
{
    srand(time(NULL));

    Core core;
    Player player;
    Bot bot;

    PlayerItems::ItemData iData;

    while (true)
    {
        char userInput;
        core.ColorPrint("Choose what do you want\n\tc - continue\n\tn - new game", 1);
        scanf("\n%c", &userInput);

        system("cls");

        if (userInput == 'c')
        {
            std::string data = core.GetJson();
            std::string botData = core.GetJson(1);

            core.ParseAndSetAttr(player, bot, data, botData, Settings::__dict__);
            std::string str_lst = core.openList();
            core.ParseList(player, str_lst);

            break;
        } else if (userInput == 'n')
        {
            break;
        } else {
            core.ColorPrint("Incorrect choice...", 4);
        }
    }

    while (Settings::RunGame)
    {
        core.ColorPrint("a - atack; d - deffence; i - inventory; s - save game;\nl - get thing into left hand; r - get thing into right hand;", 1);
        core.MainGameLogic(player, bot, iData);

        if ((core.examine(player, bot) == 0))
        {
            int a_chance_for_a_new_thing = rand() % 100;

            if ((a_chance_for_a_new_thing >= 0) && (a_chance_for_a_new_thing <= player.getNewThing()))
            {
                int thing = rand() % 4;

                for (int i = 0; i < 5; i++)
                {
                    player.getPlayeriInventory().leftArm[i] = thing;
                    if (player.getPlayeriInventory().leftArm[i] == 10)
                    {
                        *(player.leftArm_link + i) = thing;
                        break;
                    } else if (player.getPlayeriInventory().rightArm[i] == 10)
                    {
                        *(player.rightArm_link + i) = thing;
                        break;
                    }
                    if (i == 4)
                    {
                        core.ColorPrint("Inventary is full...", 4);
                    }
                }
                core.openInventory(player, iData);
                player.setNewThing(30);
                core.Save(player, bot);
            } else {
                player.setNewThing(player.getNewThing() + 5);
            }

            break;
        }
    }


    return 0;
}
//g++ -g -o main.exe main.cpp Core/MainCore.cpp Bot/bot.cpp Player/player.cpp