#include "player.h"
#include <iostream>

char Player::getAction()
{
    char action;
    std::cin >> action;

    if ((action == 'a') || (action == 'd'))
        return action;

    return 'e';
}

int Player::genarateProbability(char action)
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