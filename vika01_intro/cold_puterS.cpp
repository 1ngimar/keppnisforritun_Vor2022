#include <iostream>

// AC

using namespace std;

int main()
{
    int n, count, t;
    count = 0;
    std::cin >> n;
    while(n != 0)
    {
        std::cin >> t;
        if (t < 0)
        {
            count++;
        }
        n--;
    }
    std::cout << count << endl;
}