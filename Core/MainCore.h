#include <stdio.h>


class Core
{
public:
    void checkPlayerAction();

    template <class _bot, class _player>
    void checkBotAction(_bot &bot, _player &player, char botAction)
    {
        if (botAction == 'd')
        {
            if (bot.genarateProbability(botAction) == 0)
            {
                bot.setHp(-player.getDamage());
                printf("Player: bang\n");
            } else {
                printf("Bot: shield worked\n");
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
    }
};
