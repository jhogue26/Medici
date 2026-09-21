/*
 * Program name: game.cpp
 * Author: Justin Hogue
 * Last modified: 09/20/2023
 * Purpose: Implements the Game class.  
*/

#include "game.h"
#include "auction.h"
#include <iostream>
#include <stdexcept>

Game::Game()
{
    currentDay = 1;
}

void Game::setupGame()
{
    int numPlayers;
    std::cout << "==========================\n";
    std::cout << "Welcome to the Medici Game!\n";
    std::cout << "==========================\n";
    std::cout << "Enter the number of players (2-6): ";
    std::cin >> numPlayers;

    if (numPlayers < 2 || numPlayers > 6)
    {
        throw std::invalid_argument("Number of players must be between 2 and 6.");
    }  
    int startingMoney;
    
    if (numPlayers <= 4)
    {
        startingMoney = 40;
    }
    else
    {
        startingMoney = 30;
    }

    for (int i = 0; i < numPlayers; ++i)
    {
        std::string name;
        std::cout << "Enter player " << (i + 1) << " name: ";
        std::cin >> name;
        players.push_back(Player(name, startingMoney));
    }
    
    deck.prepareDeck(numPlayers);

    std::cout << "Game setup complete! Starting the game...\n";
    std::cout << "Cards in deck: " << deck.getDeckSize() << "\n";
}

void Game::playGame()
{
    while (currentDay <= 3)
    {
        std::cout << "\n--- Day " << currentDay << " ---\n";
        playDay();
        currentDay++;
    }
    std::cout << "\nGame over! Thank you for playing.\n";
}

void Game::playDay()
{
    std::cout << "\nDay " << currentDay << "!\n";

    Auction auction;

    // Draw cards for the auction
    if (deck.getDeckSize() > 0)
    {
        Card card1 = deck.drawCard();
        auction.addCard(card1);

        auction.displayCards();
    auction.startAuction(players);
    }
    else
    {
        throw std::runtime_error("Deck is empty. Cannot draw cards for auction.");
    }
}