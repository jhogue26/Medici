#ifndef GAME_H
#define GAME_H

#include <vector>
#include "player.h"
#include "deck.h"

class Game 
{
private:
    std::vector<Player> players;
    Deck deck;
    int currentDay;

public:
    Game();

    void setupGame();
    void playGame();
    void playDay();
}; 

#endif // GAME_H