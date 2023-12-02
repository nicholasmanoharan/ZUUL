// Game.cpp
#include "Game.h"
#include <cstdlib>  // for rand function
#include <ctime>    // for time function

Game::Game() {
    // Initialize the game
    for (int i = 0; i < 15; ++i) {
        rooms.push_back(new Room("Room " + std::to_string(i + 1)));
    }

    // Going in between rooms
    rooms[0]->setExit("East", rooms[1]);
    rooms[0]->setExit("South", rooms[5]);
    rooms[1]->setExit("West", rooms[0]);
    rooms[1]->setExit("South", rooms[2]);
    rooms[2]->setExit("North", rooms[1]);
    rooms[2]->setExit("South", rooms[3]);
    rooms[3]->setExit("North", rooms[2]);
    rooms[3]->setExit("East", rooms[4]);
    rooms[4]->setExit("West", rooms[3]);
    rooms[4]->setExit("South", rooms[9]);
    rooms[5]->setExit("North", rooms[0]);
    rooms[5]->setExit("South", rooms[10]);
    rooms[6]->setExit("North", rooms[5]);
    rooms[6]->setExit("South", rooms[7]);
    rooms[7]->setExit("North", rooms[6]);
    rooms[7]->setExit("South", rooms[8]);
    rooms[7]->setExit("East", rooms[12]);
    rooms[8]->setExit("West", rooms[7]);
    rooms[8]->setExit("East", rooms[9]);
    rooms[9]->setExit("West", rooms[8]);
    rooms[9]->setExit("South", rooms[14]);
    rooms[10]->setExit("North", rooms[5]);
    rooms[10]->setExit("South", rooms[11]);
    rooms[11]->setExit("North", rooms[10]);
    rooms[11]->setExit("South", rooms[12]);
    rooms[12]->setExit("North", rooms[11]);
    rooms[12]->setExit("South", rooms[13]);
    rooms[13]->setExit("North", rooms[12]);
    rooms[13]->setExit("East", rooms[14]);
    rooms[14]->setExit("West", rooms[13]);
    rooms[14]->setExit("South", rooms[15]);
    rooms[15]->setExit("North", rooms[14]);

    currentPlayerRoom = rooms[0]; // Start the player in the first room

    // Add items to random rooms
    const std::vector<std::string> itemNames = {"broom", "pencil", "eraser", "phone", "laptop"};
    for (int i = 0; i < 5; ++i) {
        int randomRoomIndex = rand() % 15;
        rooms[randomRoomIndex]->addItem(new Item(itemNames[i]));
    }

    player = new Player();
}

Game::~Game() {
    for (auto room : rooms) {
        delete room;
    }
    delete player;
}

void Game::play() {
    int collectedItems = 0;  // Added variable to count collected items

    // Game loop
    while (true) {
        // Print current room description
        std::cout << "You are in " << currentPlayerRoom->getDescription() << ".\n";

        // Print exits
        std::cout << "Exits:";
        for (const auto& exit : currentPlayerRoom->getExits()) {
            std::cout << " " << exit.first;
        }
        std::cout << "\n";

        // Print items in the room
        auto items = currentPlayerRoom->getItems();
        if (!items.empty()) {
            std::cout << "Items in the room:";
            for (const auto& item : items) {
                std::cout << " " << item->getName();
            }
            std::cout << "\n";
        }

        // Print items in the player's inventory
        auto inventory = player->getInventory();
        if (!inventory.empty()) {
            std::cout << "Your inventory:";
            for (const auto& item : inventory) {
                std::cout << " " << item->getName();
            }
            std::cout << "\n";
        }

        // Check for winning condition
        if (collectedItems >= 5) {
            std::cout << "Congratulations! You've collected 5 items and won the game!\n";
            break;
        }

        // Get user input
        std::string input;
        std::cout << "Enter a command: ";
        std::cin >> input;

        // Check for pick-up and drop commands
        if (input == "PICKUP") {
            std::cout << "Enter the name of the item you want to pick up: ";
            std::cin >> input;
            if (currentPlayerRoom->hasItem(input)) {
                Item* pickedItem = nullptr;
                for (auto& item : items) {
                    if (item->getName() == input) {
                        pickedItem = item;
                        break;
                    }
                }

                if (pickedItem != nullptr) {
                    player->addItem(pickedItem);
                    currentPlayerRoom->removeItem(pickedItem);
                    std::cout << "You picked up the " << input << ".\n";
                    collectedItems++;
                } else {
                    std::cout << "Item not found in the room.\n";
                }
            } else {
                std::cout << "No such item in the room.\n";
            }
        } else if (input == "DROP") {
            if (!inventory.empty()) {
                std::cout << "Enter the name of the item you want to drop: ";
                std::cin >> input;
                Item* droppedItem = nullptr;
                for (auto& item : inventory) {
                    if (item->getName() == input) {
                        droppedItem = item;
                        break;
                    }
                }

                if (droppedItem != nullptr) {
                    player->removeItem(droppedItem);
                    currentPlayerRoom->addItem(droppedItem);
                    std::cout << "You dropped the " << input << ".\n";
                    collectedItems--;
                } else {
                    std::cout << "Item not found in your inventory.\n";
                }
            } else {
                std::cout << "Your inventory is empty.\n";
            }
        } else if (input == "WIN") {
            std::cout << "Congratulations! You've collected 5 items and won the game!\n";
            break;
        } else if (input == "QUIT") {
            std::cout << "Thanks for playing. Goodbye!\n";
            break;
        } else {
            // Process movement commands
            Room* nextRoom = currentPlayerRoom->getExit(input);
            if (nextRoom != nullptr) {
                currentPlayerRoom = nextRoom;
            } else {
                std::cout << "Invalid command. Try again.\n";
            }
        }
    }
}
