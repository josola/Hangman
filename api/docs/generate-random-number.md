# [GenerateRandomNumber](https://github.com/josola/Hangman/blame/60038d7b368ae67a87aa9a3b370b988839be7d82/src/number_generator.h#L8)

**Returns a random number within a range**

Returns an integer literal that falls within a random position between a minimum value and maximum value.

📐 **Parameters**

``range``<br>
Unsigned integer that is the highest number that can be returned.

↩️ **Return value**

An integer literal.

🗺️ **Include file**

[src\number_generator.h](src\number_generator.h)

💡 **Example**

```c++
// Random number generator example.

#include <iostream>

int main()
{
    int range_limit = 32;
    int random_number = GenerateRandomNumber(range_limit);

    std::cout << random_number << std::endl;

    return 0;
}
```

📺 **Output**

```
12
```