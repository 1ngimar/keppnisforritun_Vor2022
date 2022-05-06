#include <bits/stdc++.h>

using namespace std;
#define INF (1 << 30)
#define MAXN 32
#define MAXB 16

int d[MAXN + 1][MAXB + 1], B[MAXN + 1][MAXB + 1], c[MAXN + 1], k[MAXN + 1], j2[MAXB + 1];
int A;

int dp_lookup(int x, int y)
{
    if (x == (1 << 0))
        return 0;
    if (y < 0)
        return INF;
    if (d[x][y] != -1)
        return d[x][y];
    return d[x][y] = min(dp_lookup(x, y - 1), dp_lookup(x ^ j2[y], y - 1) + c[y]);
}

int knapsack(int *w, int *r, int n, int b)
{
    int i, j;
    for (i = 0; i <= MAXN; i++)
        for (j = 0; j <= MAXB; j++)
            d[i][j] = -1;

    for (i = 0; i <= n; i++)
        r[i] = 0;
    for (i = n, j = b; i > 0; i--)
    {
        for (int ii = b; ii > 0; ii--)
        {
            j2[ii] = B[i][ii];
        }
        if (dp_lookup(A, i + 1) < dp_lookup(A ^ j2[j], i - 1) + c[i])
            j--, r[i] = 1;
    }
    // for (i = n; i > 1; i--)
    // {
    //     for (int e = b; e >= 1; e++)
    //     {
    //         dp_lookup(A ^ B[i][e], i - 1, e - 1);
    //     }
    // }
    // return dp_lookup((1 << b) - 1, n - 1, b);
    return 0;
}

void init(int n, int b)
{
    for (int i = 0; i <= n; i++)
    {
        c[i] = 0;
        k[i] = 0;
        for (int j = 0; j < b; j++)
        {
            B[i][j] = 0;
        }
    }
}

int main()
{
    int n, b, r[MAXN + 1];
    cin >> n >> b;

    init(n, b);

    A = (1 << b) - 1;
    int ci, ki, bIndex;
    for (int i = 1; i <= n; i++)
    {
        cin >> ci >> ki;
        c[i] = ci;
        k[i] = ki;
        for (int j = 1; j <= ki; j++)
        {
            cin >> bIndex;
            B[i][j] = (1 << bIndex) - 1;
        }
    }

    knapsack(c, r, n, b);

    int res = 0;
    cout << "r array" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << r[i] << " ";
        if (r[i] == 1)
        {
            res += c[i];
        }
    }
    cout << endl;

    cout << res << endl;

    return 0;
}