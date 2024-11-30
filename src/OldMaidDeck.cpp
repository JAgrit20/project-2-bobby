#include "OldMaidDeck.h"
#include "Card.h"
#include <algorithm>
#include <random>
#include <iostream>

// Create the Old Maid deck without the queen card
void OldMaidDeck::create() {
    // A standard deck without one queen for the "Old Maid" variant
    // We can create cards with ranks and suits, and add to the deck
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 1; rank <= 13; ++rank) {
            if (rank == 12) continue;  // Remove Queen (12) from the deck
            Card* card = new Card(suit, rank);
            deck.push_back(card);
        }
    }

    shuffle();
}

// Shuffle the deck
void OldMaidDeck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

// Get a card from the top of the deck
Card* OldMaidDeck::getCard() {
    if (deck.empty()) return nullptr;
    Card* card = deck.back();
    deck.pop_back();
    return card;
}

// Add a card to the deck
void OldMaidDeck::addCard(Card* card) {
    deck.push_back(card);
}

// Get the size of the deck
unsigned int OldMaidDeck::size() {
    return deck.size();
}
