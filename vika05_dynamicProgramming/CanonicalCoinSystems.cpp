#include <bits/stdc++.h>
#define MAXN 101
#define INF (1 << 30)

using namespace std;
// typedef long long ll;

int gr(int i, int j, int m, int *c, vector<int> tempV)
{
    int m_decreasing = m - j + 1, countOfCoins = 0;
    while (j >= i)
    {
        if (m_decreasing - c[i] >= 0)
        {
            countOfCoins++;
            m_decreasing -= c[i];
            if (m_decreasing == 0)
            {
                d_greedy[m - j] = countOfCoins;
                countOfCoins = 0;
                return 0;
            }
        }
    }
    return 1;
}

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
    int d_greedy[m + 1];
    for (int i = 0; i <= m; i++)
    {
        d[i] = INF;
        d_greedy[i] = INF;
    }
    d[0] = 0;
    d_greedy[m] = 0;

    vector<int> tempVector;
    for (int i = 0; i < n; i++)
    {
        if (i > 1)
        {
            for (int l = i; l < i+1; l++)
            {
                tempVector.push_back(d[i]);
            }
            int blabla = gr(i, 0, i+1)
        }
        
        for (int j = 0; j < m + 1 - c[i]; j++)
        {
            if (d[j] < INF && d[j + c[i]] > d[j] + 1)
            {
                d[j + c[i]] = d[j] + 1;
            }
        }
    }

    cout << "Optimal solution array below\n";
    for (int i = 1; i <= m; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    // ll d_greedy[m+1];
    // for (int i = 1; i <= m; i++)
    //     d[i] = INF;
    // d[0] = 0;

    // for (int i = n-1; i >= 0; i--)
    // {
    //     for (int j = 0; j < m + 1 - c[i]; j++)
    //     {
    //         if (d_greedy[j] < INF && d_greedy[j + c[i]] > d_greedy[j] + 1)
    //         {
    //             d_greedy[j + c[i]] = d_greedy[j] + 1;
    //         }
    //     }
    // }

    // int k = 0, i = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m + 1 - c[i]; j++)
    //     {
    //         if (d_greedy[j] < INF)
    //         {
    //             d_greedy[j + c[i]] = min(d_greedy[j + c[i]], d_greedy[j] + 1);
    //         }
    //     }
    // }

    // for (int i = 1; i <= m; i++)
    // {
    //     cout << d_greedy[i] << " ";
    // }
    // cout << "\nGreedy solution array above" << endl;

    // Greedy algorithm
    // int m_decreasing = m, i, j = 1, k = 0, q = 1;

    // while (k < m)
    // {
    //     i = n - 1;
    //     m_decreasing = m - j + 1;
    //     countOfCoins = 0;
    //     if (d_greedy[m - j] != INF)
    //     {

    //     }

    //     while (i >= 0)
    //     {
    //         if (m_decreasing - c[i] >= 0)
    //         {
    //             countOfCoins++;
    //             m_decreasing -= c[i];
    //             if (m_decreasing == 0)
    //             {
    //                 d_greedy[m - j] = countOfCoins;
    //                 k++;
    //                 countOfCoins = 0;
    //                 break;
    //             }
    //         }
    //         else
    //         {
    //             i--;
    //         }
    //     }
    //     j++;
    // }

    // for (i = 0; i < m; i++)
    //     cout << d_greedy[i] << " ";
    // cout << "\nGreedy solution array above" << endl;

    for (int i = 1; i <= m; i++)
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