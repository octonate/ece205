// Nathan Goldberg
// ECE 205 Hw 2 Problem 3

#include <iostream>

// calculate hat size with given formula
double sizeHat(double weight_lbs, double height_in) {
    return 2.9 * weight_lbs / height_in;
}

// calculate jacket size with given formula
double sizeJacket(double weight_lbs, double height_in, int age_yrs) {
    double size = height_in * weight_lbs / 288.0;
    if (age_yrs > 30) {
        int decadesOver30 = (age_yrs - 30) / 10;
        size += 0.125 * decadesOver30;
    }

    return size;
}

// calculate waist size with given formula
double sizeWaist(double weight_lbs, int age_yrs) {
    double size = weight_lbs / 5.7;
    if (age_yrs > 28) {
        int bienniumsOver28 = (age_yrs - 28) / 2;
        size += 0.1 * bienniumsOver28;
    }

    return size;
}

int main() {
    // intitialize height weight and age variables
    double height = 0;
    double weight = 0;
    int age = 0;

    // get inputs from user
    std::cout << "enter your height (in): ";
    std::cin >> height;
    std::cout << "enter your weight (lbs): ";
    std::cin >> weight;
    std::cout << "enter your age (years): ";
    std::cin >> age;

    // calculate clothing sizes using the functions above
    double hatSize = sizeHat(weight, height);
    double jacketSize = sizeJacket(weight, height, age);
    double waistSize = sizeWaist(weight, age);

    // output sizes to the terminal
    std::cout << "hat size: " << hatSize << std::endl;
    std::cout << "jacket size: " << jacketSize << std::endl;
    std::cout << "waist size: " << waistSize << std::endl;

    return 0;
}
