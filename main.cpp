//  Craps
// A game of chance based on dice rolls

#include <iostream>
#include <cstdlib>
#include <ostream>
#include <string>

// Define functions
int roll(int numSides); // Die toss, based on number of sides given

void printDiceRoll(int die1, int die2); // Output results of a roll

std::string firstThrow(int die1, int die2); // Output game status after first roll

std::string pointThrow(int firstPoint, int die1, int die2); // Output game status after second roll

int main() {
    // Get seed for randomization from user
    int seed = 0;
    std::cout << "Enter program seed: ";
    std::cin >> seed;
    std::cout << "\n";
    srand(seed);

    // Roll dice and input value to dieRolls
    int dieRoll1 = roll(6);
    int dieRoll2 = roll(6);
    int point = dieRoll1 + dieRoll2;

    // First roll, print roll, print status
    std::cout << "Craps First Throw\n\n";
    printDiceRoll(dieRoll1, dieRoll2);
    std::cout << "Game Status " << firstThrow(dieRoll1, dieRoll2) << std::endl;

    // Loop through point roll(s), print status
    if ((point != 2) && (point != 3) && (point != 7) && (point != 11) && (point != 12)) {
        int roll2sum;
        do {
            dieRoll1 = roll(6);
            dieRoll2 = roll(6);
            roll2sum = dieRoll1 + dieRoll2;
            printDiceRoll(dieRoll1, dieRoll2);
            std::cout << "Game Status " << pointThrow(point, dieRoll1, dieRoll2) << std::endl;
        } while ((roll2sum != 7) && (roll2sum != 11) && (roll2sum != point));
    }

    return 0;
}

// Function definitions
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
