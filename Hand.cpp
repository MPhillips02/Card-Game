#include "Hand.h"
#include <iostream>

Hand::Hand(Deck deck, int N) {
    for (int i = 0; i < N; i++) {
        hand.push_back(deck.drawCard());
    }
}


std::string Hand::printHand() {
    std::string h = "Your hand: ";

    for (unsigned int i = 0; i < hand.size(); i++) {
        h += "["+std::to_string(i+1)+"]"+" "+hand[i].getColor()+":"+std::to_string(hand[i].getRank())+" ";
    }
    return h;
}


Card Hand::dealCard(int num) {
    Card c = hand[num-1];
    hand.erase(hand.begin() + num-1);

    return c;
}


int Hand::getHandSize() {
    return hand.size();
}