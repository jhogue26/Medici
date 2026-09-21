#ifndef CARD_H
#define CARD_H

#include <iostream>

enum class Commodity {
    Cloth,
    Fur,
    Grain,
    Dye,
    Spice,
    Gold
};

class Card {
    private:
        Commodity commodity;
        int value;

    public:
        Card(Commodity commodity, int value);
        Commodity getCommodity() const;
        int getValue() const;
        bool isGold() const;
        friend std::ostream& operator<<(std::ostream& os, const Card& card);
};

#endif // CARD_H