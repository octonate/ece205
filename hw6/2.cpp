// Nathan Goldberg
// ECE205 HW 6 problem 2

#include <iostream>
#include <vector>


void selectionSort(std::vector<char> &myVector) {
    for (int i = 0; i < myVector.size(); i++) {
        // find index of highest character after index i
        int maxIdx = i;
        for (int j = i; j < myVector.size(); j++) {
            if (myVector[j] > myVector[maxIdx]) {
                maxIdx = j;
            }
        }

        // swap the values at i and the index of maximum value between i and the end
        char tmp = myVector[i];
        myVector[i] = myVector[maxIdx];
        myVector[maxIdx] = tmp;
    }
}

// function to check if a character is in a vector
bool isInVector(std::vector<char> &myVector, char ch) {
    bool result = false;
    for (int i = 0; i < myVector.size(); i++) {
        if (myVector[i] == ch) {
            result = true;
        }
    }
    return result;
}

// function to delete in place repeated characters in a vector
void deleteRepeatedChars(std::vector<char> &myVector) {
    // create vector to represent all the characters that have been seen before
    std::vector<char> seen;

    // loop through all elements of vector
    for (int i = 0; i < myVector.size(); i++) {

        // check if current element has been seen before
        if (isInVector(seen, myVector[i])) {
            // if current element has been seen before, move each element of the rest of the array down by one element
            for (int j = i; j < myVector.size() - 1; j++) {
                myVector[j] = myVector[j+1];
            }
            // remove the final element because it is repeated
            myVector.pop_back();
            // subtract one from i to start back at previous index, this is for cases where multiple repeated letters are inputted in a row
            i--;
        } else {
            // if current element has not been seen, add it to the seen vector
            seen.push_back(myVector[i]);
        }
    }
}

// print character vector
void printVector(const std::vector<char> &myVector) {
    for (int i = 0; i < myVector.size(); i++) {
        std::cout << myVector[i] << std::endl;
    }
}

int main() {
    std::vector<char> chars;

    // get chars vector from user
    char newChar = 1;
    while (newChar != '0') {
        std::cout << "Enter a character: ";
        std::cin >> newChar;

        if (newChar != '0') {
            chars.push_back(newChar);
        }
    }

    // delete repeated characters
    deleteRepeatedChars(chars);
    // sort character vector 
    selectionSort(chars);
    // print character vector
    printVector(chars);


    return 0;
}
