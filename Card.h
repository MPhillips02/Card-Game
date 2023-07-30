#ifndef CARD_H_
#define CARD_H_

#include <string>

class Card
{
    public:
        enum Color { purple, orange };
        Card(){rank = 0; value = 0; color = purple;}
        Card(int r, Color c);
        std::string printCard();
        int getRank();
        int getValue();
        std::string getColor();
    private:
        int rank;
        int value;
        Card::Color color;
};
  

#endif // CARD_H_
