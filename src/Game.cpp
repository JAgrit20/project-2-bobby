#include "Game.h"
#include <iostream>
#include <algorithm>
#include "Player.h"
#include "Card.h"

// Destructor to clean up the players
Game::~Game() {
    // We don't need to delete the players because they are not owned by the game class
    // The game just holds references to the players, so it's the responsibility of
    // whoever created the players to delete them.
    players.clear();
    playersGoneOut.clear();
}

// Add a Player to the game
void Game::addPlayer(Player* player) {
    players.push_back(player);
}

// Get the collection of players
std::vector<Player*> Game::getPlayers() {
    return players;
}

// Start the game
void Game::start() {
    ui->showGameOutcome(players);  // Show the initial game outcome (e.g. starting the game)
    deck->shuffle();  // Shuffle the deck before starting

    // Deal cards to players
    dealCards(players);

    // Main game loop
    while (!isOver()) {
        for (unsigned int i = 0; i < players.size(); ++i) {
            if (isOver()) break;

            // Perform actions before the player's turn
            beforeTurn(i, players.size());

            // Get the current player
            Player* currentPlayer = players[i];

            // Handle the current player's turn
            ui->requestCard(currentPlayer, &currentPlayer->getHand());

            // Perform actions after the player's turn
            Card* played = nullptr;  // Assume this is set by some mechanism after the card is played
            afterTurn(currentPlayer, &players, played);

            // Check if the player has no more cards
            checkIfPlayerOut();
        }
    }
}

// Deal cards to players
void Game::dealCards(std::vector<Player*> p) {
    unsigned int playerCount = p.size();
    for (unsigned int i = 0; i < playerCount; ++i) {
        while (deck->size() > 0) {
            Card* card = deck->getCard();
            p[i]->addCard(card);  // Add card to the player's hand
        }
    }
}

// Perform actions before a player's turn
void Game::beforeTurn(unsigned int playerNum, unsigned int numPlayers) {
    // Placeholder for any pre-turn logic
    std::cout << "Player " << playerNum + 1 << "'s turn starts." << std::endl;
}

// Perform actions after a player's turn
void Game::afterTurn(Player* currentPlayer, std::vector<Player*>* players, Card* played) {
    if (played) {
        // For now, we simply print the played card.
        std::cout << "Player " << currentPlayer->getName() << " played: " << *played << std::endl;
    }

    // For now, we simulate the game state after the turn.
    ui->playSucceeded();  // Assume the player successfully played
}

// Check if a player's turn is over
bool Game::turnOver() {
    // Placeholder logic for checking if the turn is over
    return true;
}

// Check if the game is over
bool Game::isOver() {
    // The game is over if only one player is left with cards, or if no cards are left
    unsigned int playersWithCards = 0;
    for (auto player : players) {
        if (player->getHand().size() > 0) {
            ++playersWithCards;
        }
    }
    return playersWithCards <= 1;
}

// Check if a player has no more cards to play and remove the player from the game
void Game::checkIfPlayerOut() {
    for (auto it = players.begin(); it != players.end(); ) {
        if ((*it)->getHand().empty()) {
            ui->outOfGame(*it);  // Inform the UI that the player is out
            playersGoneOut.push_back(*it);  // Add to the list of players who have been eliminated
            it = players.erase(it);  // Remove player from the game
        } else {
            ++it;
        }
    }
}

// Checks if a player has a set of matching cards
bool Game::hasSet(std::list<Card*>* hand, unsigned int size) {
    std::unordered_map<Card::Rank, int> rankCount;

    // Count occurrences of each rank
    for (Card* card : *hand) {
        rankCount[card->rank]++;
    }

    // Check if any rank has the desired number of matching cards
    for (auto& entry : rankCount) {
        if (entry.second >= size) {
            return true;
        }
    }
    return false;
}
