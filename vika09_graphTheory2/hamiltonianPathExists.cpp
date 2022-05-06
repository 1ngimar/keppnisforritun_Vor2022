#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

int n;

bool hamiltonianPathExists(int start, int source, int sz, vb &visited, vi g[])
{
    if (sz == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < g[i].size(); j++)
            {
                int des = g[i][j];
                visited[i] = true;
                visited[des] = true;
                bool flag = hamiltonianPathExists(i, des, sz + 2, visited, g);
                if (flag)
                    return true;
                visited[i] = false;
                visited[des] = false;
            }
        }
    }
    else
    {
        if (sz == n)
            return true;
        else if (sz > n)
            return false;
        int ssz = g[source].size();
        for (int i = 0; i < ssz; i++)
        {
            int des = g[source][i];
            if (!visited[des])
            {
                visited[des] = true;
                bool flag = hamiltonianPathExists(start, des, sz + 1, visited, g);
                if (flag)
                    return true;
                visited[des] = false;
            }
        }
    }
    return false;
}

// main missing