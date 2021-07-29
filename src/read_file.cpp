/* src/read_file.cpp
 * Implimentation for AcquireFileContents().
 *
 * (c) 2021 Jordan Sola
 * Written by Jordan Sola
 */

#include "read_file.h"
#include <fstream>

std::vector<std::string> AcquireFileContents(const std::string input_file)
{
    std::fstream file;
    std::vector<std::string> output;

    file.open(input_file, std::fstream::in);
    if (file.is_open())
    {
        std::string input;
        while (getline(file, input))
        {
            output.push_back(input);
        }
        file.close();
    }
    return output;
}