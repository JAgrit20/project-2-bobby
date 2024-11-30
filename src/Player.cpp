#include "Player.h"
#include <iostream>

// Add a card to the player's hand
void Player::addCard(Card* c) {
    hand.push_back(c);
}

// Get a specific card from the player's hand by index
Card* Player::getCard(unsigned int index) {
    if (index < hand.size()) {
        auto it = std::next(hand.begin(), index);
        return *it;
    }
    return nullptr;
}

// Get the list of cards in the player's hand
std::list<Card*>* Player::getHand() {
    return &hand;
}

// Destructor for cleaning up player resources (if needed)
Player::~Player() {
    for (Card* card : hand) {
        delete card;  // Assuming Card needs to be deleted
    }
}
