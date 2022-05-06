#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// idea:
// n choose k for k = 2, 3, 4, ... n

// AC, kattis runtime: 0.00 s

const ll maxn = 30;
const ll mod = 1e9 + 7;
ll fact[maxn + 1];

void calcfact() // Stoli� fr� Atla FF
{
    fact[0] = 1;
    for (int i = 1; i <= maxn; ++i)
        fact[i] = (fact[i - 1] * i) % mod;
}

ll egcd(ll a, ll b, ll &x, ll &y) // Stoli� fr� Atla FF
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

ll mod_inv(ll a, ll m) // stoli� fr� Atla FF
{
    ll x, y;
    ll d = egcd(a, m, x, y);
    // H�r m�tti t�kka hvort d = 1 �v� ef svo
    // er ekki er x ekki r�tt andhverfa
    return (x % m + m) % m;
}

ll nck(ll n, ll k) // stoli� fr� Atla FF
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
    ll n;
    cin >> n;
    ll res = 0;
    calcfact();
    for (ll k = 2; k <= n; k++)
    {
        res += nck(n, k);
    }
    cout << res << endl;
    return 0;
}