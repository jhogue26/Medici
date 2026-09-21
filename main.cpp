/*
 * Program name: main.cpp
 * Author: Justin Hogue
 * Last modified: 09/20/2023
 * Purpose: Runs the Medici game.
*/
#include <iostream>
#include "card.h"   
#include "player.h"
#include "deck.h"
#include "game.h"


int main()
{
    try
    {
        
        Game game;

        game.setupGame();
        game.playGame();
    }
    catch (const std::exception& error)
    {
        std::cerr << "Error: " << error.what() << std::endl;
    }
    

    return 0;
}