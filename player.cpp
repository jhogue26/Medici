/*
 * Program name: player.cpp
 * Author: Justin Hogue
 * Last modified: 09/20/2023
 * Purpose: Defines the Player class.
*/

#include "player.h"
#include <iostream>

// Constructor
Player::Player(std::string name, int money) 
{
    this->name = name;
    this->money = money;
}

// Returning the player's name, money, and ship size
std::string Player::getName() const
{
    return name;
}

int Player::getMoney() const
{
    return money;
}

int Player::getShipSize() const
{
    return static_cast<int>(ship.size());
}

// Player actions
void Player::addCard(const Card& card)
{
    ship.push_back(card);
}

void Player::spendMoney(int amount)
{
    money -= amount;
}

void Player::showShip() const
{
    std::cout << name << "'s ship:" << std::endl;
    for (const Card& card : ship)
    {
        std::cout << card << std::endl;
    }
}