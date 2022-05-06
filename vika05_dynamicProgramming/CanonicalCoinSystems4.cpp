#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 30)
#define MAXN 101
#define MAXM 2000001

// AC kattis time: 0.38 sec

int c[MAXN], optimal[MAXM], greedy[MAXM];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> c[i];

    int m = c[n - 2] + c[n - 1]; // counterexample will be at least smaller than this number

    for (int i = 1; i <= m; i++)
        optimal[i] = INF;
    optimal[0] = 0;
    
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= c[j])
            {
                optimal[i] = min(optimal[i], optimal[i - c[j]]+1);
                greedy[i] = greedy[i - c[j]] + 1;                   
            }
        }
        if (optimal[i] != greedy[i])
        {
            cout << "non-canonical" << endl;
            return 0;
        }
    }
    cout << "canonical" << endl;
    return 0;
}