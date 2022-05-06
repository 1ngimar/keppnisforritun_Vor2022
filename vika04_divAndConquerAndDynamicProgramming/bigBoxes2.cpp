#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
vector<ll> w, wOfEachBox(k);
vector<int> split_indices;

ll fun(ll t)
{
    for (auto item : split_indices)
    {
        
    }
}

int main()
{
    cin >> n >> k;

    ll item;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        w.push_back(item);
    }

    double index = 0.0, temp = 0.0;

    for (int i = 0; i < k - 1; i++)
    {
        temp += (n - index) / (k - i);
        index = round(temp);
        split_indices.push_back((int)index);
    }

    for (auto item : split_indices)
    {
        // upphafsstilla stærðir allra kassa núna síðan kalla á endurkvæma fallið
    }

    ll res = fun(0);

    return 0;
}