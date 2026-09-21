/*
 * Program name: player.cpp
 * Author: Justin Hogue
 * Last modified: 09/20/2023
 * Purpose: Defines the Player class.
*/

#include "player.h"
#include <iostream>
#include <stdexcept>

// Constructor
Player::Player(std::string name, int money) 
{
    this->name = name;
    this->money = money;
    score = 0;
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

int Player::getShipValue() const
{
    int totalValue = 0;
    for (const Card& card : ship)
    {
        totalValue += card.getValue();
    }
    return totalValue;
}

int Player::getScore() const
{
    return score;
}

// Player actions
void Player::addCard(const Card& card)
{
    if (ship.size() >= 5)
    {
        throw std::runtime_error("A player's ship can hold a maximum of 5 cards.");
    }
    ship.push_back(card);
}

void Player::spendMoney(int amount)
{
    if (amount > money)
    {
        throw std::runtime_error("Insufficient funds.");
    }
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

void Player::addScore(int points)
{
    score += points;
}
