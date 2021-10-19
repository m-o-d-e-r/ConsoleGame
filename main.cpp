#include <stdio.h>

#include "Core/MainCore.h" // core of the game
#include "Player/player.h"
#include "Bot/bot.h"


int main()
{
    MainCycle::Cycle mainCycle;

    mainCycle.RunCycle();


    return 0;
}
// g++ -o main.exe main.cpp Core/MainCore.cpp Bot/bot.cpp Player/player.cpp