#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Item.h"

class Player {
public:
    Player();
    ~Player();

    void addItem(Item* item);
    void removeItem(Item* item);
    std::vector<Item*> getInventory() const;

private:
    std::vector<Item*> inventory;
};

#endif 
