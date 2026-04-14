// Nathan Goldberg
// ECE205 HW5 problem 4

#include <cmath>
#include <iostream>
#include <iterator>

// prime number class with value member variable
class PrimeNumber {
    public:
        PrimeNumber();
        PrimeNumber(int val);
        int getVal();
        PrimeNumber operator++();
        PrimeNumber operator++(int);
        PrimeNumber operator--();
        PrimeNumber operator--(int);
    private:
        int val;
};

// function that checks if a number is prime by looping through all possible divisors 2 through sqrt(n) and checking if it divides evenly
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= ceil(sqrt(n)); i++) {
        if (n % i == 0 && n != i) {
            return false;
        }
    }
    return true;
}

// PrimeNumber constructor functions
PrimeNumber::PrimeNumber() : val(2) {}; // *** i am breaking the rules and setting default constructor value to 2 since 1 is not a prime number
PrimeNumber::PrimeNumber(int val) : val(val) {};

// ++ operator loop through consecutive values until it is prime
PrimeNumber PrimeNumber::operator++() {
    int n = val + 1;
    while (isPrime(n) == false) {
        n++;
    }
    return PrimeNumber(n);
}

// supposedly for postfix you need to put the random int
PrimeNumber PrimeNumber::operator++(int) {
    return ++PrimeNumber(val);
}

// -- operator loop through decreasing values until a prime is found
PrimeNumber PrimeNumber::operator--() {
    if (val < 2)
        return PrimeNumber(2);

    int n = val - 1;
    while (isPrime(n) == false) {
        n--;
    }
    return PrimeNumber(n);
}

PrimeNumber PrimeNumber::operator--(int) {
    return --PrimeNumber(val);
}

// get val of PrimeNumber member variable
int PrimeNumber::getVal() {
    return val;
}



int main() {
    // test program to display first 10 primes above 100 using ++ overloaded operator
    std::cout << "First 10 primes above 100: " << std::endl;
    PrimeNumber num = PrimeNumber(100);
    for (int i = 0; i < 10; i++) {
        num = ++num;
        std::cout << num.getVal() << std::endl;
    }

    // test -- overloaded operator by displaying decreasing primes under 100
    std::cout << "First 10 primes above under 100: " << std::endl;
    num = PrimeNumber(100);
    for (int i = 0; i < 10; i++) {
        num = num--;
        std::cout << num.getVal() << std::endl;
    }

    return 0;
}
