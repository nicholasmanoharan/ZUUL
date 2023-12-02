#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Item.h"

class Player {
public:
    //Initialize the Player's inventory
    Player();

    
    ~Player();

    //Adding an item 
    void addItem(Item* item);

    //Removing an item
    void removeItem(Item* item);

    //Get current inventory
    std::vector<Item*> getInventory() const;

private:
    std::vector<Item*> inventory;  // Member variable to store the player's inventory
};

#endif
