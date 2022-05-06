#include <iostream>

// AC

using namespace std;

int main()
{
    int a, b;
    std::cin >> a >> b;
    if (a < b)
    {
        std::cout << a;
        std::cout << " ";
        std::cout << b << std::endl;
    }
    else
    {
        std::cout << b;
        std::cout << " ";
        std::cout << a << std::endl;
    }
    return 0;
}