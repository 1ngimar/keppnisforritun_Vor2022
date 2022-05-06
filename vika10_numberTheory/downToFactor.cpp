#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

// AC, kattis runtime: 0.07 s

// The gist: We check if the phone number is a prime squared
//          by taking the square root of the number and checking
//          if the result is a prime, if it is, then it has 6 divisors
//          (the positive and negative divisors)

// example:
// 169 has 6 divisors: -169, -13, -1, 1, 13, 169

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

string create_phone_number(ll n)
{
    string input_str = to_string(n);
    string result = "";
    for (int i = 0; i < 18 - input_str.length(); i++)
    {
        result += "0";
    }
    result += input_str;
    return result;
}

int main()
{
    vector<ll> res_ll;
    int n;
    ld square_root;
    ll phone_number;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> phone_number;
        square_root = sqrtl(phone_number);
        if (square_root == floorl(square_root))
        {
            if (is_prime(square_root))
            {
                res_ll.push_back(phone_number);
            }
        }
    }

    string res_string;
    for (ll item : res_ll)
    {
        res_string = create_phone_number(item);
        cout << res_string << endl;
    }

    return 0;
}