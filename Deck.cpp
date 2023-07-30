#include "Deck.h"
#include "Card.h"

Deck::Deck() {
    for (int i = 1; i < 11; i++) {
        Card::Color x = Card::Color::purple;
        Card c(i, x);
        deck.push_back(c);
    }

    for (int i = 1; i < 11; i++) {
        Card::Color x = Card::Color::orange;
        Card c(i, x);
        deck.push_back(c);
    }
}


void Deck::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle (deck.begin(), deck.end(), std::default_random_engine(seed));
}


Card Deck::drawCard() {
    Card c = deck[0];

    std::cout << "top card: " << deck[0].printCard() << std::endl;

    deck.erase(deck.begin());

    return c;
}


int Deck::getDeckSize() {
    return deck.size();
}