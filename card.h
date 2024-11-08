#ifndef CARD_H
#define CARD_H

class Card
{
private:
    int point, suit;

public:
    Card() {};

    Card(int point, int suit)
    {
        this->point = point;
        this->suit = suit;
    }

    int getPoint() const { return this->point; }

    int getSuit() const { return this->suit; }

    bool operator==(const Card &card) const { return this->point == card.point; }

    bool operator<(const Card &card) const { return this->point < card.point; }

    bool operator>(const Card &card) const { return this->point > card.point; }
};

#endif // CARD_H
