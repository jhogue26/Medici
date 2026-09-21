/*
 * Program name: main.cpp
 * Author: Justin Hogue
 * Last modified: 09/20/2023
 * Purpose: Runs the Medici game.
*/
#include <iostream>
#include "card.h"   
#include "player.h"

int main()
{
    Player player1("Justin", 40);
    Card card1("Cloth", 5);
    Card card2("Spice", 3);
 
    player1.addCard(card1);
    player1.addCard(card2);

    std::cout << "Testing Medici Cards and Player class:" << std::endl;
    std::cout << "Player Name: " << player1.getName() << std::endl;
    std::cout << "Player Money: " << player1.getMoney() << std::endl;
    std::cout << "Player Ship Size: " << player1.getShipSize() << std::endl;

    player1.showShip();

    return 0;
}