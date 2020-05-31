#include <fstream>
#include <vector>
#include <string>

using std::fstream;
using std::string;
using std::vector;

vector<string> AcquireFileContents(const string input_file)
{
    fstream file;
    vector<string> output;

    file.open(input_file, fstream::in);
    if (file.is_open())
    {
        string input;
        while (getline(file, input))
        {
            output.push_back(input);
        }
        file.close();
    }
    return output;
}