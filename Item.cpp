#include "Item.h"
#include <iostream>

Item::Item(const std::string& itemName) : name(itemName) {}

Item::~Item() {
    std::cout << "Item " << name << " is being destroyed.\n";
}

std::string Item::getName() const {
    return name;
}
