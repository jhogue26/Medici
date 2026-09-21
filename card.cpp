/*
 * Program name: card.cpp
 * Author: Justin Hogue
 * Last modified: 09/20/2023
 * Purpose: Defines the Card class.
*/

#include "card.h"
// Default constructor
Card::Card() 
{
    commodity = "";
    value = 0;
}
// constructor with parameters
Card::Card(std::string commodity, int value) 
{
    this->commodity = commodity;
    this->value = value;
}

std::string Card::getCommodity() const 
{
    return commodity;
}

int Card::getValue() const 
{
    return value;
}   
// Overloaded operator to display card
std::ostream& operator<<(std::ostream& os, const Card& card)
{
    os << "Commodity: " << card.commodity << ", Value: " << card.value;
    return os;
}