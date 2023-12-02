#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Item.h"

class Room {
public:
    Room(const std::string& description);
    ~Room();

    void setExit(const std::string& direction, Room* neighbor);
    void addItem(Item* item);
    void removeItem(Item* item);
    bool hasItem(const std::string& itemName) const;

    std::string getDescription() const;
    Room* getExit(const std::string& direction) const;
    std::map<std::string, Room*> getExits() const;
    std::vector<Item*> getItems() const;

private:
    std::string description;
    std::map<std::string, Room*> exits;
    std::vector<Item*> items;
};

#endif // ROOM_H
