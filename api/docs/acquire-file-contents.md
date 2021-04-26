# [AcquireFileContents](https://github.com/josola/Hangman/blame/60038d7b368ae67a87aa9a3b370b988839be7d82/src/read_file.h#L14)

**Get contents of a text file**

Returns the contents of a locally placed file as a vector container of strings. Used to get the word list, that is used to set the winning word, from a local text file.

📐 **Parameters**

``input_file``<br>
Takes the location of a local file as string input. This file must contain plain text strings on individual line breaks.

↩️ **Return value**

The contents of the file path input as a vector container of separated strings.

🗺️ **Include file**

[src\read_file.h](src\read_file.h)

💡 **Example**

```c++
// Acquire file contents example.

#include <iostream>
#include <vector>
#include <string>

#include "read_file.h"

int main()
{
    // Get contents of text file.

    std::vector<std::string> file_contents = AcquireFileContents(src\words\eight_letter_words.txt);

    // Print contents of text file.

    for (const string : file_contents)
    {
        std::cout << word << std::endl;
    }

    return 0;
}
```

📺 **Output**

```
position
economic
ministry
cucumber
...
```