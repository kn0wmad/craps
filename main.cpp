//  Craps
// A game of chance based on dice rolls

#include <iostream>
#include <cstdlib>
#include <ostream>
#include "Craps.h"

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
