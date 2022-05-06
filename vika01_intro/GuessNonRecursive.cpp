#include <iostream>
#include <string>

// AC

using namespace std;

int main()
{
    int guess = 500;
    std::cout << guess << std::endl;
    std::cout.flush();
    int oldDiff, diff, oldGuess, top, bottom;
    top = 1000;
    bottom = 0;

    while (true)
    {
        string answer;
        std::cin >> answer;
        if (answer != "correct")
        {
            if (answer == "lower")
            {
                top = guess;
                diff = (guess - bottom) / 2;
                guess = bottom + diff;
            }
            else if (answer == "higher")
            {
                bottom = guess;
                diff = (top - guess) / 2;
                guess = top - diff;
            }
            std::cout << guess << std::endl;
            std::cout.flush();
        }
        else // don't know if I need this else statement
        {
            return 0;
        }
    }
    return 0;
}