// src/main.cpp
#include "OldMaid.h"
#include "OldMaidUI.h"
#include "OldMaidDeck.h"
#include "Player.h"

int main() {
    OldMaidUI* ui = new OldMaidUI();
    OldMaidDeck* deck = new OldMaidDeck();
    OldMaid game(ui, deck);

    game.addPlayer(new Player("Alice"));
    game.addPlayer(new Player("Bob"));
    game.addPlayer(new Player("Charlie"));

    game.start();

    return 0;
}
