/* src/read_file.h
 * Takes file input and reads contents to a container to be processed.
 *
 * (c) 2021 Jordan Sola
 * Written by Jordan Sola
 */

#ifndef READ_FILE_H
#define READ_FILE_H

#include <vector>
#include <string>

std::vector<std::string> AcquireFileContents(const std::string input_file);

#endif // RED_FILE_H