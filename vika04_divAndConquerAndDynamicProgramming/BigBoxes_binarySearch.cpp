#include <bits\stdc++.h>

using namespace std;
typedef long long ll;

// unfinished, aka. this solution is wrong

// ll mx;
vector<ll> wOfEachBox;

int gr_check(vector<ll> w, int n, int k, ll m)
{
    wOfEachBox.clear();
    int i = 0, j = 0;
    ll r = 0;
    while (i < n)
    {
        if (r + w[i] <= m)
        {
            r += w[i];
            i++;
        }
        else
        {
            wOfEachBox.push_back(r);
            j++;
            r = 0;
            // r = w[i];
        }
    }
    // j++;
    wOfEachBox.push_back(r);
    return j >= k;
}

int main()
{
    int n, k;
    vector<ll> w;

    cin >> n >> k;

    ll w_item, s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w_item;
        w.push_back(w_item);
        s += w_item;
    }

    ll r = 0;
    // ll s = 10000000000;
    // ll mx = *max_element(w.begin(), w.end());
    int countOfBoxes = 0, i = 0;
    s *= k * k;
    while (r < s)
    {
        ll m = (r + s) / 2;
        if (gr_check(w, n, k, m))
        {
            r = m + 1;
        }
        else
        {
            s = m;
        }
    }

    // mx = *max_element(wOfEachBox.begin(), wOfEachBox.end());
    cout << r << endl;
    return 0;
}