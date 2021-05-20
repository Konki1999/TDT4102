#pragma once
#include "std_lib_facilities.h"
#include <iostream>
#include <clocale>

enum class Suit{clubs, hearts, spades, diamonds};
enum class Rank{two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

string suitToString(Suit suit);
string rankToString(Rank rank);
int findNumValueOfRank(Rank rank);

class Card{
private:
    Suit s;
    Rank r;
public:
    Card(Suit suit, Rank rank);
    Suit getSuit();
    Rank getRank();
    string toString();
    string toStringShort();
};