// Nathan Goldberg
// ECE205 Homework 2 Problem #2


#include <iostream>
#include <cstdlib>
#include <cmath>

const size_t LINE_LEN = 256;
const size_t NUM_SCORES = 5;


// function to calculate the mean value of an array of doubles
double mean(double nums[], size_t numsLen) {
    double tot = 0;

    // find the total value of all the elements
    for (size_t i = 0; i < numsLen; i++) {
        tot += nums[i];
    }

    // return the sum of all the elements / number of elements
    return tot / numsLen;
}


double sampleStdDev(double nums[], size_t numsLen) {
    // calculate the sample mean of nums array
    double sampleMean = mean(nums, numsLen);
    double totalSumSquares = 0;

    // find the total sum of squares by adding up the square of the difference between each element and the sample mean
    for (size_t i = 0; i < numsLen; i++) {
        totalSumSquares += pow(nums[i] - sampleMean, 2);
    }

    // find variance by dividing total sum of squares by N - 1
    double variance = totalSumSquares / (numsLen - 1);

    // return square root of variance = standard deviation
    return sqrt(variance);
}


int main() {
    // set floating point output precision to 2 decimal points
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
    
    /* *** couldn't find in notes about C++ file handling so I'm doing it how I know in C-style */

    // initialize file pointer and line array for reading file
    FILE *filePtr;
    char line[LINE_LEN];

    // check if scores.txt exists and can be read
    if ((filePtr = fopen("scores.txt", "r")) == NULL) {
        std::cout << "cant open scores.txt file bruh\n";
        return 1;
    }

    double examScores[NUM_SCORES];

    // iterate through scores.txt line by line
    for (size_t i = 0; i < NUM_SCORES; i++) {
        // use fgets to get the next line, check if it reaches end of file (occurs if file is <5 lines long)
        if (fgets(line, sizeof(line), filePtr) == NULL)
            break;

        // populate examScores array with float values from scores.txt
        examScores[i] = atof(line);
    }

    // calculate mean and stdDev of scores sample from above functions
    double scoresMean = mean(examScores, NUM_SCORES);
    double scoresStdDev = sampleStdDev(examScores, NUM_SCORES);

    // output mean and stdDev of scores to terminal
    std::cout << "mean score: " << scoresMean << std::endl;
    std::cout << "sample standard deviation of scores: " << scoresStdDev << std::endl;

    // close scores.txt file pointer
    fclose(filePtr);

    // open output.txt to write to
    if ((filePtr = fopen("output.txt", "w")) == NULL) {
        std::cout << "cant open output.txt file bruh\n";
        return 1;
    }

    // write mean and std dev to output.txt
    fprintf(filePtr, "Average: %.2lf\n", scoresMean);
    fprintf(filePtr, "Standard Deviation: %.2lf\n", scoresStdDev);

    // close file pointer
    fclose(filePtr);

    return 0;
}
