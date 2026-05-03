// Nathan Goldberg
// ECE205 homework 6 problem 3

#include <iostream>
#include <vector>

std::vector<int> erathosthenes(int N) {
    // create vector to represent at what indices are prime; 1 = prime, 0 = composite, initialize all elements to be prime
    std::vector<int> primesIdxs(N, 1);
    // set values 0 and 1 to composite
    primesIdxs[0] = 0;
    primesIdxs[1] = 0;
    // set first prime to 2
    int curPrime = 2;
    // loop through all primes below N/2
    while(curPrime < N/2) {
        // eliminate all indices of numbers that are an integer multiple of the current prime
        for (int i = 2; i * curPrime < N; i++) {
            primesIdxs[i * curPrime] = 0;
        }
        // update the current prime to the next-largest prime
        do {
            curPrime++;
        } while (primesIdxs[curPrime] == 0);
    }

    // after doing the sieve with all primes < N/2, the only indices left with a value of 1 will be prime
    // loop through all primeIdxs to find the remaining primes and add to prime vector
    std::vector<int> primes;
    for (int i = 0; i < N; i++) {
        if (primesIdxs[i] == 1) {
            primes.push_back(i);
        }
    }
    return primes;
}

// print integer vector
void printVector(const std::vector<int> &myVector) {
    for (int i = 0; i < myVector.size(); i++) {
        std::cout << myVector[i] << std::endl;
    }
}


int main() {
    // get N from user
    int N = 0;
    std::cout << "Enter N: ";
    std::cin >> N;

    // get vector for all primes < N and print
    std::vector<int> primes = erathosthenes(N);
    printVector(primes);

    return 0;
}
