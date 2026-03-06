// Nathan Goldberg
// ECE 205 HW3 problem 2

#include <iostream>
#include <cmath>

void triangle(double a, double b, double c, double &area, double &perimeter) {
    // triangle inequality theorem: triangle can be made if the following conditions are met:
    // a + b > c
    // a + c > b
    // b + c > a
    if (!(a + b > c && a + c > b && b + c > a)) {
        perimeter = 0;
        area = 0;
        return;
    }

    // calculate perimeter and area
    perimeter = a + b + c;
    double s = perimeter / 2;
    area = std::sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    // define variables;
    double a = 0;
    double b = 0;
    double c = 0;
    double area = 0;
    double perimeter = 0;

    // get side lengths a, b, and c from user
    std::cout << "enter side length a: ";
    std:: cin >> a;
    std::cout << "enter side length b: ";
    std:: cin >> b;
    std::cout << "enter side length c: ";
    std:: cin >> c;

    // run triangle function to get area and perimeter outputs
    triangle(a, b, c, area, perimeter);

    // output calculated values
    std::cout << "calculated area: " << area << std::endl;
    std::cout << "calculated perimeter: " << perimeter << std::endl;

    return 0;
}
