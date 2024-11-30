#include "OldMaidUI.h"
#include <iostream>

unsigned int OldMaidUI::requestCard(Player* p, std::list<Card*>* hand) {
    std::cout << p->name << ", choose a card to request from another player." << std::endl;

    // For simplicity, let's assume we just pick the first card in hand
    unsigned int cardIndex = 0;

    // Display the player's hand for the sake of the UI
    std::cout << "Your current hand: ";
    for (Card* card : *hand) {
        std::cout << *card << " ";
    }
    std::cout << std::endl;

    // Simplified request, returning the first card's index
    std::cout << "Requesting card: " << *hand->front() << std::endl;
    return cardIndex;
}

void OldMaidUI::playFailed() {
    std::cout << "Request failed: no matching card found." << std::endl;
}

void OldMaidUI::playSucceeded() {
    std::cout << "Request succeeded: matching card found!" << std::endl;
}

void OldMaidUI::outOfGame(Player* player) {
    std::cout << player->name << " is out of the game." << std::endl;
}

void OldMaidUI::showGameOutcome(std::vector<Player*> players) {
    std::cout << "Game Over!" << std::endl;
    for (auto player : players) {
        std::cout << player->name << "'s score: " << player->score << std::endl;
    }
}
