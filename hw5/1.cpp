// Nathan Goldberg
// ECE205 HW5 problem 1

#include <iostream>

// create class with member functions to set distance, set time, and return the average speed (in mph)
// private member variables are distance traveled (in miles) and time elapsed (in minutes)
class BicycleSpeedometer {
    public:
        void setDistance(double distance);
        void setTime(double timeTravelled);
        double avgSpeed(void);
    private:
        int dist;
        int time;
};

// member function definitions to set private member variables
void BicycleSpeedometer::setDistance(double distance) {
    dist = distance;
}

void BicycleSpeedometer::setTime(double timeTravelled) {
    time = timeTravelled;
}

// returns average speed in mph
double BicycleSpeedometer::avgSpeed(void) {
    return 60.0 * dist / time;
}

int main() {
    // define variables and get user input
    double miles = 0;
    double mins = 0;
    std::cout << "Enter number of miles travelled: ";
    std::cin >> miles;
    std::cout << "Enter number of minutes elapsed: ";
    std::cin >> mins;

    // define BicycleSpeedometer class instance, set member variables to user specified inputs
    BicycleSpeedometer speedo;
    speedo.setDistance(miles);
    speedo.setTime(mins);

    // display average speed of the rider
    std::cout << "Average speed of the rider: " << speedo.avgSpeed() << " mph" << std::endl;
    return 0;
}
