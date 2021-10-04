#ifndef CHECK_UTILITY_HPP
#define CHECK_UTILITY_HPP

/*
 * Checks whatever needs checking.
 * (c) 2020-2021 Jordan Sola. All rights reserved. (MIT License)
 * Written by Jordan Sola 2020-2021
 */

#include <string>

bool CheckAttemptInput(const unsigned int input);
bool CheckWordLengthInput(const unsigned int input);
bool CheckGuessInput(const std::string input);

#endif // !CHECK_UTILITY_HPP