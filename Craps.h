// Function prototypes

#include <string>

#ifndef CRAPSFNCS_H
#define CRAPSFNCS_H
int roll(int numSides); // Die toss, based on number of sides given

void printDiceRoll(int die1, int die2); // Output results of a roll

std::string firstThrow(int die1, int die2); // Output game status after first roll

std::string pointThrow(int firstPoint, int die1, int die2); // Output game status after second roll

#endif
