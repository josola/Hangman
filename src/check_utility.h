#ifndef CHECK_UTILITY_H
#define CHECK_UTILITY_H

/* src/check_utility.h
 * Checks whatever needs checking.
 * (c) 2020-2021 Jordan Sola
 * Written by Jordan Sola */

#include <string>

bool CheckAttemptInput(const unsigned int input);
bool CheckWordLengthInput(const unsigned int input);
bool CheckGuessInput(const std::string input);

#endif // !CHECK_UTILITY_H