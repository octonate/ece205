// Nathan Goldberg
// ECE 205 HW1 problem 1

#include <ios>
#include <iostream>
#include <ostream>

int main() {
    // set precision for cout floats to 4 digits past the decimal point
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(4);

    // get total seconds input from user
    int secondsTot;
    std::cout << "input number of seconds: ";
    std::cin >> secondsTot;

    // calculate equivalent time in hours, minutes, seconds format
    int hours = secondsTot / 3600;
    int minutes = (secondsTot % 3600) / 60;
    int seconds = (secondsTot % 3600) % 60;

    std::cout << hours << " hours, " << minutes << " minutes, " << seconds << " seconds\n";

    // calculate equivalent time in hours
    double hoursTot = static_cast<double>(secondsTot) / 3600.0;
    std::cout << hoursTot << " hours\n";

    // calculate equivalent time in minutes
    double minutesTot = static_cast<double>(secondsTot) / 60.0;
    std::cout << minutesTot << " minutes\n";

    return 0;
}
