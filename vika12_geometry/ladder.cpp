#include <bits/stdc++.h>
using namespace std;

// AC, kattis time: 0.00 s

// 1 <= h <= 10,000
// 1 <= v <= 89

const double E = 1e-5;

int main()
{
    int h, v, res;
    const double PI = 3.141592653589793238463;
    cin >> h >> v;
    double radians = v * (PI / 180.0);
    double temp = sin(radians);
    res = ceil(h / temp);
    cout << res << endl;
    cout << E << endl;

}