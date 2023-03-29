#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>

using namespace std;

namespace ariel {

class Card{
private:
    int value;// value of the card
    string type;// type of the card

public:
    Card(int value, string type);//constructor

};

}

#endif