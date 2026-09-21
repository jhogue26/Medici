/*
 * Program name: auction.cpp
 * Author: Justin Hogue
 * Last modified: 09/20/2023
 * Purpose: Implements the Auction class.
*/

#include "auction.h"
#include <iostream>
#include <stdexcept>

Auction::Auction()
{
    currentBid = 0;
    highestBidder = -1;
}

void Auction::addCard(const Card& card)
{
    if (cards.size() >= 4)
    {
        throw std::runtime_error("An auction must have between 1 and 3 cards.");
    }
    cards.push_back(card);
}

void Auction::displayCards() const
{
    std::cout << "\nCards up for auction:\n";
    for (const Card& card : cards)
    {
        std::cout << card << std::endl;
    }
}

void Auction::startAuction(std::vector<Player>& players)
{
    currentBid = 0;
    highestBidder = -1;

    std::cout << "\nStarting auction...\n";
    displayCards();

    for (size_t i = 0; i < players.size(); ++i)
    {
        int bidAmount;
        std::cout << players[i].getName() << ", enter your bid (or 0 to pass): ";
        std::cin >> bidAmount;

        if (bidAmount > 0)
        {
            placeBid(static_cast<int>(i), bidAmount);
        }
    }

    if (highestBidder != -1)
    {
        std::cout << players[highestBidder].getName() << " wins the auction with a bid of " << currentBid << "!\n";
        players[highestBidder].spendMoney(currentBid);
        for (const Card& card : cards)
        {
            players[highestBidder].addCard(card);
        }
    }
    else
    {
        std::cout << "No bids were placed. The auction ends with no winner.\n";
    }
}

int Auction::getCardCount() const
{
    return static_cast<int>(cards.size());
}

int Auction::getHighestBid() const
{
    return currentBid;
}   

int Auction::getHighestBidder() const
{
    return highestBidder;
}   

void Auction::placeBid(int playerIndex, int bidAmount)
{
    if (bidAmount <= currentBid)
    {
        throw std::runtime_error("Bid must be higher than the current bid.");
    }
    currentBid = bidAmount;
    highestBidder = playerIndex;
}
