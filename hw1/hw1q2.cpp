// Nathan Goldberg
// ECE 205 HW1 problem 2

#include <ios>
#include <iostream>
#include <ostream>

int main() {
    // set precision for cout floats to 2 digits past the decimal point
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);

    // define constants for base and overtime pay
    const double BASE_PAY = 36.75;
    const double OVERTIME_PAY = BASE_PAY * 1.5;

    double hoursTot = 0;
    int dependents = 0;

    // get hours worked this week and number of dependents info from the user
    std::cout << "input hours worked this week: ";
    std::cin >> hoursTot;

    std::cout << "input number of dependents: ";
    std::cin >> dependents;

    double hoursOvertime = 0;
    double hoursBase = 0;

    // calculate base and overtime hours
    if (hoursTot > 40.0) {
        hoursBase = 40;
        hoursOvertime = hoursTot - 40.0;
    } else {
        hoursBase = hoursTot;
    }

    // calculate gross pay
    double payGross = BASE_PAY * hoursBase + OVERTIME_PAY * hoursOvertime;

    // calculate taxes
    // total percentage taxes taken is 6% + 15% + 4% + 1% = 26%
    double tax = 0.26 * payGross + 20;

    if (dependents >= 2) {
        tax += 40;
    }

    // calculate take home pay
    double payTakeHome = payGross - tax;

    // output pross pay and take home pay to the terminal
    std::cout << "gross pay: $" << payGross << std::endl;
    std::cout << "take home pay: $" << payTakeHome << std::endl;

    return 0;
}
