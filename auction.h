#ifndef AUCTION_H
#define AUCTION_H

#include <vector>
#include "player.h"
#include "card.h"

class Auction 
{
private:
    std::vector<Card> cards;
    int currentBid;
    int highestBidder;

public:
    // Constructor
    Auction();

    void addCard(const Card& card);
    void displayCards() const;
    void startAuction(std::vector<Player>& players);

    int getCardCount() const;
    int getHighestBid() const;
    int getHighestBidder() const;

    void placeBid(int playerIndex, int bidAmount);
};

#endif // AUCTION_H
    