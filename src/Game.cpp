// src/Game.cpp
#include "Game.h"
#include "Exception.h"

Game::~Game() {
    delete deck;
    delete ui;
    for (auto player : players) {
        delete player;
    }
}

void Game::addPlayer(Player* player) {
    players.push_back(player);
}

std::vector<Player*> Game::getPlayers() {
    return players;
}

void Game::start() {
    if (players.empty()) {
        throw game_init_error("No players in the game.");
    }
    deck->shuffle();
    dealCards(players);
    unsigned int playerIndex = 0;
    while (!isOver()) {
        beforeTurn(playerIndex, players.size());
        Player* currentPlayer = players[playerIndex];
        // Logic for the player's turn
        // ...
        afterTurn(currentPlayer, &players, nullptr);
        checkIfPlayerOut();
        playerIndex = (playerIndex + 1) % players.size();
    }
    ui->showGameOutcome(playersGoneOut);
}

void Game::checkIfPlayerOut() {
    for (auto it = players.begin(); it != players.end();) {
        if ((*it)->getHand()->empty()) {
            ui->outOfGame(*it);
            playersGoneOut.push_back(*it);
            it = players.erase(it);
        } else {
            ++it;
        }
    }
}

bool Game::hasSet(std::list<Card*>* hand, unsigned int size) {
    std::map<Card::Rank, int> rankCount;
    for (auto card : *hand) {
        rankCount[card->rank]++;
    }
    for (auto& pair : rankCount) {
        if (pair.second >= size) {
            return true;
        }
    }
    return false;
}
