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
    std::cout << "==========================\n\n";
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
    displayWinner();
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

    scoreDay();
}

void Game::scoreDay()
{
    std::cout << "\nScoring for Day " << currentDay << ":\n";
    for (Player& player : players)
    {
        int shipValue = player.getShipValue();
        player.addScore(shipValue);
        std::cout << player.getName() << "'s ship value: " << shipValue 
                  << "\nTotal score: " << player.getScore() << "\n";
        player.resetShip(); // Reset ship for the next day
    }
}

void Game::displayWinner()
{
    std::cout << "\n--- Final Scores ---\n";

    for (size_t i = 1; i < players.size(); ++i)
    {
        std::cout << players[i].getName() << ": " << players[i].getScore() << "\n";
    }

    int highestScore = players[0].getScore();
    int winnerIndex = 0;
    bool tie = false;
    
    for (size_t i = 1; i < players.size(); ++i)
    {

        if (players[i].getScore() > highestScore)
        {
            highestScore = players[i].getScore();
            winnerIndex = static_cast<int>(i);
            tie = false;
        }
        else if (players[i].getScore() == highestScore)
        {
            tie = true;
        }
    }

    if (tie)
    {
        std::cout << "\nIt's a tie! Multiple players have the highest score of " << highestScore << "!\n";
    }
    else
    {
        std::cout << "\n" << players[winnerIndex].getName() << " wins with a score of " << highestScore << "!\n";
    }
}
