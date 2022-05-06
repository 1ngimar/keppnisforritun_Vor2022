#include <bits/stdc++.h>

// AC kattis time = 1.09 sec

using namespace std;
#define MAXC 2001
#define MAXN 2001
#define MAXT 31
#define INF (1 << 30)
int myMax(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int v_all[MAXT][MAXN], w_all[MAXT][MAXN];
int d[MAXN][MAXC], v[MAXN], w[MAXN];
list<int> c_all, n_all;

int dp_lookup(int x, int y)
{
    if (y < 0)
        return -INF;
    if (x < 0)
        return 0;
    if (d[x][y] != -1)
        return d[x][y];
    return d[x][y] = myMax(dp_lookup(x - 1, y), dp_lookup(x - 1, y - w[x]) + v[x]);
}

void knapsack(int *v, int *w, int *r, int n, int c)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j <= c; j++)
            d[i][j] = -1;
    for (i = 0; i < n; i++)
        r[i] = 0;
    j = c;
    for (i = n - 1; i >= 0; i--)
        if (dp_lookup(i - 1, j) < dp_lookup(i - 1, j - w[i]) + v[i])
            j -= w[i], r[i] = 1;
}

int main()
{
    int c, n, r[MAXN], i = 0, k = 0, j = 0;
    while (cin >> c >> n)
    {
        c_all.push_front(c);
        n_all.push_front(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i] >> w[i];
            v_all[k][i] = v[i];
            w_all[k][i] = w[i];
        }
        k++;
    }

    i = 0;
    int countOfItems;
    while (!n_all.empty())
    {
        n = n_all.back();
        n_all.pop_back();

        c = c_all.back();
        c_all.pop_back();

        for (j = 0; j < n; j++)
        {
            v[j] = v_all[i][j];
            w[j] = w_all[i][j];
        }
        i++;

        knapsack(v, w, r, n, c);

        countOfItems = 0;
        for (k = 0; k < n; k++)
        {
            if (r[k])
            {
                countOfItems++;
            }
        }
        printf("%d\n", countOfItems);

        for (k = 0; k < n; k++)
        {
            if (r[k])
            {
                printf("%d ", k);
            }
        }
        printf("\n");
    }
    return 0;
}