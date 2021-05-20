#pragma once
#include "CardDeck.h"

class Blackjack{
private:
    CardDeck deck{};
    vector<Card> playerHand;
    vector<Card> dealerHand;
    int valueOfCard(Card card);
    int sumOfHand(vector<Card> hand);
    void printHand(vector<Card> hand);
    void playerDraws();
    void dealerTurn();
public:
    Blackjack();
    void playerTurn();
    void endgame();
};

void playBlackjack();