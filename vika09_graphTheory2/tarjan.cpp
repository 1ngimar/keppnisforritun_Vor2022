#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
struct union_find
{
    vi p;
    union_find(int n) : p(n, -1) {}
    int find(int x)
    {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    bool united(int x, int y)
    {
        return find(x) == find(y);
    }
    void unite(int x, int y)
    {
        int xp = find(x), yp = find(y);
        if (xp == yp)
            return;
        if (p[xp] > p[yp])
            swap(xp, yp);
        p[xp] += p[yp], p[yp] = xp;
        return;
    }
    int size(int x) { return -p[find(x)]; }
};
vi ord;
vector<bool> done;
void dfs(vvi &g, int v)
{
    done[v] = true;
    for (int x : g[v])
        if (!done[x])
            dfs(g, x);
    ord.push_back(v);
}
pair<union_find, vi> tarjan(vvi &g)
{
    ord.clear();
    union_find uf(g.size());
    vi dag;
    vvi gr(g.size());
    for (int i = 0; i < g.size(); ++i)
    {
        for (int x : g[i])
        {
            gr[x].push_back(i);
        }
    }
    done.resize(g.size());
    for (int i = 0; i < g.size(); ++i)
        done[i] = false;
    for (int i = 0; i < g.size(); ++i)
        if (!done[i])
            dfs(gr, i);
    for (int i = 0; i < g.size(); ++i)
        done[i] = false;
    stack<int> s;
    for (int i = g.size() - 1; i >= 0; --i)
    {
        if (done[ord[i]])
            continue;
        s.push(ord[i]);
        dag.push_back(ord[i]);
        while (!s.empty())
        {
            int t = s.top();
            done[t] = true;
            s.pop();
            uf.unite(t, ord[i]);
            for (int x : g[t])
            {
                if (!done[x])
                    s.push(x);
            }
        }
    }
    reverse(dag.begin(), dag.end());
    return make_pair(uf, dag);
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    vvi g(n, vi());
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        // g[--a].push_back(--b);
        g[a].push_back(b);
    }
    auto t = tarjan(g);
    for (int x : t.first.p)
    {
        cout << x << ' ';
    }
    cout << endl;
    for (int x : t.second)
    {
        cout << x << ' ';
    }
    cout << endl;
}
