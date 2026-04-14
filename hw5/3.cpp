// Nathan Goldberg
// ECE205 HW5 problem 3

#include <iostream>

const int ARR_LEN = 32;

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

        Pizza(PizzaSize pizzaSize, PizzaType pizzaType, int pizzaNumToppings);
        Pizza();
    private:
        PizzaType type;
        PizzaSize size;
        int numToppings;
};

// constuctors for default Pizza class and custom Pizza
Pizza::Pizza() : type(HAND_TOSSED), size(MEDIUM), numToppings(0) {};
Pizza::Pizza(PizzaSize pizzaSize, PizzaType pizzaType, int pizzaNumToppings) : type(pizzaType), size(pizzaSize), numToppings(pizzaNumToppings) {};

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


// order class with member variables for the vector of Pizzas and the number of pizzas
class Order {
    public:
        void addPizza(Pizza pizza);
        void outputOrder();
        Order();
    private:
        Pizza pizzas[ARR_LEN];
        int numPizzas;
};

// constructor for Order class to set numPizzas to 0
Order::Order() : numPizzas(0) {};

// function to add pizza to order
void Order::addPizza(Pizza pizza) {
    pizzas[numPizzas] = pizza;
    numPizzas++;
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

// output order by calling Pizza class's member functions and looping through pizzas vector
void Order::outputOrder() {
    std::cout << "Order: " << std::endl;
    double totalPrice = 0;
    for (int i = 0; i < numPizzas; i++) {
        std::cout << "Pizza #" << i + 1 << ":" << std::endl;
        outputDescription(pizzas[i]);
        totalPrice += computePrice(pizzas[i]);
        std::cout << "Price: $" << computePrice(pizzas[i]) << std::endl;
        std::cout << std::endl;
    }
    std::cout << "Total price: $" << totalPrice << std::endl;
}

int main() {
    // define 3 sample pizzas
    Pizza pizza1(MEDIUM, HAND_TOSSED, 2);
    Pizza pizza2(SMALL, PAN, 1);
    Pizza pizza3(LARGE, DEEP_DISH, 0);

    // add 3 sample pizzas to order and output
    Order order = Order();
    order.addPizza(pizza1);
    order.addPizza(pizza2);
    order.addPizza(pizza3);

    order.outputOrder();

    return 0;
}
