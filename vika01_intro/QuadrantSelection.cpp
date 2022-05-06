#include <iostream>

// AC

using namespace std;

int main() 
{
    int x, y;
    std::cin >> x;
    std::cin >> y;
    if (x < 0)
    {
        if (y < 0)
        {
            std::cout << 3 << endl;
        }
        else
        {
            std::cout << 2 << endl;
        }
    }
    else
    {
        if (y < 0)
        {
            std::cout << 4 << endl;
        }
        else
        {
            std::cout << 1 << endl;
        }
    }
    return 0;
}