#include <bits/stdc++.h>

// AC, Kattis time: 0.00 sec.

// PROBLEM DESCRIPTION
// Input
// The first and only input line consists of a single integer n, the number Neelix saw on his screen.

// Output
// Output the number x, where xx=n. Your answer must have an absolute or relative error of at most 10?6.

// Limits
// 1 ? n ? 10000000000

using namespace std;
typedef long double ld;

ld n, t, q;
ld error = 0.000001;

ld fun(ld a, ld b, ld m)
{
    t = pow(m, m);
    if (t <= n + error && t >= n - error)
    {
        return m;
    }
    if (t < n)
    {
        q = m + ((b - m) / 2.0);
        return fun(m, b, q);
    }
    if (t > n)
    {
        q = a + ((m - a) / 2.0);
        return fun(a, m, q);
    }
    return 0;
}

int main()
{
    ld res;
    cin >> n;
    ld sq = sqrtl(n) + error;

    ld bottom = 1 - error;
    ld m = (sq - bottom) / 2 + bottom;
    res = fun(bottom, sq, m);

    double a = res;
    printf("%.10g\n", a);

    return 0;
}