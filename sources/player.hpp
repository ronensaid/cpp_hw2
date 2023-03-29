#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

using namespace std;

namespace ariel {

class Player {
private: 
    string Pname; // player name

public:
    Player(string Pname);// constructor according to Demo.cpp

    int stacksize();
    int cardesTaken();
};

}
#endif