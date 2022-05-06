#include <bits/stdc++.h>

// AC Kattis time: 0.00 sec

// problem:
// Choose t ? 0 such that b^t + c/(t + 1) will be as small as possible for given b, c.

// solution:
// f(t) = b^t + c/(t+1)
// We use ternary search to find min of f

// Desmos graph of sample input 2
// https://www.desmos.com/calculator/s4nu5pss4c

using namespace std;
typedef long double ld;
#define INF (1 << 30)
#define EPS 0.000001

ld b1, c;

ld f(ld t)
{
    return pow(b1, t) + c / (t + 1);
}

int main()
{
    cin >> b1 >> c;

    // a starts as 0.0 because this problem specifies that Bergur can't train for negative minutes!
    ld a = 0.0, b = INF, m1, m2; 
    while (b - a > EPS)
    {
        m1 = (a + a + b) / 3.0;
        m2 = (a + b + b) / 3.0;
        if (f(m1) > f(m2))
            a = m1;
        else
            b = m2;
    }
    ld res = f(a);
    printf("%Lf\n", res);
}