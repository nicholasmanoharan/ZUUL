#ifndef GAME_H
#define GAME_H

#include "Room.h"
#include "Player.h"

class Game {
public:
    Game();
    ~Game();

    void play();

private:
    Room* currentPlayerRoom;
    Player* player;
    std::vector<Room*> rooms;
};

#endif // GAME_H
