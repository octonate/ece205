// Nathan Goldberg
// ECE205 HW#4 Problem 1

#include <iostream>

const int MAX_ARR_LEN = 64;

void fillArr(int arr[], int &arrLen, const int maxArrLen) {
    // get array size from user, check if it is larger than max arr length
    std::cout << "Input size of array to be filled: ";
    std::cin >> arrLen;
    if (arrLen > maxArrLen) {
        arrLen = maxArrLen;
        std::cout << "Too large, max array size is " << arrLen << std::endl;
    }

    // fill array with elements from user
    std::cout << "Input numbers at indeces: " << std::endl;

    for (int i = 0; i < arrLen; i++) {
        // initialize current array element to 0
        arr[i] = 0;

        // get new element from user, check if it is < 0
        do {
            std::cout << "[" << i << "] : ";
            std::cin >> arr[i];
            if (arr[i] < 0) {
                std::cout << "Number must be non-negative! try again" << std::endl;
            }
        } while (arr[i] < 0);
    }
}

void fillHist(int hist[], int &numBins, int arr[], int arrLen, const int maxArrLen) {
    // find maximum value in the array to determine number of bins needed for histogram
    int max = 0;
    for (int i = 0; i < arrLen; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // calculate number of bins needed for bins of size 10
    numBins = max / 10 + 1;

    // check if numBins is greater than max arr len
    if (numBins > maxArrLen) {
        numBins = maxArrLen;
        std::cout << "Maximum value in array is too large; histogram will be truncated." << std::endl;
    }

    // initialize histogram to 0 elements for every bin
    for (int i = 0; i < maxArrLen; i++) {
        hist[i] = 0;
    }

    // go through each element in array and increment the number in the bin it belongs to
    for (int i = 0; i < arrLen; i++) {
        // calculate which bin the current element belongs to
        int curBin = arr[i] / 10;
        
        // check if this bin is out of bounds; if not, increment its value
        if (curBin <= numBins) {
            hist[curBin]++;
        }
    }
}

void outputHist(int hist[], int numBins) {
    // loop through hist array and output in format "bin i : n values"
    for (int i = 0; i < numBins; i++) {
        std::cout << "bin " << i + 1 << " : " << hist[i] << " values" << std::endl;
    }
}

int main() {
    // define array and histogram and their length variables
    int arr[MAX_ARR_LEN];
    int histogram[MAX_ARR_LEN];
    int arrLen;
    int numBins;

    // fill user specified array
    fillArr(arr, arrLen, MAX_ARR_LEN);

    // fill histogram array based on user specified array
    fillHist(histogram, numBins, arr, arrLen, MAX_ARR_LEN);

    std::cout << std::endl;

    // display histogram as a list of bins and values
    outputHist(histogram, numBins);


    return 0;
}
