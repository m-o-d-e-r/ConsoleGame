#include "bot.h"

#include <stdlib.h>


char Bot::generateAction ()
{
    switch (0 + rand() % 2)
    {
    case 0:
        return 'a';
    case 1:
        return 'd';
    }

    return 'q';
}

int Bot::genarateProbability(char action)
{
    switch (action)
    {
    case 'a':
        if ((rand() % 100) <= this->getPossibility_of_hit())
            return 111;
        break;
    default:
        if ((rand() % 100) <= this->getPossibility_of_protection())
            return 101;
        break;
    }

    return 0;
}