#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

#include "doctest.h"

using namespace ariel;
using namespace std;

TEST_CASE("in the beginning before playing any turn each player should have 26 cards and no logs or winner or lastTurn should be declared") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK_THROWS(game.printLastTurn());
    CHECK_THROWS(game.printWiner());
    CHECK_THROWS(game.printLog());
    CHECK((p1.stacksize() == 26));
    CHECK((p2.stacksize() == 26));
    CHECK((p1.cardesTaken() == 0));
    CHECK((p2.cardesTaken() == 0));
}

TEST_CASE("after all cards are played we will have a winner") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();

    //both players are supposed to have 0 cards in their stack
    REQUIRE(p1.stacksize() == 0);
    REQUIRE(p2.stacksize() == 0);
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLog());
    
}


TEST_CASE("After playing a turn each player should have 1 card less") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    int initialStackSize1 = p1.stacksize();
    int initialStackSize2 = p2.stacksize();

    game.playTurn();

    REQUIRE(p1.stacksize() == initialStackSize1 - 1);
    REQUIRE(p2.stacksize() == initialStackSize2 - 1);
    REQUIRE(p1.stacksize() == p2.stacksize());
}


TEST_CASE("playing against yourself should throw an exception and playing against another player is ok") {
    Player p1("Alice");
    Player p2("Bob");
    CHECK_THROWS(Game(p1, p1));
    CHECK_NOTHROW(Game(p1,p2));
}

TEST_CASE("creating a null player or noname player should not be possible") {
    CHECK_THROWS_AS(Player(NULL), invalid_argument);
    CHECK_THROWS_AS(Player(""), invalid_argument);
}

TEST_CASE("Total Number of Cards in the Game Should be 52") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    
    game.playTurn();
    game.playTurn();

    REQUIRE((p1.stacksize() + p1.cardesTaken() + p2.cardesTaken() + p2.stacksize() == 52));
}
TEST_CASE("when the game is finished you should not be able to play another turn") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    CHECK_THROWS(game.playTurn());
}

TEST_CASE("Game Should End in a Tie When Both Players Run Out of Cards in the Same Turn") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    // Play turns until both players have only one card left
    while (p1.stacksize() + p1.cardesTaken() > 1 && p2.stacksize() + p2.cardesTaken() > 1) {
        game.playTurn();
    }

    // Play one more turn
    game.playTurn();

    // Both players should have 0 cards left in their stack
    CHECK((p1.stacksize() == 0));
    CHECK((p2.stacksize() == 0));

    // Both players should have taken the same amount of cards
    CHECK((p1.cardesTaken() == p2.cardesTaken()));

    // The game should end in a tie which means it will print no winner 
    CHECK_THROWS(game.printWiner());
}

TEST_CASE("Game Should End in a Win When One Player Runs Out of Cards Before the Other") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    // Play turns until one player has no more cards
    while (p1.stacksize() + p1.cardesTaken() > 0 && p2.stacksize() + p2.cardesTaken() > 0) {
        game.playTurn();
    }

    // The winning player should have more than 0 cards taken
    if (p1.cardesTaken() > 0 || p2.cardesTaken() > 0) {
        CHECK_NOTHROW(game.printWiner());
    }
}



TEST_CASE("Printing Game Stats Should Not Throw an Exception") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK_NOTHROW(game.printStats());
}

TEST_CASE("Printing Game Log Should Not Throw an Exception") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK_NOTHROW(game.printLog());
}

TEST_CASE("Printing the Winner Should Not Throw an Exception") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK_NOTHROW(game.printWiner());
}

TEST_CASE("Printing the Last Turn Should Not Throw an Exception") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printLastTurn());
}
