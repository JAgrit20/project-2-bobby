// src/OldMaidDeck.cpp
#include "OldMaidDeck.h"

void OldMaidDeck::create() {
    Deck::create();
    // Remove one Queen to make the Old Maid
    for (auto it = deck.begin(); it != deck.end(); ++it) {
        if ((*it)->rank == Card::QUEEN) {
            delete *it;
            deck.erase(it);
            break;
        }
    }
}
