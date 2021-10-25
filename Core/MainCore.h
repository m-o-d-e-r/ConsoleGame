#include <stdio.h>
#include <string>
#include <fstream>


class Core
{
public:
    template <typename _player, typename _bot>
    void caseA (_player &player, _bot &bot, char &playerAction, char &botAction);
    template <typename _player, typename _bot>
    void caseD (_player &player, _bot &bot, char &playerAction, char &botAction);

    template <typename _player, typename _bot>
    void MainGameLogic (_player &player, _bot &bot)
    {
        char playerAction = player.getAction();

        if (playerAction != 'e')
        {
            char botAction = bot.generateAction();
            switch (playerAction)
            {
            case 'a':
                caseA(player, bot, playerAction, botAction);
                break;
            case 'd':
                caseD(player, bot, playerAction, botAction);
                break;
            case 's': // сохранение, будет доступно только во время игры
                Save(player, bot);
                printf("=== Game is saved ===\n");
                break;
            case 'r': // загрузить игру с .json
                // не будет доступно во время игры
                printf("R\n");
                break;
            }
        } else {
                printf("Action is wrong\n");
            }
    }

    template <typename _player, typename _bot>
    void Save (_player &player, _bot &bot);

    std::string GetJson ();

    template <typename _player, typename _bot, typename _dict>
    void ParseAndSetAttr(_player &player, _bot &bot, std::string &data, _dict &__dict__);
};


template <typename _player, typename _bot>
void Core::caseA(_player &player, _bot &bot, char &playerAction, char &botAction)
{
    if (player.genarateProbability(playerAction) == 111)
    {
        printf("Player: is shooting\n");
        if (bot.genarateProbability('f') == 100)
        {
            player.setHp(-player.getDamage());
            printf("Bot: has tend of\n");
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
}

template <typename _player, typename _bot>
void Core::caseD(_player &player, _bot &bot, char &playerAction, char &botAction)
{
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
    }
}

template <typename _player, typename _bot, typename _dict>
void Core::ParseAndSetAttr(_player &player, _bot &bot, std::string &data, _dict &__dict__)
{
    int i = 0;
    while (i != 8)
    {
        std::string keyValue = data.substr(0, data.find(","));
        keyValue = keyValue.substr(2, keyValue.length());

        std::string name = keyValue.substr(0, keyValue.find('"'));
        int value = std::stoi(keyValue.substr(keyValue.find(":") + 1, keyValue.length()));

        int id_ = __dict__[name];

        switch (id_)
        {
        case 0:
            player.n_setHp(value);
            break;
        case 1:
            player.setExp(value);
            break;
        case 2:
            player.setLevel(value);
            break;
        case 3:
            player.setDamage(value);
            break;
        case 4:
            player.setPossibility_of_hit(value);
            break;
        case 5:
            player.setPossibility_of_protection(value);
            break;
        case 6:
            player.setPossibility_to_fend_off(value);
            break;
        case 7:
            player.setCount_of_batle(value);
            break;
        default:
            break;
        }
//            printf("%s %i\n", name.c_str(), value);

        data = data.substr(data.find(",") + 1, data.length());
        i++;
    }
}


template <typename _player, typename _bot>
void Core::Save (_player &player, _bot &bot)
{
    std::ofstream out;
    out.open("main.json");
    if (out.is_open())
    {
        out << "{" << std::endl;
        out << "\t\"hp\":" << player.getHp() << ","  << std::endl;
        out << "\t\"exp\":0," << std::endl;
        out << "\t\"level\": 20," << std::endl;
        out << "\t\"damage\":10," << std::endl;
        out << "\t\"possibility_of_hit\":50," << std::endl;
        out << "\t\"possibility_of_protection\":50," << std::endl;
        out << "\t\"possibility_to_fend_off\":15," << std::endl;
        out << "\t\"count_of_batle\":0" << std::endl;
        

        out << "}" << std::endl;
    }
}

