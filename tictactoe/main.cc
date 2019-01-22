/*  Justin Baum
    22 January 2019
    CSCE240 Tic Tac Toe Practice
    Not in class
*/

#include <iostream>
#include "board.cc"
int main(int args, char* argv[]) {
    Tictactoe::Board board = Tictactoe::Board();
    while(!board.isover()) {
        // Print out prompt
        board.print();
        int x;
        int y;
        std::cout << "Player " << board.printplayer(board.turn) << " turn: " << std::endl;
        std::cin >> x;
        std::cin >> y;
        board.makemove(x,y);
    }
    board.print();

    return 0;
};