#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

const double ESP = 1e-6;

// Sk�lager�
// AC, kattis time: 0.00 s
int main()
{
    ld r;
    cin >> r;
    // p��ag�ras me� helmingunarleit fyrir kva�ratr�t
    ld c = powl(r, 2) * 2; // �etta er a^2 + b^2 parturinn
    ld res = sqrtl(c);
    // vi� vitum a� a^2 + b^2 = c^2
    // ld begin = c, end = 0, middle, res, check;
    // while (begin >= end) // helmingunarleit fyrir kva�ratr�t af c
    // {
    //     middle = (begin + end) / 2;
    //     check = middle * middle;
    //     if (check == c)
    //     {
    //         res = middle;
    //         break;
    //     }
    //     if (check < c)
    //         end = middle + 1, res = middle;
    //     else
    //         begin = middle - 1;
    // }
    // ld extraPrecision = 0.1;
    // for (int i = 0; i < 6; i++)
    // {
    //     while (c >= powl(res, 2))
    //     {
    //         res += extraPrecision;
    //     }
    //     res -= extraPrecision;
    //     extraPrecision /= 10;
    // }
    // printf("%.6Lf\n", res);
    cout << res << endl;
    cout << setprecision(6) << res << endl;
    // cout << fixed << setprecision(6) << res;
    return 0;
}