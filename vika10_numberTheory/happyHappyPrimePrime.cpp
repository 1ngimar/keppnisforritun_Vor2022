#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// AC, kattis runtime: 0.02 s

bool is_prime(ll n)
{
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0)
            return false;
        if (n % (i + 2) == 0)
            return false;
    }
    return true;
}

bool is_happy(ll x)
{
    ll sum = 0, e;
    while (x > 0)
    {
        e = x % 10;
        x = floorl(x / 10);
        sum += e * e;
    }
    if (sum == 1)
    {
        return true;
    }
    else if (sum > 1 && sum <= 4)
    {
        return false;
    }
    return is_happy(sum);
}

int main()
{
    int K, m, t;
    cin >> K;
    list<pair<int, pair<int, string>>> output;
    bool flag;
    for (int i = 1; i < K + 1; i++)
    {
        flag = false;
        cin >> t >> m;

        if (is_prime(m))
        {
            if (is_happy(m))
            {
                flag = true;
            }
            else
                flag = false;
        }
        else
            flag = false;
        
        if (flag)
            output.push_back(make_pair(i, make_pair(m, "YES")));
        else
            output.push_back(make_pair(i, make_pair(m, "NO")));
    }

    for (auto item : output)
    {
        cout << item.first << " " << item.second.first << " " << item.second.second << endl;
    }
    
    return 0;
}