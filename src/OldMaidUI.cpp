// src/OldMaidUI.cpp
#include "OldMaidUI.h"
#include <iostream>

unsigned int OldMaidUI::requestCard(Player* p, std::list<Card*>* hand) {
    // For simplicity, randomly select a card
    unsigned int index = rand() % hand->size();
    return index;
}

void OldMaidUI::playFailed() {
    std::cout << "No matching pair found.\n";
}

void OldMaidUI::playSucceeded() {
    std::cout << "Pair found and removed!\n";
}

void OldMaidUI::outOfGame(Player* player) {
    std::cout << player->name << " is out of the game.\n";
}

void OldMaidUI::showGameOutcome(std::vector<Player*> players) {
    if (players.empty()) {
        std::cout << "All players are out of the game!\n";
    } else {
        std::cout << players.front()->name << " is the Old Maid!\n";
    }
}
