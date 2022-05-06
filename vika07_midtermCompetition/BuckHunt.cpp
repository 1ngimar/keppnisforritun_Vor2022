#include<bits/stdc++.h>

// AC, kattis time = 0.00 sec

using namespace std;

int main()
{
    int x1, x2, y1, y2, n;

    cin >> x1 >> x2 >> y1 >> y2;
    cin >> n;
    int x, y, count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}