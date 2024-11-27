// src/OldMaid.cpp
#include "OldMaid.h"
#include <algorithm>

void OldMaid::dealCards(std::vector<Player*> p) {
    size_t playerIndex = 0;
    while (deck->size() > 0) {
        Card* card = deck->getCard();
        p[playerIndex]->addCard(card);
        playerIndex = (playerIndex + 1) % p.size();
    }
    // Remove pairs from each player's hand
    for (auto player : p) {
        auto hand = player->getHand();
        bool foundPair;
        do {
            foundPair = false;
            for (auto it1 = hand->begin(); it1 != hand->end(); ++it1) {
                auto it2 = it1;
                ++it2;
                while (it2 != hand->end()) {
                    if ((*it1)->rank == (*it2)->rank) {
                        delete *it1;
                        delete *it2;
                        hand->erase(it1);
                        hand->erase(it2);
                        foundPair = true;
                        break;
                    } else {
                        ++it2;
                    }
                }
                if (foundPair) break;
            }
        } while (foundPair);
    }
}

void OldMaid::beforeTurn(unsigned int playerNum, unsigned int numPlayers) {
    playerAsking = playerNum;
}

void OldMaid::afterTurn(Player* currentPlayer, std::vector<Player*>* players, Card* played) {
    // Remove pairs if any after the turn
    auto hand = currentPlayer->getHand();
    bool foundPair;
    do {
        foundPair = false;
        for (auto it1 = hand->begin(); it1 != hand->end(); ++it1) {
            auto it2 = it1;
            ++it2;
            while (it2 != hand->end()) {
                if ((*it1)->rank == (*it2)->rank) {
                    delete *it1;
                    delete *it2;
                    hand->erase(it1);
                    hand->erase(it2);
                    foundPair = true;
                    break;
                } else {
                    ++it2;
                }
            }
            if (foundPair) break;
        }
    } while (foundPair);
}

bool OldMaid::turnOver() {
    // The turn is over after one card is drawn
    return true;
}

bool OldMaid::isOver() {
    return players.size() <= 1;
}
