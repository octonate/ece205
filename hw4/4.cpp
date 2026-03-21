// Nathan Goldberg
// ECE205 HW#4 Problem 4

#include <iostream>

// prints the tictactoe board
void printBoard(char board[9]) {
    std::cout << board[0] << "   " << board[1] << "   " << board[2] << std::endl << std::endl;
    std::cout << board[3] << "   " << board[4] << "   " << board[5] << std::endl << std::endl;
    std::cout << board[6] << "   " << board[7] << "   " << board[8] << std::endl << std::endl;
}

// win conditions when the following board indeces are equal to either 'X' or 'O':
// rows:
//  0, 1, 2
//  3, 4, 5
//  6, 7, 8
// cols:
//  0, 3, 6
//  1, 4, 7
//  2, 5, 8
// diags:
//  0, 4, 8
//  2, 4, 6

// function that returns whether or not if the game has ended;
// returns 0 if game is ongoing
// returns 1 if a win condition occurred
// returns -1 if a draw has occurred
int gameOver(char board[9]) {
    // massive if statment to check if a 3-in-a-row has occurred
        // check rows
    if ((board[0] == board[1] && board[1] == board[2]) ||
        (board[3] == board[4] && board[4] == board[5]) ||
        (board[6] == board[7] && board[7] == board[8]) ||

        // check columns
        (board[0] == board[3] && board[3] == board[6]) ||
        (board[1] == board[4] && board[4] == board[7]) ||
        (board[2] == board[5] && board[5] == board[8]) ||

        // check diagonals
        (board[0] == board[4] && board[4] == board[8]) ||
        (board[2] == board[4] && board[4] == board[6])) {

        return 1;
    }


    // check for draw, occurres when all characters on board are 'X' or 'O'
    bool isDraw = true;
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            isDraw = false;
        }
    }

    if (isDraw == true) {
        return -1;
    }

    return 0;
}


// checks if a position is valid on the given tictactoe board
bool isValidPos(char board[9], int pos) {
    // return false if position is out of bounds
    if (pos < 1 || pos > 9) {
        return false;
    }

    // return false if position is taken by a player already
    if (board[pos - 1] == 'X' || board[pos - 1] == 'O') {
        return false;
    }

    return true;
}

int main() {
    // initialize tictactoe board
    char board[9] = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9',
    };

    char curPlayer = 'X';
    int gameCondition = 0;

    // repeat game loop if game is ongoing
    while ((gameCondition = gameOver(board)) == 0) {
        int nextPos = 0;
        bool validPos = false;
        printBoard(board);

        // repeat getting player's position until position is valid
        while (validPos == false) {
            std::cout << "Player " << curPlayer << ", enter your position: ";
            std::cin >> nextPos;

            // assign validPos variable to the output of isValidPos function, and check if it returned false
            if ((validPos = isValidPos(board, nextPos)) == false) {
                std::cout << "Invalid position! try again" << std::endl;
            }
        }

        // update board state with new move
        board[nextPos - 1] = curPlayer;

        // switch current player to the next player
        if (curPlayer == 'X') {
            curPlayer = 'O';
        } else {
            curPlayer = 'X';
        }
    }

    // print final board state
    printBoard(board);

    // when loop ends, game is over
    std::cout << "GAME OVER: " << std::endl;

    // output game over message
    if (gameCondition == -1) {
        std::cout << "DRAW!" << std::endl;;

    // if not a draw, X or Y must have won. if loop stopped when curPlayer == 'X', player 'O' won and if loop stopped when curPlayer == 'O', player 'X' won
    } else if (curPlayer == 'X') {
        std::cout << "PLAYER O WINS!" << std::endl;;
    } else {
        std::cout << "PLAYER X WINS!" << std::endl;;
    }
    

    return 0;
}
