/*
   Craps

   A game of chance based on dice rolls
*/

#include <iostream>
#include <cstdlib>
#include <ostream>
#include <string>

// Define functions
int roll(int numSides); // Die toss, based on number of sides given

void printDiceRoll(int die1, int die2); // Output results of a roll

std::string firstRoll(int die1, int die2); // Output game status after first roll

std::string pointRoll(int firstPoint, int die1, int die2); // Output game status after second roll

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
    int rollTotal = dieRoll1 + dieRoll2;

    // First roll, print roll, print status
    std::cout << "Craps First Throw\n\n";
    printDiceRoll(dieRoll1, dieRoll2);
    std::cout << "Game Status " << firstRoll(dieRoll1, dieRoll2) << std::endl;

    // Loop through point roll(s), print status
    while ((rollTotal != 2) && (rollTotal != 3) && (rollTotal != 7) && (rollTotal != 11) && (rollTotal != 12)) {
        std::cout << "Game Status " << pointRoll(rollTotal, dieRoll1, dieRoll2) << std::endl;
        dieRoll1 = roll(6);
        dieRoll2 = roll(6);
        rollTotal = dieRoll1 + dieRoll2;
        printDiceRoll(dieRoll1, dieRoll2);
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

std::string firstRoll(int die3, int die4) {
    int sum = die3 + die4;
    if ((sum == 7) || (sum == 11)) {
        return "WIN\n";
    } else if ((sum == 2) || (sum == 3) || (sum == 12)) {
        return "LOSE\n";
    } else {
        return "Roll for Point: " + std::to_string(sum) + "\n";
    }
}

std::string pointRoll(int firstPoint, int die1, int die2) {
    int sum2 = die1 + die2;
    if (sum2 == firstPoint) {
        return "WIN\n";
    } else if (sum2 == 7) {
        return "LOSE\n";
    } else {
        return "KEEP rolling for point: " + std::to_string(sum2) + "\n";
    }
}
