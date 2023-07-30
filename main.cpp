#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <ctime>
#include <iostream>
using namespace std;

int main() {

  // 1. Create a deck of cards and shuffle it.
  // 2. Create two players, each one with 5 cards in their hand.
  // 3. Play five rounds. In each round:
  //    - Have computer deal a card from their hand.
  //    - Show human their hand of cards so that they can make a selection.
  //    - Have human deal their card. 
  //    - Determine who won the round and update points accordingly.
  //    - Print results for current round.
  // 4. Print final game results.  

  // initializes and shuffles the deck
  Deck c;
  c.shuffle();

  // generates the players and computers decks
  Player person(c, 5);
  c.shuffle();
  Player computer(c, 5);
  int pchoice;

  cout <<"Welcome to TigerGame!\n";
  cout <<"The deck has been shuffled and cards have been drawn.\n\n";

  // creates loop to go for 5 rounds
  for (int i = 0; i < 5; i++) {
    cout << "Round " << i+1 << endl;
    cout << "-------\n";
    // Generates computers random choice
    srand(time(NULL));
    int randNum = rand() % computer.hand.getHandSize() + 1;

    // deals a random card from the computers hand, and prints it out for the player to see.
    Card comp = computer.hand.dealCard(randNum);
    cout << "The computer plays: " << comp.printCard() << endl;

    // prints the players hand and prompts them for their choice (not allowing choice if it is more than their hand size)
    cout << person.hand.printHand() << endl;
    cout << "Which card do you want to play? ";
    cin >> pchoice;

    while (pchoice > person.hand.getHandSize()) {
      std::cout << "Please select a valid card.\n";
      cout << "Which card do you want to play? ";
      cin >> pchoice;
    }
    Card pers = person.hand.dealCard(pchoice);

    if (pers.getValue() > comp.getValue()) {
      cout << "You win this round!\n";
      person.score += pers.getValue()+comp.getValue();
    } else if (pers.getValue() < comp.getValue()) {
      cout << "The computer wins this round!\n";
      computer.score += pers.getValue()+comp.getValue();
    } else {
      cout << "Tie!\n";
    }

    cout << "\nCurrent scores:\n" << "Human: " << person.score << "\nComputer: " << computer.score << endl << endl;

  }

  cout << "FINAL SCORE:\n" << "Human: " << person.score << "\nComputer: " << computer.score << endl << endl;
  if (person.score > computer.score) {
    cout << "Human has won!\n";
  } else if (person.score < computer.score) {
    cout << "Computer has won!\n";
  } else {
    cout << "Final outcome is a tie!\n";
  }
      

  return 0;
}
