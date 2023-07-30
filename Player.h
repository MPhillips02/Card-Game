// Note: There is no Player.cpp file.
// The player class is simple enough to
// implement everything in Player.h

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Hand.h"
#include "Deck.h"

class Player
{
    public:
        Hand hand;
        int score;
        Player() {score = 0;}
        Player(Deck x, int N) {hand = Hand(x, N); score = 0;}
};
  

#endif // PLAYER_H_
