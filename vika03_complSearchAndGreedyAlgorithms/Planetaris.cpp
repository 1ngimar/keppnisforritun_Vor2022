#include <iostream>
#include <set>

// AC, Kattis time: 0.04 sec

using namespace std;
typedef long long ll;

int main()
{
    int n, i; // min 1 and max 10^5 = 100.000
    ll a, t, result = 0;  // min 1 and max 10^9 = 1.000.000.000
    cin >> n >> a;
    multiset<ll> e;
    for (i = 0; i < n; i++)
    {
        cin >> t;
        e.insert(t);
    }
    for (ll item : e)
    {
        if (item < a)
        {
            result++;
            a -= item;  // send at least as many as Finnur
            a--;        // and send one more to win (this also covers if Finnur sends 0 ships)
        }
        else
        {
            break;
        }
    }
    cout << result << endl;
    return 0;
}