#include "Game.h"
#include<cstdlib> 
#include <ctime>

int main () {

    srand(static_cast<unsigned>(time(nullptr)));

    Game game;
    game.play();

    return 0;

}
