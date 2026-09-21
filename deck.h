#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

class Deck 
{
private:
    std::vector<Card> cards;

public:
    // Constructor
    Deck(); 

    // Deck functions
    void createDeck();
    void shuffleDeck();
    void prepareDeck(int numPlayers);
    Card drawCard();
    int getDeckSize() const;
};

#endif // DECK_H