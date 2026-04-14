// Nathan Goldberg
// ECE205 HW5 problem 2

#include <iostream>

// define enum types for size and types of pizza
enum PizzaType {
    DEEP_DISH,
    HAND_TOSSED,
    PAN
};

enum PizzaSize {
    SMALL,
    MEDIUM,
    LARGE
};

// create pizza class
class Pizza {
    public:
        void setSize(PizzaSize pizzaSize);
        void setType(PizzaType pizzaType);
        void setNumToppings(int pizzaNumToppings);

        PizzaSize getSize(void);
        PizzaType getType(void);
        int getNumToppings(void);
    private:
        PizzaType type;
        PizzaSize size;
        int numToppings;
};

void Pizza::setSize(PizzaSize pizzaSize) {
    size = pizzaSize;
}

void Pizza::setType(PizzaType pizzaType) {
    type = pizzaType;
}

void Pizza::setNumToppings(int pizzaNumToppings) {
    numToppings = pizzaNumToppings;
}

PizzaSize Pizza::getSize(void) {
    return size;
}

PizzaType Pizza::getType(void) {
    return type;
}

int Pizza::getNumToppings(void) {
    return numToppings;
}

// output description of Pizza class
void outputDescription(Pizza pizza) {
    std::cout << "Pizza info:" << std::endl;
    std::cout << "Size: ";
    switch (pizza.getSize()) {
    case SMALL:
        std::cout << "Small" << std::endl;
        break;
    case MEDIUM:
        std::cout << "Medium" << std::endl;
        break;
    case LARGE:
        std::cout << "Large" << std::endl;
        break;
    }

    std::cout << "Type: ";
    switch (pizza.getType()) {
    case DEEP_DISH:
        std::cout << "Deep Dish" << std::endl;
        break;
    case HAND_TOSSED:
        std::cout << "Hand Tossed" << std::endl;
        break;
    case PAN:
        std::cout << "Pan" << std::endl;
        break;
    }

    std::cout << "Number of Toppings: " << pizza.getNumToppings() << std::endl;
}

// compute price for a Pizza
double computePrice(Pizza pizza) {
    double price = pizza.getNumToppings() * 2;
    switch (pizza.getSize()) {
    case SMALL:
        price += 10;
        break;
    case MEDIUM:
        price += 14;
        break;
    case LARGE:
        price += 17;
        break;
    }

    return price;
}

int main() {
    // define 3 sample pizzas
    Pizza pizza1, pizza2, pizza3;

    pizza1.setSize(MEDIUM);
    pizza1.setType(HAND_TOSSED);
    pizza1.setNumToppings(2);

    pizza2.setSize(SMALL);
    pizza2.setType(PAN);
    pizza2.setNumToppings(1);

    pizza3.setSize(LARGE);
    pizza3.setType(DEEP_DISH);
    pizza3.setNumToppings(0);

    // output description and price of each of the 3 pizzas
    std::cout << "Pizza 1: " << std::endl;
    outputDescription(pizza1);
    std::cout << "Price: $" << computePrice(pizza1) << std::endl;
    std::cout << std::endl;

    std::cout << "Pizza 2: " << std::endl;
    outputDescription(pizza2);
    std::cout << "Price: $" << computePrice(pizza2) << std::endl;
    std::cout << std::endl;

    std::cout << "Pizza 3: " << std::endl;
    outputDescription(pizza3);
    std::cout << "Price: $" << computePrice(pizza3) << std::endl;
    std::cout << std::endl;

    return 0;
}
