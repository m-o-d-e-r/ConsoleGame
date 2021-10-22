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
            //printf("%c - %c\n", playerAction, botAction);
            //printf("%i - %i\n",    
            //    player.genarateProbability(playerAction),
            //    bot.genarateProbability(botAction)
            //);
            switch (playerAction)
            {
            case  'a':
                if (player.genarateProbability(playerAction) == 111)
                {
                    if (bot.genarateProbability('f') == 100)
                    {
                        player.setHp(-player.getDamage());
                        printf("Bot: has tend of");
                        continue;
                    }

                    if (botAction == 'd')
                    {
                        if (bot.genarateProbability(botAction) == 0)
                        {
                            bot.setHp(-player.getDamage());
                            printf("Player: bang\n");
                        }
                    } else {
                        if (bot.genarateProbability(botAction) == 111)
                        {
                            if (player.genarateProbability('f') == 100)
                            {
                                bot.setHp(-bot.getDamage());
                                printf("Player: has tend of\n");
                            } else {
                                player.setHp(-bot.getDamage());
                                printf("Bot: bang\n");
                            }
                        } else {
                            printf("Bot: try to shoot\n");
                        }
                    }
                } else {
                    printf("Player: try to shoot\n");
                }
                break;
            case 'd':
                if (botAction == 'a')
                {
                    if (bot.genarateProbability(botAction) == 111)
                    {
                        if (player.genarateProbability('f') == 100)
                        {
                            bot.setHp(-bot.getDamage());
                            printf("Player: has tend of\n");
                            continue;
                        } else {
                            player.setHp(-bot.getDamage);
                            printf("Bot: bang\n");
                        }
                    } else {
                        printf("Bot: try to shoot\n");
                    }
                } else {
                    continue;
                }
                break;
            }
        } else {
            printf("Action is wrong\n");
        }
    }

    return 0;
}
//g++ -o main.exe main.cpp Core/MainCore.cpp Bot/bot.cpp Player/player.cpp