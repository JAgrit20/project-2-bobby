#include "Deck.h"
#include <algorithm>
#include <random>
#include <iostream>

// Destructor: Clean up dynamically allocated memory for cards
Deck::~Deck() {
    for (auto card : deck) {
        delete card;
    }
    deck.clear();
}

// Shuffle the deck of cards using random shuffling
void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

// Add a card to the deck
void Deck::addCard(Card* card) {
    deck.push_back(card);
}

// Get the top card from the deck
Card* Deck::getCard() {
    if (!deck.empty()) {
        Card* topCard = deck.back();
        deck.pop_back();
        return topCard;
    }
    return nullptr;  // If the deck is empty
}

// Get the size of the deck
unsigned int Deck::size() {
    return deck.size();
}

// Create a standard deck of 52 cards (13 ranks * 4 suits)
void Deck::create() {
    for (int suit = Card::CLUB; suit <= Card::HEART; ++suit) {
        for (int rank = Card::ACE; rank <= Card::KING; ++rank) {
            deck.push_back(new Card(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank)));
        }
    }
}
