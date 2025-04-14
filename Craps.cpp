// Function definitions

#include <iostream>
#include <cstdlib>
#include <string>

int roll(int numSides) {
    int value;
    value = (rand() % numSides) + 1;
    return value;
}

void printDiceRoll(int die1, int die2) {
    int sum;
    sum = die1 + die2;
    std::cout << "Die 1: " << die1 << "\tSum: " << sum << std::endl;
    std::cout << "Die 2: " << die2 << std::endl << std::endl;
}

std::string firstThrow(int die1, int die2) {
    int sum = die1 + die2;
    if ((sum == 7) || (sum == 11)) {
        return "WIN\n";
    } else if ((sum == 2) || (sum == 3) || (sum == 12)) {
        return "LOSE\n";
    } else {
        return "Roll for Point: " + std::to_string(sum) + "\n";
    }
}

std::string pointThrow(int firstPoint, int die1, int die2) {
    int sum2 = die1 + die2;
    do {
        if (sum2 == firstPoint) {
            return "WIN\n";
        } else if (sum2 == 7) {
            return "LOSE\n";
        } else {
            return "KEEP rolling for point: " + std::to_string(firstPoint) + "\n";
        }
    } while (!(sum2 == firstPoint) || (sum2 == 7));
}
