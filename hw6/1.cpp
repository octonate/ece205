// Nathan Goldberg
// ECE205 HW 6 problem 1

#include <iostream>
#include <vector>

// function to return the maximum value of an int vector
int maxVectorElement(const std::vector<int> &nums) {
    int max = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

// generate bins given vector of numbers
std::vector<int> makeBins(const std::vector<int> &nums) {
    // find the number of bins needed by looking at the max number in the list
    int maxVal = maxVectorElement(nums);
    int numBins = maxVal / 10 + 1;
    std::vector<int> bins(numBins);

    // loop through list of nums and increment value at each bin it belongs to
    for (int i = 0; i < nums.size(); i++) {
        int curBin = nums[i] / 10;
        bins[curBin]++;
    }

    return bins;
}

// print each bin and how many elements it has
void printBins(const std::vector<int> &bins) {
    for (int i = 0; i < bins.size(); i++) {
        std::cout << "Bin " << i + 1 << ": " << bins[i] << " elements" << std::endl;
    }
}

int main() {
    std::vector<int> nums;

    // get nums vector from user
    int newNum = 0;
    while (newNum >= 0) {
        std::cout << "Enter a number: ";
        std::cin >> newNum;

        if (newNum >= 0) {
            nums.push_back(newNum);
        }
    }

    // make bins and print bins
    std::vector<int> bins = makeBins(nums);
    printBins(bins);

    return 0;
}
