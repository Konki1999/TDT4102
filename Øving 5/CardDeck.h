#pragma once
#include "Card.h"
#include <ctime>
#include <cmath>
#include <cstdlib>

class CardDeck{
private:
    vector<Card> cards;
    void swap(int index1, int index2); //Private because it will only be used when shuffling
public:
    CardDeck();
    void print();
    void printShort();
    void shuffle();
    Card drawCard();
};