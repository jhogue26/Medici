#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>


class Card {
    private:
        std::string commodity;
        int value;

    public:
        // Constructors
        Card(); 
        Card(std::string commodity, int value);
        // Getters
        std::string getCommodity() const;
        int getValue() const;
        // Overloaded operator to display card
        friend std::ostream& operator<<(std::ostream& os, const Card& card);
};

#endif // CARD_H