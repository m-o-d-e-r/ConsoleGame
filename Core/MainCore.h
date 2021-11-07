#pragma once

#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <Windows.h>


class Core
{
public:
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    template <typename _player, typename _bot>
    void caseA (_player &player, _bot &bot, char &playerAction, char &botAction);
    template <typename _player, typename _bot>
    void caseD (_player &player, _bot &bot, char &playerAction, char &botAction);

    template <typename _player, typename _bot, typename _i_data>
    void MainGameLogic (_player &player, _bot &bot, _i_data &iData);

    template <typename _player, typename _bot>
    int examine(_player &player, _bot &bot);

    template <typename _player, typename _bot>
    void Save (_player &player, _bot &bot);

    template <typename _player, typename _i_data>
    void openInventory (_player &player, _i_data &iData);

    std::string GetJson ();
    std::string GetJson (int marker);

    template <typename _player, typename _bot, typename _dict>
    void ParseAndSetAttr(_player &player, _bot &bot, std::string &data, std::string &botData, _dict &__dict__);

    void ColorPrint(std::string message, int color);
};

template <typename _player, typename _bot, typename _i_data>
void Core::MainGameLogic (_player &player, _bot &bot, _i_data &iData)
{
    char playerAction = player.getAction();

    if (playerAction != 'e')
    {
        char botAction = bot.generateAction();
        switch (playerAction)
        {
        case 'a':
            this->caseA(player, bot, playerAction, botAction);
            break;
        case 'd':
            this->caseD(player, bot, playerAction, botAction);
            break;
        case 's':
            this->Save(player, bot);
            this->ColorPrint("=== Game is saved ===", 2);
            break;
        case 'i':
            this->openInventory(player, iData);
            break;
        }
    } else {
            this->ColorPrint("Action is wrong", 4);
        }
}

template <typename _player, typename _bot>
int Core::examine(_player &player, _bot &bot)
{
    if (bot.getHp() <= 0)
    {
        this->ColorPrint("===================================================\n====================You are won====================\n===================================================", 2);
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
        this->ColorPrint("====================================================\n====================You are lose====================\n====================================================", 4);
        return 1;
    }
    return -1;
}

template <typename _player, typename _bot>
void Core::caseA(_player &player, _bot &bot, char &playerAction, char &botAction)
{
    if (player.genarateProbability(playerAction) == 111)
    {
        this->ColorPrint("Player: is shooting", 3);
        if (bot.genarateProbability('f') == 100)
        {
            player.setHp(-player.getDamage());
            this->ColorPrint("Bot: has tend of", 3);
        } else {
            if (botAction == 'd')
            {
                this->ColorPrint("Bot: took the shield", 3);
                if (bot.genarateProbability(botAction) == 0)
                {
                    bot.setHp(-player.getDamage());
                    this->ColorPrint("Bot: shield does not work", 3);
                    this->ColorPrint("Player: bang", 3);
                } else {
                    this->ColorPrint("Bot: shield worked", 3);
                }
            } else {
                this->ColorPrint("Player: bang", 3);
                this->ColorPrint("Bot: is shooting", 3);
                if (bot.genarateProbability(botAction) == 111)
                {
                    if (player.genarateProbability('f') == 100)
                    {
                        bot.setHp(-bot.getDamage());
                        this->ColorPrint("Player: has tend of", 3);
                    } else {
                        player.setHp(-bot.getDamage());
                        this->ColorPrint("Bot: bang", 3);
                    }
                } else {
                    this->ColorPrint("Bot: tried to shoot", 3);
                }
            }
        }
    } else {
        this->ColorPrint("Player: tried to shoot", 3);
        if (botAction == 'd')
        {
            this->ColorPrint("Bot: took the shield", 3);
        } else {
            if (bot.genarateProbability(botAction) == 111)
            {
                this->ColorPrint("Bot: is shooting", 3);
                if (player.genarateProbability('f') == 100)
                {
                    bot.setHp(-bot.getDamage());
                    this->ColorPrint("Player: has tend of", 3);
                } else {
                    player.setHp(-bot.getDamage());
                    this->ColorPrint("Bot: bang", 3);
                }
            } else {
                this->ColorPrint("Bot: tried to shoot", 3);
            }
        }

    }
}

template <typename _player, typename _bot>
void Core::caseD(_player &player, _bot &bot, char &playerAction, char &botAction)
{
    this->ColorPrint("Player: took the shield", 3);
    if (botAction == 'a')
    {
        if (bot.genarateProbability(botAction) == 111)
        {
            this->ColorPrint("Bot: is shooting", 3);
            if (player.genarateProbability('f') == 100)
            {
                bot.setHp(-bot.getDamage());
                this->ColorPrint("Player: has tend of", 3);
            } else {
                if (player.genarateProbability(botAction) == 101)
                {
                    this->ColorPrint("Player: shield worked", 3);
                } else {
                    this->ColorPrint("Player: shield does not work", 3);
                    player.setHp(-bot.getDamage());
                    this->ColorPrint("Bot: bang", 3);
                }
            }
        } else {
            this->ColorPrint("Bot: try to shoot", 3);
        }
    } else {
        this->ColorPrint("Bot: took the shield", 3);
    }
}

template <typename _player, typename _i_data>
void Core::openInventory (_player &player, _i_data &iData)
{
    this->ColorPrint("=============================\n==========Inventory==========\n=============================\n", 2);
    SetConsoleTextAttribute(this->hConsole, 2);

    std::cout.width(15);
    std::cout.fill(' ');    
    std::cout << "Left arm";

    std::cout.width(15);
    std::cout.fill(' ');
    std::cout << "Right arm" << std::endl << std::endl;;
    for (int i = 0; i < 5; i++)
    {
        std::cout.width(10);
        std::cout.fill(' ');

        std::cout << iData.NAME_OF_THINGS_FOR_ATTACK[player.getPlayeriInventory().leftArm[i]].c_str();

        std::cout.width(20);
        std::cout.fill(' ');

        std::cout << iData.NAME_OF_THINGS_FOR_ATTACK[player.getPlayeriInventory().rightArm[i]].c_str() << std::endl;
    }

    SetConsoleTextAttribute(this->hConsole, 7);
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
    this->ColorPrint("Data read successfully...", 1);
} // конец магии парсера

template <typename _player, typename _bot>
void Core::Save (_player &player, _bot &bot)
{
    // это тоже надо переделать(будет позже)
    std::ofstream out;
    out.open("player.json");
    if (out.is_open())
    {
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

