#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

// UNFINISHED

const ll maxn = 1000000;
const ll mod = 1e9 + 7;
ll fact[maxn + 1];

void calcfact() // Stolið frá Atla FF
{
    fact[0] = 1;
    for (int i = 1; i <= maxn; ++i)
        fact[i] = (fact[i - 1] * i) % mod;
}

ll egcd(ll a, ll b, ll &x, ll &y) // Stolið frá Atla FF
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = egcd(b, a % b, x, y);
    x -= a / b * y;
    swap(x, y);
    return d;
}

ll mod_inv(ll a, ll m) // stolið frá Atla FF
{
    ll x, y;
    ll d = egcd(a, m, x, y);
    // Hér mætti tékka hvort d = 1 því ef svo
    // er ekki er x ekki rétt andhverfa
    return (x % m + m) % m;
}

ll nck(ll n, ll k) // stolið frá Atla FF
{
    ll res = fact[n];
    res *= mod_inv(fact[k], mod);
    res %= mod;
    res *= mod_inv(fact[n - k], mod);
    res %= mod;
    return res;
}

int main()
{
    int n;
    vi ones, twos, threes;
    int song;
    ll numOnes = 0, numTwos = 0, numThrees = 0;
    cin >> n;
    calcfact();
    for (int i = 0; i < n; i++)
    {
        cin >> song;
        if (song == 1)
        {
            ones.push_back(1);
            numOnes++;
        }
        else if (song == 2)
        {
            twos.push_back(2);
            numTwos++;
        }
        else if (song == 3)
        {
            threes.push_back(3);
            numThrees++;
        }
    }
    ll res = 0;
    // fyrir hvern s
}
