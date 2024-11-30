#include "OldMaid.h"
#include "OldMaidDeck.h"
#include "OldMaidUI.h"
#include "Player.h"
#include <iostream>
#include <algorithm>

// Deal cards to players in the Old Maid game
void OldMaid::dealCards(std::vector<Player*> p) {
    unsigned int playerCount = p.size();
    std::vector<Card*> allCards;

    // Collect all cards from the deck into a vector
    while (deck->size() > 0) {
        allCards.push_back(deck->getCard());
    }

    // Distribute the cards to players
    unsigned int cardIndex = 0;
    while (cardIndex < allCards.size()) {
        for (unsigned int i = 0; i < playerCount && cardIndex < allCards.size(); ++i) {
            p[i]->addCard(allCards[cardIndex++]);
        }
    }
}

// Perform actions before a player's turn in Old Maid
void OldMaid::beforeTurn(unsigned int playerNum, unsigned int numPlayers) {
    std::cout << "Player " << playerNum + 1 << "'s turn starts." << std::endl;
    // In Old Maid, players may need to choose cards based on the current hand
}

// Perform actions after a player's turn in Old Maid
void OldMaid::afterTurn(Player* currentPlayer, std::vector<Player*>* players, Card* played) {
    if (played) {
        std::cout << "Player " << currentPlayer->name << " played: " << *played << std::endl;
    }

    // After the player's turn, we can check if the player has a matching set of cards (pairs)
    bool hasPairs = false;
    for (Card* card : currentPlayer->getHand()) {
        // Check for pairs, you could add custom logic to remove pairs here.
    }
    
    ui->playSucceeded();
}

// Check if a player's turn is over
bool OldMaid::turnOver() {
    return true;  // Placeholder: assume the turn ends automatically
}

// Check if the game is over in Old Maid
bool OldMaid::isOver() {
    // The game is over when only one player remains with cards, or when there is only one card left
    unsigned int playersWithCards = 0;
    for (Player* player : players) {
        if (!player->getHand()->empty()) {
            playersWithCards++;
        }
    }
    return playersWithCards <= 1;
}

// The Old Maid deck, which creates a deck without one pair (the queen)
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

// Old Maid UI implementation
unsigned int OldMaidUI::requestCard(Player* p, std::list<Card*>* hand) {
    std::cout << p->name << ", choose a card to request." << std::endl;
    // Simplified version for requesting a card
    return 0; // Placeholder: returning the first card in hand
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
