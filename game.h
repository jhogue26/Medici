#ifndef GAME_H
#define GAME_H

#include <vector>
#include "player.h"
#include "deck.h"
#include "auction.h"

class Game 
{
private:
    std::vector<Player> players;
    Auction auction;    
    Deck deck;
    int currentDay;

public:
    Game();

    void setupGame();
    void playGame();
    void playDay();
    void scoreDay();
}; 

#endif // GAME_H