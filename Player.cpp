#include "Player.h"
#include <algorithm>

Player::Player() {}

Player::~Player() {
    for (auto item : inventory) {
        delete item;
    }
}

void Player::addItem(Item* item) {
    inventory.push_back(item);
}

void Player::removeItem(Item* item) {
    inventory.erase(std::remove(inventory.begin(), inventory.end(), item), inventory.end());
}

std::vector<Item*> Player::getInventory() const {
    return inventory;
}
