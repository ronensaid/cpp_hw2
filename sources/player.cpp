#include "player.hpp"

namespace ariel {

    Player::Player(string Pname): Pname(Pname) {
        // constructor
    }

    int Player::stacksize() {
        // return the number of cards in the player's stack
        return 0;
    }

    int Player::cardesTaken() {
        // return the number of cards the player has taken
        return 0;
    }

} 
