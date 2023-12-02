#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    // Constructor to initialize the item with a name
    Item(const std::string& name);

    // Destructor to clean up resources (not needed for this simple class)
    ~Item();

    // Getter function to retrieve the item's name
    std::string getName() const;

private:
    std::string name;  // Member variable to store the item's name
};

#endif
