#include <bits/stdc++.h>
#define MAXN 501
#define MAXT 5001
#define INF (1 << 30)
using namespace std;

double d[MAXN][MAXT];
int w[MAXN], t, n;

int max(int x, int y)
{
    if (x < y)
        return x;
    return y;
}

int min(int x, int y)
{
    if (x < y)
        return y;
    return x;
}

int dp_lookup(int x, int y)
{
    if (y < 0)
        return INF;
    if (x < 0)
        return 0;
    if (d[x][y] != -1)
        return d[x][y];
    return d[x][y] = min(dp_lookup(x - 1, y), dp_lookup(x - 1, y - w[x]) + 0.5);
}

int main()
{
    cin >> t >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    int i, j, rod1[t], rod2[t];
    for (i = 0; i < n; i++)
    {
        rod1[i] = -1;
        rod2[i] = -1;
        for (j = 0; j < t; j++)
        {
            d[i][j] = -1;
        }
    }

    j = t;
    for (i = n - 1; i >= 0; i--)
        if (dp_lookup(i - 1, j) < dp_lookup(i - 1, j - w[i]) + 0.5)
            j -= w[i], rod1[i] = w[i] - j;

    

    // prenta útkomu
    return 0;
}

// [1][1][1][1][][][][]
// [][][][][][][][]

// [][1][1][1][1][][][]
// [][][][][][][][]

// [][][1][1][1][1][][]
// [][][][][][][][]

// [][][][1][1][1][1][]
// [][][][][][][][]

// [][][][][1][1][1][1]
// [][][][][][][][]