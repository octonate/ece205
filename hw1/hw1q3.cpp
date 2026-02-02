// Nathan Goldberg
// ECE 205 HW1 problem 3

#include <ios>
#include <iostream>
#include <ostream>
#include <iomanip>

int main() {
    // set precision for cout floats to 2 digits past the decimal point
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);

    double balance = 1000;
    double interestTot = 0;
    double paymentTot = 0;

    // print table header
    std::cout << "Month #      Interest      Principal      Balance      Total Interest      Total Paid\n";

    // loop through months until balance due reaches 0
    for (int month = 1; balance > 0; month++) {
        // calculate interest for the month, add to total interest
        double interest = 0.015 * balance;
        interestTot += interest;

        // calculate principal paid for the month
        double principal = 50.0 - interest;
        // check if total payment should be < $50 and recalculate principal if so
        if (balance - 50 - interest < 0) {
            principal = balance;
            paymentTot += principal + interest;
        } else {
            paymentTot += 50;
        }

        balance -= principal;

        // output all the values in the table, right align and use std::setw() to to line each column up with header
        std::cout << std::right
            << std::setw(7) << month
            << std::setw(14) << interest
            << std::setw(15) << principal
            << std::setw(13)<< balance
            << std::setw(20) << interestTot
            << std::setw(16) << paymentTot << std::endl;
    }

    return 0;
}
