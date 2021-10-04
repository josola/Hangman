#ifndef READ_FILE_H
#define READ_FILE_H

/*
 * Takes file input and reads contents to a container to be processed.
 * (c) 2020-2021 Jordan Sola. All rights reserved. (MIT License)
 * Written by Jordan Sola 2020-2021
 */

#include <vector>
#include <string>

std::vector<std::string> AcquireFileContents(const std::string input_file);

#endif // !READ_FILE_H