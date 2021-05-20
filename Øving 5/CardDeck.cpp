#include "CardDeck.h"

CardDeck::CardDeck(){
    for(int i = 0; i < 4; i++){
        Suit suit = Suit(i);
        for(int j = 0; j < 13; j++){
            Rank rank = Rank(j);
            Card c{suit, rank};
            cards.push_back(c);
        }
    }
};

void CardDeck::swap(int index1, int index2){
    Card card1 = cards[index1];
    cards[index1] = cards[index2];
    cards[index2] = card1;
}

void CardDeck::print(){
    for(Card card : cards){
        string str = card.toString();
        cout << str << endl;
    }
}

void CardDeck::printShort(){
    for(Card card : cards){
        string str = card.toStringShort();
        cout << str << endl;
    }
}

void CardDeck::shuffle(){
    int len = cards.size();
    for(int i = 0; i < 1000000; i++){
        int index1 = rand()%len;
        int index2 = rand()%len;
        swap(index1,index2);
    }
}

Card CardDeck::drawCard(){
    Card c = cards[0];
    cards.erase(cards.begin());
    return c;
}