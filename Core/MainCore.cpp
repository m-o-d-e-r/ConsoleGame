#include "MainCore.h"


std::string Core::GetJson ()
{
    std::fstream OpenJsonFile("player.json");

    std::string t = "";
    std::string text = "";

    while (!OpenJsonFile.eof())
    {
        getline(OpenJsonFile, t);
        if ((t.find("{") == -1) && (t.find("}") == -1))
        {
            for (int i = 0; i < t.length(); i++)
            {
                if (t[i] != ' ')
                    text += t[i];
            }
        }
    }
    return text;
}

std::string Core::GetJson (int marker)
{
    std::fstream OpenJsonFile("bot.json");

    std::string t = "";
    std::string text = "";

    while (!OpenJsonFile.eof())
    {
        getline(OpenJsonFile, t);
        if ((t.find("{") == -1) && (t.find("}") == -1))
        {
            for (int i = 0; i < t.length(); i++)
            {
                if (t[i] != ' ')
                    text += t[i];
            }
        }
    }
    return text;
}

