#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.h"

class Player 
{
    private:
        std::string name;
        int money;
        std::vector<Card> ship;

    public:
        // Constructors
        Player(std::string name, int money);

        // Getters
        std::string getName() const;
        int getMoney() const;
        int getShipSize() const;
        int getShipValue() const;

        // Player actions
        void addCard(const Card& card);
        void spendMoney(int amount);
        void showShip() const;
};  

#endif // PLAYER_H