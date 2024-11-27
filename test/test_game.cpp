// tests/test_game.cpp
#include "gtest/gtest.h"
#include "OldMaidDeck.h"
#include "Player.h"

TEST(DeckTest, DeckCreation) {
    OldMaidDeck deck;
    deck.create();
    EXPECT_EQ(deck.size(), 51); // 52 cards minus one Queen
}

TEST(PlayerTest, AddAndGetCard) {
    Player player("TestPlayer");
    Card* card = new Card(Card::HEART, Card::ACE);
    player.addCard(card);
    EXPECT_EQ(player.getHand()->size(), 1);
    Card* retrievedCard = player.getCard(0);
    EXPECT_EQ(retrievedCard->suit, Card::HEART);
    EXPECT_EQ(retrievedCard->rank, Card::ACE);
    EXPECT_EQ(player.getHand()->size(), 0);
    delete retrievedCard;
}
