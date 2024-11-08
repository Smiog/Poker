#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <random>

class Deck
{
private:
    std::vector<Card> cards;

public:
    Deck() {};

    Deck(std::vector<Card> cards) { this->cards = cards; }

    std::vector<Card> getDeck() { return this->cards; }

    int getNum() { return (int)this->cards.size(); }

    void init()
    {
        this->cards.clear();
        for (int point = 1; point <= 13; ++point)
            for (int suit = 0; suit < 4; ++suit)
                this->cards.push_back(Card(point, suit));
    }

    void shuffle(unsigned seed = 0)
    {
        std::mt19937 rnd(seed);
        std::vector<Card> tmp;
        while (!this->cards.empty())
        {
            int id = rnd() % this->cards.size();
            tmp.push_back(this->cards[id]);
            this->cards.erase(this->cards.begin() + id);
        }
        this->cards = tmp;
    }

    Card deal()
    {
        Card card = cards.back();
        cards.pop_back();
        return card;
    }
};

#endif // DECK_H
