#include "player.h"
#include <iostream>

char Player::getAction()
{
    char action;
    scanf("\n%c", &action);
    if ((action == 'a') || (action == 'd') || (action == 's') || (action == 'r') || (action == 'i') || (action == 'l') || (action == 'f'))
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

void Player::setLeft()
{
    int num;

    std::cin >> num;


    if ((num == 0) || (num == 1) || (num == 2) || (num == 3) || (num == 4))
    { 
        if (*(this->leftArm_link + num) != 10)
        {
            *(this->curLeftArm_link) = this->leftArm_link[num];
            this->setDamage(this->getDamage() + this->iData.THINGS_FOR_ARMS_ATTACK[this->leftArm_link[num]]);
            this->leftArm_link[num] = 10;
        } else {
            std::cout << "Inventory is empty..." << std::endl;
        }
    } else {
        std::cout << "Wrong input..." << std::endl;
    }
}

void Player::setRight()
{
    int num;

    std::getchar();
    std::cin >> num;

    if ((num == 0) || (num == 1) || (num == 2) || (num == 3) || (num == 4))
    {
        if (*(this->rightArm_link + num) != 10)
        {
            *(this->curRightArm_link) = this->rightArm_link [num];
            this->setDamage(this->getDamage() + this->iData.THINGS_FOR_ARMS_ATTACK[this->rightArm_link[num]]);
            this->rightArm_link[num] = 10;
        } else {
            std::cout << "Inventory is empty..." << std::endl;
        }
    } else {
        std::cout << "Wrong input..." << std::endl;
    }
}
