// Nathan Goldberg
// ECE205 HW#4 Problem 2

#include <iostream>

const int ARR_LEN = 7;

int main() {
    double scores[ARR_LEN];
    double difficulty = 0;

    // get degree of difficulty from user, making sure it is within range
    while (difficulty < 1.2 ||  difficulty > 3.8) {
        std::cout << "Enter difficulty of the dive: ";
        std::cin >> difficulty;

        if (difficulty < 1.2 || difficulty > 3.8) {
            std::cout << "Degree of difficulty must be in range 1.2 to 3.8! try again" << std::endl;
        }
    }

    // get each judge score from user and store it in scores array
    for (int i = 0; i < ARR_LEN; i++) {
        // while loop to repeat user entry if score is outside of range
        do {
            std::cout << "Enter Judge #" << i + 1 << "'s score: ";
            std::cin >> scores[i];

            if (scores[i] < 0 || scores[i] > 10) {
                std::cout << "Scores must be between 0 and 10! try again" << std::endl;
            }
        } while (scores[i] < 0 || scores[i] > 10);
    }
    
    // find highest and lowest judge score
    double highScore = 0;
    double lowScore = 10;

    for (int i = 0; i < ARR_LEN; i++) {
        if (scores[i] < lowScore) {
            lowScore = scores[i];
        }
        if (scores[i] > highScore) {
            highScore = scores[i];
        }
    }

    // calculate sum of all scores:
    double scoreSum = 0;
    for (int i = 0; i < ARR_LEN; i++) {
        scoreSum += scores[i];
    }

    // subtract highest and lowest score to remove them from the sum
    scoreSum = scoreSum - highScore - lowScore;

    // multiply sum by difficulty degree and 0.6 to get final score
    double finalScore = scoreSum * difficulty * 0.6;
    std::cout << "Final score: " << finalScore << std::endl;


    return 0;
}
