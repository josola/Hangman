# [CheckAttemptInput](https://github.com/josola/Hangman/blame/60038d7b368ae67a87aa9a3b370b988839be7d82/src/check_utility.h#L8)

**Checks whether input for number of attempts falls within an acceptable range.**

Takes a const unsigned integer as input, then checks it against a preset range for number of failed attempts a player gets before the game ends. For this game the range is 1 to 25.

📐 **Parameters**

``input``<br>
Const unsigned integer.

↩️ **Return value**

Returns a ``bool``.

🗺️ **Include file**

[api\docs\check-attempt-input.md](https://github.com/josola/Hangman/blob/e86b39f3e066a785dbd41c5ceeda6aef2b0ea91c/src/check_utility.h)

💡 **Example**

```c++
// Check attempt count example.

#include <iostream>

int main()
{
    int num_of_attempts = 0;

    bool acceptable_attempt_count = false;
    while (!acceptable_attempt_count)
    {
        cin >> num_of_attempts;

        if (!CheckAttemptInput())
        {
            std::cout << "Invalid number of attempts." << endl;
        }
        else
        {
            acceptable_attempt_count = true;
        }
    }

    std::cout << num_of_attempts << acceptable_attempt_count << std::endl;

    return 0;
}
```

📺 **Output**

```
364
Invalid number of attempts.
12
12 TRUE
```