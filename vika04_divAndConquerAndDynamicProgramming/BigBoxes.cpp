#include <bits/stdc++.h>

// WA

using namespace std;
typedef long long ll;

ll forward(vector<ll> w, int n, int k)
{
    vector<ll> wOfEachBoxForward(k);
    int i, j, p, counter = 1;
    ll temp;
    for (i = 0; i < k - 1; i++) // partition first one item in each k - 1 boxes
    {
        wOfEachBoxForward[i] = w[i];
    }
    for (j = i; i < n; i++) // put rest of the items in the last box
    {
        if (j == 1)
        {
            counter++;
        }
        wOfEachBoxForward[j] += w[i];
    }

    i = j - 1;
    p = j;

    while (j != 0 && p < n && i >= 0)
    {      
        temp = w[p++];
        wOfEachBoxForward[j] -= temp;
        wOfEachBoxForward[i] += temp;
        if (wOfEachBoxForward[j] < wOfEachBoxForward[i])
        {
            j--;
            p = j;
            i--;
        }
        else if (i == 0 && counter == 1)
        {
            break;
        }
    }
    return *max_element(wOfEachBoxForward.begin(), wOfEachBoxForward.end());
}

ll backwards(vector<ll> w, int n, int k)
{
    vector<ll> wOfEachBoxBack(k);
    int i = k - 1, j = k - 1, p = n - 1;
    ll temp;
    while (i > 0)
        wOfEachBoxBack[i--] = w[p--];
    while (p >= 0)
        wOfEachBoxBack[i] += w[p--];

    p = n - j - 1; // gæti verið vitlaust, ath með fleiri test case!!!!!!!!!!!!!!!!!!!!!!!!!!
    while (p > 0 && i >= 0)
    {
        temp = w[p--];
        wOfEachBoxBack[i] -= temp;
        wOfEachBoxBack[j] += temp;
        if (wOfEachBoxBack[j] > wOfEachBoxBack[i])
        {
            j--;
            p = j;
            i--;
        }
        else if (i == 0 && p + 1 >= n)
        {
            break;
        }
    }
    return *max_element(wOfEachBoxBack.begin(), wOfEachBoxBack.end());
}

int main()
{
    int n, k, i, j, p;
    cin >> n >> k;

    vector<ll> w, wOfEachBox(k);
    ll wi, temp;
    for (int i = 0; i < n; i++)
    {
        cin >> wi;
        w.push_back(wi);
    }

    ll resF = forward(w, n, k);
    ll resB = backwards(w, n, k);

    ll finalRes = min(resF, resB);

    // res = *max_element(wOfEachBox.begin(), wOfEachBox.end());
    cout << finalRes << endl;

    return 0;
}