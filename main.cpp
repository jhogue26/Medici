/*
 * Program name: main.cpp
 * Author: Justin Hogue
 * Last modified: 09/20/2023
 * Purpose: Runs the Medici game.
*/
#include <iostream>
#include "card.h"   

int main()
{
    Card card1("Cloth", 5);
    Card card2("Spice", 3);
    Card card3("Gold", 10);

    std::cout << "Testing Medici Cards: \n";

    std::cout << card1 << std::endl;
    std::cout << card2 << std::endl;
    std::cout << card3 << std::endl;

    return 0;
}