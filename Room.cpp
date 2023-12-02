#include "Room.h"

Room::Room(const std::string& desc) : description(desc) {}

Room::~Room() {
    for (auto item : items) {
        delete item;
    }
}

void Room::setExit(const std::string& direction, Room* neighbor) {
    exits[direction] = neighbor;
}

void Room::addItem(Item* item) {
    items.push_back(item);
}

void Room::removeItem(Item* item) {
    items.erase(std::remove(items.begin(), items.end(), item), items.end());
}

bool Room::hasItem(const std::string& itemName) const {
    for (const auto& item : items) {
        if (item->getName() == itemName) {
            return true;
        }
    }
    return false;
}

std::string Room::getDescription() const {
    return description;
}

Room* Room::getExit(const std::string& direction) const {
    auto it = exits.find(direction);
    return (it != exits.end()) ? it->second : nullptr;
}

std::map<std::string, Room*> Room::getExits() const {
    return exits;
}

std::vector<Item*> Room::getItems() const {
    return items;
}
