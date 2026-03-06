// Nathan Goldberg
// ECE205 Homework 3 problem 3

#include <iostream>
#include <ostream>


// function that prints time in neat way (repurposed from midterm code)
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


// edited function from midterm code
int timeMachine(int start, int end) {
    // initialize varaibles
    char startPeriod = 0;
    char endPeriod = 0;

    // separate hour and minutes from 4 digit integer
    int startHour = start / 100;
    int endHour = end / 100;
    int startMin = start % 100;
    int endMin = end % 100;

    // calculate difference of times
    int diff = 60 * endHour + endMin - (60 * startHour + startMin);
    // add 24 hours to the difference if start time is pm and end time is am so it wont end up negative
    if (start > end) {
        diff += 60 * 24;
    }
    std::cout << "Difference in minutes: " << diff << std::endl;
    return diff;
}

int main() {
    int start = 0;
    int end = 0;

    // get input from user
    std::cout << "Enter start time as integer: ";
    std::cin >> start;
    std::cout << "Enter end time as integer: ";
    std::cin >> end;
    std::cout << std::endl;

    timeMachine(start, end);

    return 0;
}
