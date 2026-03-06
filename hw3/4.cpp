// Nathan Goldberg
// ECE 205 HW 3 problem 4

#include <iostream>

// get lbs and oz inputs from user
void getInputs(double &lbs, double &oz) {
    std::cout << "Enter number of pounds: ";
    std::cin >> lbs;
    std::cout << "Enter number of ounces: ";
    std::cin >> oz;
}

void convert(double lbsIn, double ozIn, double &kgOut, double &gOut) {
    // convert lbs and oz to one total value in lbs
    double lbsTot = lbsIn + ozIn / 16;
    // convert total lbs value into kg
    double kgTot = lbsTot / 2.2046;
    // truncate total kg to get kl output
    kgOut = static_cast<int>(kgTot);
    // take the fractional component left and multiply by 1000 to get grams output
    gOut = 1000 * (kgTot - kgOut);
}

// display converted units
void output(double kg, double g) {
    std::cout << "Equivalent to: " << std::endl;
    std::cout << kg << " kg and " << g << " g" << std::endl;
}


int main() {
    // initialize variables
    double lbs = 0;
    double oz = 0;
    double kg = 0;
    double g = 0;

    char quit = 0;

    // run the 3 functions in a loop until char 'q' is intered

    while (quit != 'n') {
        getInputs(lbs, oz);
        convert(lbs, oz, kg, g);
        output(kg, g);
        std::cout << "would you like to input another time? " << std::endl;
        std::cin >> quit;
    }

    return 0;
}
