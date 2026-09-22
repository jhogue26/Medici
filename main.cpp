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

template <typename T>
void displayMessage(const T& message)
{
    std::cout << message << std::endl;
}

int main()
{
    try
    {
        displayMessage("Starting the Medici Game...");
        
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