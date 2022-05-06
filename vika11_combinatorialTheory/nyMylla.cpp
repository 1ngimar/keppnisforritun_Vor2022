#include <bits/stdc++.h>
using namespace std;

// WA, This solution is wrong!
// I read the description wrong, such that I assumed that a player can
// fill out all on the x-axis and y-axis until they have reached the end of the grid...

void fyrri()
{
    cout << "Fyrri!" << endl;
}

void seinni()
{
    cout << "Seinni!" << endl;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    bool a_turn = true, b_turn = false;
    while (true)
    {
        if (a_turn)
        {
            if (n <= 0 || m <= 0)
            {
                seinni();
                break;
            }
            if (n + m - 1 >= k)
            {
                n--;
                m--;
            }
            else
            {
                seinni();
                break;
            }
            a_turn = false;
            b_turn = true;
        }
        else if (b_turn)
        {
            if (n <= 0 || m <= 0)
            {
                fyrri();
                break;
            }
            if (n + m - 1 >= k)
            {
                n--;
                m--;
            }
            else
            {
                fyrri();
                break;
            }
            a_turn = true;
            b_turn = false;
        }
    }
    return 0;
}