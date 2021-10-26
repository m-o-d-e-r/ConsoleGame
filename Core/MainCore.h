#pragma once

#include <stdlib.h>
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
    void MainGameLogic (_player &player, _bot &bot);

    template <typename _player, typename _bot>
    int examine(_player &player, _bot &bot);

    template <typename _player, typename _bot>
    void Save (_player &player, _bot &bot);

    std::string GetJson ();
    std::string GetJson (int marker);

    template <typename _player, typename _bot, typename _dict>
    void ParseAndSetAttr(_player &player, _bot &bot, std::string &data, std::string &botData, _dict &__dict__);
};


template <typename _player, typename _bot>
void Core::MainGameLogic (_player &player, _bot &bot)
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
int Core::examine(_player &player, _bot &bot)
{
    if (bot.getHp() <= 0)
    {
        printf("===================================================\n====================You are won====================\n===================================================\n");
        bot.n_setHp(100);
        bot.setLevel(bot.getLevel() + 1);
        bot.setPossibility_of_hit(bot.getPossibility_of_hit() + (0 + rand() % 3));
        bot.setPossibility_of_protection(bot.getPossibility_of_protection() + (0 + rand() % 3));
        bot.setPossibility_to_fend_off(bot.getPossibility_to_fend_off() + (0 + rand() % 3));

        player.n_setHp(100);
        player.setExp(player.getExp() + (0 + rand() % 10));
        player.setLevel(player.getLevel() + 1);
        player.setCount_of_batle(player.getCount_of_batle() + 1);
        Core::Save(player, bot);

        return 0;
    }

    if (player.getHp() <= 0)
    {
        printf("====================================================\n====================You are lose====================\n====================================================\n");

        return 1;
    }
    return -1;
}

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
void Core::ParseAndSetAttr(_player &player, _bot &bot, std::string &data, std::string &botData, _dict &__dict__)
{
    int i = 0;
    while (i != 8)
    {
// тут творится основная магия по парсингу
        std::string keyValue = data.substr(0, data.find(","));
        keyValue = keyValue.substr(2, keyValue.length());

        std::string name = keyValue.substr(0, keyValue.find('"'));
        int value = std::stoi(keyValue.substr(keyValue.find(":") + 1, keyValue.length()));
// надо придумать что-то круче
        std::string botKeyValue = botData.substr(0, botData.find(","));
        botKeyValue = botKeyValue.substr(2, botKeyValue.length());

        std::string botName = botKeyValue.substr(0, botKeyValue.find('"'));
        int botValue = std::stoi(botKeyValue.substr(botKeyValue.find(":") + 1, botKeyValue.length()));
// магия почти закочилась
        int id_   = __dict__[name];
        int id_b  = __dict__[botName];

        // тут нужно оставить один switch(сделаю позже)
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
            player.setPossibility_of_protection(value);
            break;
        case 7:
            player.setCount_of_batle(value);
            break;
        }

        switch (id_b)
        {
        case 0:
            bot.n_setHp(botValue);
            break;
        case 2:
            bot.setLevel(botValue);
            break;
        case 3:
            bot.setDamage(botValue);
            break;
        case 4:
            bot.setPossibility_of_hit(botValue);
            break;
        case 5:
            bot.setPossibility_of_protection(botValue);
            break;
        case 6:
            bot.setPossibility_to_fend_off(botValue);
            break;
        }

        data = data.substr(data.find(",") + 1, data.length());
        botData = botData.substr(botData.find(",") + 1, botData.length());
        i++;
    }
} // конец магии парсера

template <typename _player, typename _bot>
void Core::Save (_player &player, _bot &bot)
{
    // это тоже надо переделать(будет позже)
    std::ofstream out;
    out.open("player.json");
    if (out.is_open())
    {
        printf("%i\n", player.getPossibility_of_protection());
        out << "{" << std::endl;
        out << "\t\"hp\": " << player.getHp() << ","  << std::endl;
        out << "\t\"exp\": " << player.getExp() << "," << std::endl;
        out << "\t\"level\": " << player.getLevel() << "," << std::endl;
        out << "\t\"damage\": " << player.getDamage() << "," << std::endl;
        out << "\t\"possibility_of_hit\": " << player.getPossibility_of_hit() << "," << std::endl;
        out << "\t\"possibility_of_protection\": " << player.getPossibility_of_protection() << "," << std::endl;
        out << "\t\"possibility_to_fend_off\": " << player.getPossibility_to_fend_off() << "," << std::endl;
        out << "\t\"count_of_batle\": " << player.getCount_of_batle() << std::endl;
        out << "}" << std::endl;
    }

    std::ofstream out_; // нужно переделать
    out_.open("bot.json");
    if (out_.is_open())
    {
        out_ << "{" << std::endl;
        out_ << "\t\"hp\": " << bot.getHp() << ","  << std::endl;
        out_ << "\t\"level\": " << bot.getLevel() << "," << std::endl;
        out_ << "\t\"damage\": " << bot.getDamage() << "," << std::endl;
        out_ << "\t\"possibility_of_hit\": " << bot.getPossibility_of_hit() << "," << std::endl;
        out_ << "\t\"possibility_of_protection\": " << bot.getPossibility_of_protection() << "," << std::endl;
        out_ << "\t\"possibility_to_fend_off\": " << bot.getPossibility_to_fend_off() << std::endl;
        out_ << "}" << std::endl;
    }
}

