/*
 * Implimentation for checking utilities.
 * (c) 2020-2021 Jordan Sola. All rights reserved. (MIT License)
 * Written by Jordan Sola 2020-2021
 */

#include <iostream>
#include <vector>

#include "check_utility.h"

bool CheckAttemptInput(const unsigned int input) {
	
	int min = 1;
	int max = 25;

	if (input < min || input > max)
		return false;
	else
		return true;

}

bool CheckWordLengthInput(const unsigned int input) {
	
	int min = 2;
	int max = 14;

	if (input < min || input > max)
		return false;
	else
		return true;

}

bool CheckGuessInput(const std::string input) {
	
	std::vector<std::string> bad_guesses = { "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+", "-", "=",
											 ",", ".", "/", "<", ">", "?", ";", ":", "[", "]",
											 "{", "}", "|", "`", "~", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

	bool output = false;
	if (input.size() > 1)
		return output;
	else {

		for (size_t i = 0; i < bad_guesses.size(); i++) {

			if (input == bad_guesses[i])
				return false;
			else
				output = true;
				
		}

	}

	return output;
}