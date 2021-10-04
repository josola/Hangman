/*
 * Implimentation for AcquireFileContents().
 * (c) 2020-2021 Jordan Sola. All rights reserved. (MIT License)
 * Written by Jordan Sola 2020-2021
 */

#include <fstream>

#include "read_file.h"

std::vector<std::string> AcquireFileContents(const std::string input_file) {

	std::fstream file;
	std::vector<std::string> output;

	file.open(input_file, std::fstream::in);
	if (file.is_open()) {

		std::string input;

		while (getline(file, input))
			output.push_back(input);

		file.close();
		
	}

	return output;
}