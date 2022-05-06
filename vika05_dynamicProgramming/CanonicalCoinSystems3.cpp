#include <bits/stdc++.h>
#define MAXN 101
#define INF (1 << 30)

using namespace std;

int main()
{
    int n, c[MAXN];
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    int m = c[n - 2] + c[n - 1]; // biggest test case to guarantee a counterexample

    // Optimal algorithm
    int d[m + 1];
    int d_greedy[m+1];
    for (int i = 0; i <= m; i++)
    {
        d[i] = INF;
        d_greedy[i] = 0;
    }
    d[0] = 0;
    // d_greedy[m] = 0;

    vector<int> tempVector;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m + 1 - c[i]; j++)
        {
            if (d[j] < INF && d[j + c[i]] > d[j] + 1)
            {
                d[j + c[i]] = d[j] + 1;
            }
        }
    }

    // cout << "Optimal solution array below\n";
    // for (int i = 1; i <= m; i++)
    // {
    //     cout << d[i] << " ";
    // }
    // cout << endl;

    // int d_gr[m + 1][n+1] = {0};
    int R[m][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            R[i][j] = 0;
        }
    }

    sort(c, c + n, greater<int>());

    int d_g[n];
    for (int i = 0; i < n; i++)
    {
        d_g[i] = 0;
    }

    int k, a, t = m, j = 0, countOfCoins, temp;
    // int t = 7;

//     from itertools import*
// g=lambda x,c,n=0:x and g(x-[v for v in c if v<=x][0],c,n+1)or n
// lambda c:len(c)<3or 1-any(any(any(x==sum(p)for p in combinations(c*i,i))for i in range(g(x,c)))for x in range(c[0]*2))

    

    // while (j < m)
    // {
    //     k = 0;
    //     a = 0;
    //     countOfCoins = 0;
    //     temp = 0;
    //     while (a < t)
    //     {
    //         if (c[k] == t)
    //         {
    //             countOfCoins = 1;
    //             R[a][k] = 1;
    //         }
    //         else if (c[k] > t)
    //         {
    //             R[a][k] = R[a][k-1];
    //         }
            
            
    //         temp = floor((t - a) / c[k]);
    //         R[j][k] = temp;
    //         a = a + temp * c[k];
    //         countOfCoins += temp;
    //         k++;
    //     }
    //     d_greedy[m - j] = countOfCoins;
    //     t--;
    //     j++;
    // }

    // for (i = 0; i < m; i++)
    //     cout << d_greedy[i] << " ";
    // cout << "\nGreedy solution array above" << endl;

    for (int i = m; i > 0; i--)
    {
        if (d[i] != d_greedy[i])
        {
            cout << "non-canonical" << endl;
            return 0;
        }
    }
    cout << "canonical" << endl;
    return 0;
}