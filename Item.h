#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(const std::string& name);
    ~Item();

    std::string getName() const;

private:
    std::string name;
};

#endif 
