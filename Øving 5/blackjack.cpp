#include "blackjack.h"

Blackjack::Blackjack(){
    deck.shuffle();
    for(int i = 0; i < 2; i++){
        Card card1 = deck.drawCard();
        playerHand.push_back(card1);
    }
    Card card2 = deck.drawCard();
    dealerHand.push_back(card2); 
}

int Blackjack::valueOfCard(Card card){
    Rank r = card.getRank();
    int rankNum = findNumValueOfRank(r);
    int value;
    if(rankNum <= 10){
        value = rankNum;
    }
    else if(rankNum < 14){
        value = 10;
    }
    else{
        value = 11;
    }
    return value;
}

int Blackjack::sumOfHand(vector<Card> hand){
    vector<int> handValues(hand.size());
    for(int i = 0; i < hand.size(); i++){
        handValues[i] = valueOfCard(hand[i]);
    }
    int numberOfElevens = count(handValues.begin(), handValues.end(), 11);
    int sum = 0;
    for(int x : handValues){
        sum += x;
    }
    while((sum > 21) && (numberOfElevens > 0)){
        sum -= 10;
        numberOfElevens -= 1;
    }
    return sum;
}

void Blackjack::printHand(vector<Card> hand){
    for(Card card : hand){
        string str = card.toString();
        cout << str << ", ";
    }
    cout << "Sum: " << sumOfHand(hand) << endl;
}

void Blackjack::playerDraws(){
    Card card = deck.drawCard();
    playerHand.push_back(card);
    cout << "Your hand: \n";
    printHand(playerHand);
}

void Blackjack::playerTurn(){
    cout << "---Your turn---\n\n";
    bool playerPlay = true;
    int playerSum = sumOfHand(playerHand);
    cout << "Your hand: \n";
    printHand(playerHand);
    cout << "Dealer\'s hand: \n";
    printHand(dealerHand);
    while(playerPlay){

        if(playerSum == 21){
        cout << "You got a Blackjack!\n";
        playerPlay = false;
        dealerTurn();
        break;
        }

        char hitOrStand;
        cout << "Do you want to (h)it or (s)tand?\n";
        cin >> hitOrStand;
        switch(hitOrStand){
            case 'h':
                playerDraws();
                playerSum = sumOfHand(playerHand);
                break;
            case 's':
                playerPlay = false;
                dealerTurn();
                break;
            default:
                cout << "Your hand: \n";
                printHand(playerHand);
                break;
        }
        if(playerSum > 21){
            playerPlay = false;
            dealerTurn();
        }
    }
}

void Blackjack::dealerTurn(){
    cout << "---Dealer\'s turn---\n\n";
    bool dealerPlay = true;
    int dealerSum = sumOfHand(dealerHand);
    cout << "Dealer\'s hand: \n";
    printHand(dealerHand);
    while(dealerPlay){
        if (dealerSum == 21){
            cout << "Dealer has a Blackjack!\n";
        }
        if(dealerSum > 21){
            dealerPlay = false;
        }
        else if(dealerSum >= 17){
            cout << "Dealer stands...\n";
            dealerPlay = false;
        }
        else{
            cout << "Dealer draws... \n";
            Card card = deck.drawCard();
            dealerHand.push_back(card);
            cout << "Dealer\'s hand:\n";
            printHand(dealerHand);
            dealerSum = sumOfHand(dealerHand);  
        }
    }
}

void Blackjack::endgame(){
    int playerSum = sumOfHand(playerHand);
    int dealerSum = sumOfHand(dealerHand);
    if(playerSum > 21){
        cout << "You are bust. The dealer wins.\n";
    }
    else if(playerSum == dealerSum){
        cout << "It\'s a push. Nobody wins.\n";
    }
    else if(playerSum > dealerSum){
        cout << "Your sum is greater than the dealer\'s. You win!\n";
    }
    else if(dealerSum > 21){
        cout << "Dealer is bust. You win!\n";
    }
    else{
        cout << "The dealer\'s sum is greater than yours. You lose.\n";
    }
    cout << endl;
}

void playBlackjack(){
    Blackjack game{};
    game.playerTurn();
    game.endgame();
}