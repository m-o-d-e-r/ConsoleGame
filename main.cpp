#include <stdio.h>
#include <stdlib.h>

#include "Core/MainCore.h" // core of the game
#include "Player/player.h"
#include "Bot/bot.h"

#include "settings/settings.hpp"


int main()
{
    Player player;
    Bot bot;

    while (Settings::RunGame)
    {
        char playerAction = player.getAction();

        if (playerAction != 'e')
        {
            char botAction = bot.generateAction();
            printf("%c - %c\n", playerAction, botAction);
            printf(
                "Probability ->  %i - %i\n",
                player.genarateProbability(playerAction),
                bot.genarateProbability(botAction)
            );

//            printf("%i\n", player.genarateProbability(playerAction));
        } else {
            printf("Action is wrong\n");
        }
    }

    return 0;
}
//g++ -o main.exe main.cpp Core/MainCore.cpp Bot/bot.cpp Player/player.cpp