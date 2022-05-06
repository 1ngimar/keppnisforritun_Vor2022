#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;

// AC kattis runtime: 0.03 s

void finish(bool flag)
{
    if (flag)
    {
        cout << "Gengur!" << endl;
    }
    else
    {
        cout << "Vonlaust!" << endl;
    }
}

int main()
{
    ll n, a, b, h;
    cin >> n;
    ld nDouble, aDouble, hDouble, tempDouble, tempDouble2;
    ll aTemp, hTemp, temp, temp2;

    nDouble = (ld)n;
    h = floorl(sqrtl(n));
    hDouble = (ld)h;

    // if (h * h > n / 2)
    // {
    //     h = h - (h/3);
    // }
    // 1,000,000,000 ítranir í versta falli, very bad
    // while (h >= 2)
    // {
    //     temp = (n % (h * h));
    //     if (temp == 0)
    //     {
    //         finish(true);
    //         return 0;
    //     }
    //     h -= temp;
    // }

    for (h = floorl(cbrtl(n)); h >= 2; h--)
    {
        hDouble = (ld)h;
        tempDouble = nDouble / hDouble;
        temp = n / h;
        if (tempDouble != temp)
        {
            continue;
        }
        if (n % (h * h) == 0)
        {
            finish(true);
            return 0;
        }
        a = floorl(sqrtl(temp));
        aDouble = (ld)a;
        tempDouble2 = tempDouble / aDouble;
        temp2 = temp / a;
        if (tempDouble2 != temp2)
        {
            continue;
        }
        while (a >= 2)
        {
            if (n % (a * a) == 0)
            {
                finish(true);
                return 0;
            }
            a--;
        }
    }
    finish(false);
    return 0;
}