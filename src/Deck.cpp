// src/Deck.cpp
#include "Deck.h"
#include <algorithm>
#include <random>

Deck::~Deck() {
    for (auto card : deck) {
        delete card;
    }
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

void Deck::addCard(Card* card) {
    deck.push_back(card);
}

Card* Deck::getCard() {
    if (deck.empty()) return nullptr;
    Card* topCard = deck.back();
    deck.pop_back();
    return topCard;
}

unsigned int Deck::size() {
    return deck.size();
}

void Deck::create() {
    for (int suit = Card::CLUB; suit <= Card::HEART; ++suit) {
        for (int rank = Card::ACE; rank <= Card::KING; ++rank) {
            deck.push_back(new Card(static_cast<Card::Suit>(suit),
                                    static_cast<Card::Rank>(rank)));
        }
    }
}
