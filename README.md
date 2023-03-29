In this assignment we will implement the card game War for two players. There is a normal deck of cards with 52 cards at the beginning of the game the deck is shuffled (randomly) and divided equally between the two players. On each turn the players draw one card from the top of their pile and the player with the highest card takes both cards to him (2 Ace wins). If the players have drawn two identical cards then they place one card face down and a lesser card on top of it. The high card player takes all six cards. If there is a tie again, continue with a closed card followed by an open card until one of the players wins. The turn continues until one of the players takes the pot or runs out of cards. If you run out of cards while breaking a tie, each player takes the cards he threw (divide the pot half and half). The game continues until the players run out of cards and the winner is the player who took the most cards.

Examples of the class operation can be found in Demo.cpp.

In step one, you must write titles and comprehensive unit tests. Think about the departments you will build and what each department should contain. No need for inheritance.

Write all the necessary files so that the following commands work without errors:

make demo && ./demo
make test && ./test

It is also recommended to run:

make tidy
make valgrind

Please note: Do not change existing files, but only add new files. The automatic test system re-copies all existing files on top of the solution you submit, so any changes you make to the existing files will be deleted.
