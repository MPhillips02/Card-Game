#include "Card.h"
#include <string>

Card::Card(int r, Color c) {
    if (c == purple) {
        rank = r;
        value = r;
        color = purple;
    } else if (c == orange) {
        rank = r;
        value = r*2;
        color = orange;
    }
}

std::string Card::printCard() {
    std::string card;

    if (color == purple) {
         card = "purple:"+std::to_string(rank);
    } else if (color == orange) {
        card = "orange:"+std::to_string(rank);
    }

    return card;
}

int Card::getRank() {
    return rank;
}

int Card::getValue() {
    return value;
}

std::string Card::getColor() {
    std::string card;

    if (color == purple) {
        card = "purple";
    } else if (color == orange) {
        card = "orange";
    }

    return card;
}