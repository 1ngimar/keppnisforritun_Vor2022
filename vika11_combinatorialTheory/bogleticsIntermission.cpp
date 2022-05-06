#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

// AC, kattis time: 0.02 s

int main()
{
    int n, k;
    cin >> n;
    vi v;
    v.push_back(0);
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        v.push_back(k);
    }

    int temp, temp2, count;
    int i = 1;
    int sumCount = 0;

    while (true)
    {
        if (i > n)
        {
            break;
        }
        if (v[i] == -1 || v[i] == i)
        {
            i++;
            continue;
        }
        temp = v[i];
        v[i] = -1;
        count = 2;
        while (true)
        {
            count++;
            if (i == v[temp])
            {
                v[temp] = -1;
                sumCount += count;
                break;
            }   
            temp2 = v[temp];
            v[temp] = -1;
            temp = temp2;
        }
        i++;
    }
    cout << sumCount << endl;
    return 0;
}