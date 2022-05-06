#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;

// AC, kattis time: 0.01 s

int main()
{
    int n, p, d;
    string str;
    cin >> n >> p >> d >> str;

    char c;
    vb a1;
    int t = n + 1 - p;
    while (t < n)
    {
        c = str[t];
        if (c == 'W')
        {
            a1.push_back(false);
        }
        else
        {
            a1.push_back(true);
        }
        t++;
    }
    t = 0;
    while (t < n)
    {
        c = str[t];
        if (c == 'Z')
        {
            a1.push_back(true);
        }
        else
        {
            a1.push_back(false);
        }
        t++;
    }

    int countTired = 0;
    int countSleep = 0;
    int i = p - 1, j = p - 1;
    for (int k = 0; k < p; k++)
    {
        if (a1[k])
        {
            countSleep++;
        }
    }

    i = p;
    while (i < a1.size())
    {
        if (countSleep < d)
        {
            countTired++;
        }
        if (a1[i])
        {
            countSleep++;
        }
        if (a1[i - p])
        {
            countSleep--;
        }
        i++;
    }
    if (countSleep < d)
    {
        countTired++;
    }
    cout << countTired << endl;
    return 0;
}