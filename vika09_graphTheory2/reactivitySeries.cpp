#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

// WA

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

// amb er hvort það sé ótvíræð röð
// skilar lengd minna en g.size() ef ekki dag
vi topsort(vvi &g, bool &amb) // Stolið frá Atla Fannar Franklín
{
    vi deg(g.size()), res;
    for (vi v : g)
        for (int x : v)
            deg[x]++;
    queue<int> q;
    for (int i = 0; i < g.size(); ++i)
        if (deg[i] == 0)
            q.push(i);
    amb = false;
    while (q.size() > 0)
    {
        if (q.size() > 1)
            amb = true;
        int cur = q.front();
        q.pop();
        res.push_back(cur);
        for (int x : g[cur])
            if (--deg[x] == 0)
                q.push(x);
    }
    return res;
}

int main()
{
    int m, a, b;
    cin >> n >> m;
    vi g[n], res;
    vvi g1(n, vi()); // for the topological sort

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g1[a].push_back(b);
    }

    vi temp;
    vb visited(n, false);
    bool flag = hamiltonianPathExists(-1, -1, 0, visited, g);

    if (flag)
    {
        bool amb = false;
        res = topsort(g1, amb);
        for (auto item : res)
            cout << item << " ";
        cout << endl;
    }
    else
        cout << "back to the lab" << endl;
    return 0;
}