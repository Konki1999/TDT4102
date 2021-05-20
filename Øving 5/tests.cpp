#include "tests.h"

void testCard(){
    Suit s = Suit::clubs;
	Rank r = Rank::king;
	string suit = suitToString(s);
	string rank = rankToString(r);
	cout << rank << " of " << suit << endl << endl;

	Card c{Suit::spades, Rank::ace};
	cout << c.toString() <<'\n';
	cout << c.toStringShort() << endl << endl;
}

void testCardDeck(){
    CardDeck cd{};
	cd.printShort();
	cout << endl;
	cd.shuffle();
	cd.print();
	Card c1 = cd.drawCard();
	cout << endl << c1.toString() << endl << endl;
	cd.print();
}