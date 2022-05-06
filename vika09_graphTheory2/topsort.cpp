#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

// amb er hvort það sé ótvíræð röð
// skilar lengd minna en g.size() ef ekki dag
vi topsort(vvi &g, bool &amb)
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
    int n, m, a, b;
    cin >> n >> m;
    vvi g(n, vi());

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
    }

    bool amb = false;
    vi result = topsort(g, amb);
    for (auto item : result)
        cout << item << endl;

    return 0;
}