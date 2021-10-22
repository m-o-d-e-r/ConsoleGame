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
            switch (playerAction)
            {
            case 'a':
                if (player.genarateProbability(playerAction) == 111)
                {
                    printf("Player: is shooting\n");
                    if (bot.genarateProbability('f') == 100)
                    {
                        player.setHp(-player.getDamage());
                        printf("Bot: has tend of\n");
                        continue;
                    } else {
                        if (botAction == 'd')
                        {
                            printf("Bot: took the shield\n");
                            if (bot.genarateProbability(botAction) == 0)
                            {
                                bot.setHp(-player.getDamage());
                                printf("Bot: shield does not work\n");
                                printf("Player: bang\n");
                            } else {
                                printf("Bot: shield worked\n");
                            }
                        } else {
                            printf("Player: bang\n");
                            printf("Bot: is shooting\n");
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
                                printf("Bot: tried to shoot\n");
                            }
                        }
                    }
                } else {
                    printf("Player: tried to shoot\n");
                    if (botAction == 'd')
                    {
                        printf("Bot: took the shield\n");
                    } else {
                        if (bot.genarateProbability(botAction) == 111)
                        {
                            printf("Bot: is shooting\n");
                            if (player.genarateProbability('f') == 100)
                            {
                                bot.setHp(-bot.getDamage());
                                printf("Player: has tend of\n");
                            } else {
                                player.setHp(-bot.getDamage());
                                printf("Bot: bang\n");
                            }
                        } else {
                            printf("Bot: tried to shoot\n");
                        }
                    }

                }
                break;
            case 'd':
                printf("Player: took the shield\n");
                if (botAction == 'a')
                {
                    if (bot.genarateProbability(botAction) == 111)
                    {
                        printf("Bot: is shooting\n");
                        if (player.genarateProbability('f') == 100)
                        {
                            bot.setHp(-bot.getDamage());
                            printf("Player: has tend of\n");
                            continue;
                        } else {
                            if (player.genarateProbability(botAction) == 101)
                            {
                                printf("Player: shield worked\n");
                            } else {
                                printf("Player: shield does not work\n");
                                player.setHp(-bot.getDamage());
                                printf("Bot: bang\n");
                            }
                        }
                    } else {
                        printf("Bot: try to shoot\n");
                    }
                } else {
                    printf("Bot: took the shield\n");
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