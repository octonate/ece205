// Nathan Goldberg
// ECE 205 Hw 2 Problem 4

#include <iostream>
#include <ctime>

const size_t NUM_WINNERS = 4;

// function that generates a random integer between min and max inclusive
int randInt(int min, int max) {
    return rand() % (max - min) + min;
}

// function that checks if num is an element in array arr
bool isNumInArray(int arr[], int num, size_t arrLen) {
    bool result = false;
    for (size_t i = 0; i < arrLen; i++) {
        if (arr[i] == num) {
            result = true;
            break;
        }
    }
    return result;
}

int main() {
    // set random seed to current time
    srand(time(0));

    // initialize winners array to 0
    int winners[NUM_WINNERS] = {0};

    // generate first random winner (guaranteed no repeats yet because first number)
    winners[0] = randInt(1, 25);
    // print first number generated
    std::cout << "all numbers generated (includes repeats):" << std::endl << winners[0] << std::endl;

    // generate 4 more winners
    for (size_t i = 1; i < NUM_WINNERS; i++) {
        int nextNum;

        // generate a next number, if this number is already in winners array then generate a new number
        do {
            nextNum = randInt(1, 25);

            // print every number generated to show that the code works even if repeat numbers is generated
            std::cout << nextNum << std::endl;
        } while (isNumInArray(winners, nextNum, i) == true);

        // put this unique number in the winners array
        winners[i] = nextNum;
    }

    // print winning numbers (without repeats)
    std::cout << std::endl << "all winners (no repeats):" << std::endl;
    for (size_t i = 0; i < NUM_WINNERS; i++) {
        std::cout << winners[i] << std::endl;
    }

    return 0;
}
