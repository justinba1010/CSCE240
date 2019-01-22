/*  Justin Baum
    18 January 2019
    CSCE240 Multifiles Practice
*/

#include <iostream>

namespace Tictactoe {
    class Board {
        public:
            Board();
            int board[3][3];
            int turn;
            int winner;
            bool isover();
            bool makemove(int x, int y);
            void print();
            char printplayer(int player);
            
    };

    Board::Board() {
        // Initialize Board
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                board[i][j] = 0;
            }
        }
        turn = 1;
        winner = 0;
    };

    bool Board::isover() {
        for(int i = 0; i < 3; i++) {
            // Horizontals
            if(board[i][0] != 0 && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
                winner = board[i][0];
                return true;
            }
            // Verticals
            if(board[0][i] != 0 && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
                winner = board[0][i];
                return true;
            }
        }
        // Diagonals
        if(board[0][0] != 0 && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            winner = board[0][0];
            return true;
        }
        if(board[2][0] != 0 && board[2][0] == board[1][1] && board[2][0] == board[0][2]) {
            winner = board[0][0];
            return true;
        }
        bool filled = true;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                // Check for an empty block.
                filled &= board[i][j] != 0;
            }
        }
        return filled;
    };
    bool Board::makemove(int x, int y) {
        // Check if spot is open or if the game is over
        if(board[x][y] != 0 || isover()) {
            return false;
        };
        board[x][y] = turn;
        turn *= -1;
        return true;
    };
    void Board::print() {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                std::cout << printplayer(board[i][j]) << (j == 2 ? "" : "|");
            }
            std::cout << std::endl;
        }
    };
    char Board::printplayer(int turn) {
        switch(turn) {
            case 1:
                return 'X';
                break;
            case 0:
                return ' ';
                break;
            default:
                return 'O';
        }
    };
};