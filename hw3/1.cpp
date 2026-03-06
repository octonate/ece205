// Nathan Goldberg
// ECE205 Homework #3 problem 1

#include <iostream>

// function to get input from user
int input(int &hours, int &mins) {
    std::cout << "Input hour: ";
    std::cin >> hours;
    std::cout << "Input minutes: ";
    std::cin >> mins;

    // return value of -1 means user wants to stop entering times
    if (hours < 0 || mins < 0) {
        return -1;
    }
    else {
        return 0;
    }
}

// convert 24 hour inputs to 12 hour time, using call by reference for variable outputs
void conversion(int hoursIn, int minsIn, int &hoursOut, int &minsOut, char &period) {
    hoursOut = hoursIn % 12;
    minsOut = minsIn;
    
    if (hoursIn < 12) {
        period = 'A';
    } else {
        period = 'P';
    }
}

// function that prints time in neat way (repurposed from midterm problem since it does exactly what I need)
void printTime(int hour, int min, char period) {
    if (period != 0 && hour == 0) { // special case for 00:00 to become 12:00 AM
        std::cout << 12;
    } else if (hour < 10) {
        if (period == 0) {
            std::cout << 0;
        }
        std::cout << hour;
    } else {
        std::cout << hour;
    }
    
    std::cout << ':';

    if (min < 10) {
        std::cout << 0 << min;
    } else {
        std::cout << min;
    }

    if (period == 'A') {
        std::cout << " AM";
    } else if (period == 'P') {
        std::cout << " PM";
    }

    std::cout << std::endl;

}

int main() {
    // initialize all inputs/outputs to 0
    int hours24 = 0;
    int mins24 = 0;
    int hours12 = 0;
    int mins12 = 0;
    char period = 0;

    // repeat time conversion until user inputs a negative number
    while (input(hours24, mins24) == 0) {
        conversion(hours24, mins24, hours12, mins12, period);
        printTime(hours12, mins12, period);
    }

    return 0;
}
