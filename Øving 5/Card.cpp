#include "Card.h"

map<Suit,string> mapSuitToString{{Suit::clubs, "Clubs"}, {Suit::hearts, "Hearts"}, {Suit::spades, "Spades"}, {Suit::diamonds,"Diamonds"}};
map<Rank,string> mapRankToString{{Rank::two, "Two"}, {Rank::three, "Three"}, {Rank::four,"Four"}, {Rank::five,"Five"}, {Rank::six,"Six"}, {Rank::seven,"Seven"}, {Rank::eight,"Eight"}, {Rank::nine,"Nine"}, {Rank::ten,"Ten"}, {Rank::jack,"Jack"}, {Rank::queen,"Queen"}, {Rank::king,"King"}, {Rank::ace, "Ace"}};

string suitToString(Suit suit){
    string str = mapSuitToString.at(suit);
    return str;
}

string rankToString(Rank rank){
    string str = mapRankToString.at(rank);
    return str;
}

int findNumValueOfRank(Rank rank){
    int i = 0;
    while(true){
        if(Rank(i) == rank){
            return i+2;
        }
        else{
            i++;
        }
    }
}

Card::Card(Suit suit, Rank rank): s{suit}, r{rank}
{}

Suit Card::getSuit(){
    return s;
}

Rank Card::getRank(){
    return r;
}

string Card::toString(){
    string str = rankToString(r) + " of " + suitToString(s);
    return str;
}

string Card::toStringShort(){
    char shortSuit = suitToString(s)[0];
    string shortRank = to_string(findNumValueOfRank(r));
    string str = shortSuit + shortRank;
    return str;
}