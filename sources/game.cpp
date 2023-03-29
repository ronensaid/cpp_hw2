#include "game.hpp"
#include <iostream>

using namespace std;

namespace ariel{

    Game::Game(Player &p1, Player &p2): player1(p1), player2(p2){
        // initialize the game with the given players
    }

    void Game::playTurn(){
        // play a single turn of the game
        // implement the game logic here
    }

    void Game::printLastTurn(){
        // print the last turn played
        // format: "[Player Name] played [Card Value] of [Card Suit]"
        // example: "Alice played 5 of Hearts"
    }

    void Game::playAll(){
        // play the game until the end
        // keep track of each turn using a log
        // use a while loop that ends when one player wins or the deck is empty
    }

    void Game::printWiner(){
        // print the name of the winning player
    }

    void Game::printLog(){
        // print the log of all turns played
        // format: "[Turn Number]: [Player Name] played [Card Value] of [Card Suit]"
    }

    void Game::printStats(){
        // print basic statistics for each player
        // format: "[Player Name]: [Win Rate], [Cards Won], [Other Stats...]"
        // also print the draw rate and amount of draws that occurred
    }

}
