// src/Player.cpp
#include "Player.h"

Player::~Player() {
    for (auto card : hand) {
        delete card;
    }
}

void Player::addCard(Card* c) {
    hand.push_back(c);
}

Card* Player::getCard(unsigned int index) {
    if (index >= hand.size()) return nullptr;
    auto it = hand.begin();
    std::advance(it, index);
    Card* card = *it;
    hand.erase(it);
    return card;
}

std::list<Card*>* Player::getHand() {
    return &hand;
}
