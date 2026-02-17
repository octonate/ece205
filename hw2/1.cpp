// Nathan Goldberg
// ECE205 Homework 2 Problem #1


#include <iostream>
#include <cmath>

// function that calculates the gravitational force
double gravForce_dyn(double m1_kg, double m2_kg, double d_cm) {
    const double G = 0.00000006673;
    double m1_g = m1_kg * 1000;
    double m2_g = m2_kg * 1000;
    return G * m1_g * m2_g / pow(d_cm, 2);
}

int main() {
    // initialize variables
    char again = 'n';
    double m1 = 0;
    double m2 = 0;
    double d = 0;

    // do while loop so user can do many calculations
    do {
        // get mass and distance values from user
        std::cout << "input mass 1 (kg): ";
        std::cin >> m1;

        std::cout << "input mass 2 (kg): ";
        std::cin >> m2;

        std::cout << "input distance (cm): ";
        std::cin >> d;

        // calculate force using gravForce_dyn function
        double F = gravForce_dyn(m1, m2, d);
        std::cout << "gravitational force is " << F << " dyn" << std::endl;

        // prompt the user to input another number
        std::cout << "would you like to calculate again? (y/n)" << std::endl;
        std::cin >> again;
    } while (again == 'y');

    return 0;
}
