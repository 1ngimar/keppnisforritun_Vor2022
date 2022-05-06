#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// AC, kattis runtime: 0.00 s

bool is_divisible_9_times(ll n, ll div)
{
    for (int i = 0; i < 9; i++)
    {
        if (n % div == 0)
            n /= div;
        else
            return false;
    }
    return true;
}

int biggest_meow_factor(ll n)
{
    ll top = sqrtl(n) + 1, temp, oldTop = top;
    while (true)
    {
        temp = powl(top, 9);
        if (temp > 0 && temp <= n)
            for (ll i = oldTop; i > 0; i--)
                if (is_divisible_9_times(n, i))
                    return i;
        else
        {
            oldTop = top;
            top /= 2;
        }
    }
}

int main()
{
    ll n;
    cin >> n;
    int res;
    res = biggest_meow_factor(n);
    cout << res << endl;
    return 0;
}