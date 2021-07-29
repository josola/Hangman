# [CheckWordLengthInput](https://github.com/josola/Hangman/blame/60038d7b368ae67a87aa9a3b370b988839be7d82/src/check_utility.h#L9)

**Checks that input falls within an acceptable range.**

Takes an unsigned integer literal as input and checks whether the input is within a set minimum value and maximum value. For this program, the minimum value is 2 and the maximum value is 14. These are the supported word lengths to use during gameplay.

📐 **Parameters**

``input``<br>
Const unsigned integer.

↩️ **Return value**

Returns a boolean value: 0/1, TRUE/FALSE.

🗺️ **Include file**

[src\check_utility.h](https://github.com/josola/Hangman/blob/e86b39f3e066a785dbd41c5ceeda6aef2b0ea91c/src/check_utility.h)

💡 **Example**

```c++
// Word length check example.

#include <iostream>

int main()
{
    int word_length = 0;

    bool good_input = false;
    while (!good_input)
    {
        cin >> word_length;
        if (!CheckWordLength(word_length))
        {
            cout << "Input does not fall within range." << endl;
        }
        else
        {
            good_input = true;
        }
    }

    cout << word_length << ' ' << good_input << endl;

    return 0;
}
```

📺 **Output**

```
12
12 TRUE

32
Input does not fall within range.
4
4 TRUE
```