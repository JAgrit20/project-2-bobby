#include "OldMaid.h"
#include "OldMaidUI.h"
#include "OldMaidDeck.h"
#include "Player.h"

int main() {
    // Create the game UI and deck objects
    OldMaidUI* ui = new OldMaidUI();
    OldMaidDeck* deck = new OldMaidDeck();

    // Initialize the game with the UI and deck
    OldMaid game(ui, deck);

    // Add players to the game
    game.addPlayer(new Player("Alice"));
    game.addPlayer(new Player("Bob"));
    game.addPlayer(new Player("Charlie"));

    // Create the deck and shuffle it
    deck->create();

    // Deal cards to the players
    game.dealCards(game.getPlayers());

    // Start the game
    game.start();

    // Clean up
    delete ui;
    delete deck;

    return 0;
}
