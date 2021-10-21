#include "bot.h"

#include <stdlib.h>
#include <iostream>

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
    case 'd':
        if ((rand() % 100) <= this->getPossibility_of_protection())
            return 101;
        break;
    default:
        if ((rand() % 100) <= this->getPossibility_to_fend_off())
            return 100;
        break;
    }

    return 0;
}