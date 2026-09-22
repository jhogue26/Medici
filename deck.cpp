/*
 * Program name: deck.cpp
 * Author: Justin Hogue
 * Last modified: 09/20/2023
 * Purpose: Implements the Deck class.
*/

#include "deck.h"
#include "exception.h"
#include <algorithm>
#include <random>
#include <stdexcept>

// Constructor
Deck::Deck() 
{
    createDeck();
}

// Create a standard deck of cards
void Deck::createDeck()
{
    cards.clear();

    std::vector<std::string> commodities = {"Cloth", "Fur", "Grain", "Dye", "Spice"};

    int values[] = {0, 1, 2, 3, 4, 5, 5};

    for (const std::string& commodity : commodities) 
    {
        for (int value : values) 
        {
            cards.push_back(Card(commodity, value));    
        }
    }
    // Gold card
    cards.push_back(Card("Gold", 10));
}
// Shuffle the deck of cards
void Deck::shuffleDeck()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(cards.begin(), cards.end(), generator);
}
// Draw a card from the deck
Card Deck::drawCard()
{
    if (cards.empty())
    {
        throw EmptyDeckException("You cannot draw a card from an empty deck.");
    }
    Card card = cards.back();
    cards.pop_back();
    return card;
}
// Get the current size of the deck
int Deck::getDeckSize() const
{
    return static_cast<int>(cards.size());
}
void Deck::prepareDeck(int numPlayers)
{
    createDeck();
    shuffleDeck();

    // Number of cards to remove based on the number of players
    int cardsToUse;
    if (numPlayers == 2 || numPlayers == 3) 
    {
        cardsToUse = 18; // Use 18 cards for 2 or 3 players
    } 
    else if (numPlayers == 4) 
    {
        cardsToUse = 24; // Use 24 cards for 4 players
    }
    else if (numPlayers == 5) 
    {
        cardsToUse = 30; // Use 30 cards for 5 players
    }
    else if (numPlayers == 6) 
    {
        cardsToUse = 36; // Use 36 cards for 6 players
    }
    else 
    {
        throw std::invalid_argument("Invalid number of players. Must be between 2 and 6.");
    }
    while (static_cast<int>(cards.size()) > cardsToUse) 
    {
        cards.pop_back(); // Remove cards from the deck until the desired size is reached
    }
}