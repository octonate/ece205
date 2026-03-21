// Nathan Goldberg
// ECE205 HW#4 Problem 3

#include <iostream>

void printSeats(char seats[10][4]) {
    // for loop through all rows 
    for (int i = 0; i < 10; i++) {
        // print row number
        std::cout << i + 1 << "   ";

        // add extra padding for 1-digit row numbers
        if (i < 9) {
            std::cout << " ";
        }

        // loop through all seats within row
        for (int j = 0; j < 4; j++) {
            std::cout << seats[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

int main() {
    // intialize seat pattern
    char seats[10][4] = {
        { 'A', 'B', 'C', 'D' },
        { 'A', 'B', 'C', 'D' },
        { 'A', 'B', 'C', 'D' },
        { 'A', 'B', 'C', 'D' },
        { 'A', 'B', 'C', 'D' },
        { 'A', 'B', 'C', 'D' },
        { 'A', 'B', 'C', 'D' },
        { 'A', 'B', 'C', 'D' },
        { 'A', 'B', 'C', 'D' },
        { 'A', 'B', 'C', 'D' }
    };

    bool adding = true;

    // keep looping until 'adding' variable gets set to false when user doesn't want to input any more seats
    while (adding == true) {
        // initialize current row and column variables
        int row = 0;
        int col = 0;
        char letter = 0;
        char repeat = 0;
        bool available = false;

        // display current seating arrangement
        std::cout << "Current seating pattern: " << std::endl;
        printSeats(seats);
        std::cout << std::endl;

        // repeat until available seat is inputted
        while (available == false) {
            // get row and seat letter from user
            std::cout << "Enter desired seat: " << std::endl;
            std::cout << "     Row number: ";
            std::cin >> row;
            std::cout << "    Seat letter: ";
            std::cin >> letter;

            // set col variable to 0, 1, 2, or 3 given seat letter
            switch (letter) {
            case 'A':
                col = 0;
                break;
            case 'B':
                col = 1;
                break;
            case 'C':
                col = 2;
                break;
            case 'D':
                col = 3;
                break;
            }

            // check if desired seat is taken, set variable available to corresponding bool value
            if (seats[row - 1][col] == 'X') {
                std::cout << "Seat " << row << letter << " is taken! try again" << std::endl;
                available = false;
            } else {
                available = true;
                seats[row - 1][col] = 'X';
            }
        }

        // ask user if they would like to input another seat and update adding variable accordingly
        std::cout << "Would you like to input another seat? (y/n): ";
        std::cin >> repeat;
        if (repeat == 'y') {
            adding = true;
        } else {
            adding = false;
        }

    }


    return 0;
}
