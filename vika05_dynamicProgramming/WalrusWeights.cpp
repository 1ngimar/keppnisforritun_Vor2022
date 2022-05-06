#include <bits/stdc++.h>
#define MAXN 1001
#define OBJ 1000
#define INF (1 << 30)

// AC kattis time 0.01

using namespace std;

int d[MAXN][MAXN], w[MAXN];

int dp_lookup1(int x, int y)
{
    if (y < 0)
        return -INF;
    if (x < 0)
        return 0;
    if (d[x][y] != -1)
        return d[x][y];
    return d[x][y] = max(dp_lookup1(x - 1, y), dp_lookup1(x - 1, y - w[x]) + w[x]);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> w[i];

    int r[MAXN], r2[MAXN];

    for (int i = 0; i < MAXN; i++)
    {
        r[i] = 0;
        r2[i] = 0;
        for (int j = 0; j < MAXN; j++)
            d[i][j] = -1;
    }

    int j = OBJ;
    for (int i = n - 1; i >= 0; i--)
        if (dp_lookup1(i - 1, j) < dp_lookup1(i - 1, j - w[i]) + w[i])
            j -= w[i], r[i] = 1;


    j += OBJ;
    for (int i = n - 1; i >= 0; i--)
        if (dp_lookup1(i - 1, j) < dp_lookup1(i - 1, j - w[i]) + w[i])
            j -= w[i], r2[i] = 1;

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (r[i])
            sum1 += w[i];
        if (r2[i])
            sum2 += w[i];
    }

    int result;
    result = max(sum1, sum2);
    cout << result << endl;
    return 0;
}
