#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

std::vector<int> arrayOfNumbers = {42, 5, 11, 7, 2, 4};
int sumOfNumbers = 16;

// Simple solution using loops
void solutionUsingLoop() {
    for (size_t i = 0; i < arrayOfNumbers.size() - 1; ++i) {
        for (size_t j = i + 1; j < arrayOfNumbers.size(); ++j) {
            if (sumOfNumbers == arrayOfNumbers[i] + arrayOfNumbers[j]) {
                std::cout << arrayOfNumbers[i] << " " << arrayOfNumbers[j] << std::endl;
            }
        }
    }
}

// Two pointer solution
void solutionUsingTwoPointer() {
    std::sort(arrayOfNumbers.begin(), arrayOfNumbers.end());
    size_t l = 0;
    size_t r = arrayOfNumbers.size() - 1;
    while (l < r) {
        if (arrayOfNumbers[l] + arrayOfNumbers[r] == sumOfNumbers) {
            std::cout << arrayOfNumbers[l] << " " << arrayOfNumbers[r] << std::endl;
            break;
        } else if (arrayOfNumbers[l] + arrayOfNumbers[r] < sumOfNumbers) {
            ++l;
        } else {
            --r;
        }
    }
}

// Hashing method
void solutionUsingHashing() {
    std::unordered_set<int> dataSet;
    for (size_t i = 0; i < arrayOfNumbers.size(); ++i) {
        int temp = sumOfNumbers - arrayOfNumbers[i];
        if (dataSet.find(temp) != dataSet.end()) {
            std::cout << arrayOfNumbers[i] << " " << temp << std::endl;
        }
        dataSet.insert(arrayOfNumbers[i]);
    }
}

int main() {
    solutionUsingLoop();
    solutionUsingTwoPointer();
    solutionUsingHashing();

    return 0;
}
