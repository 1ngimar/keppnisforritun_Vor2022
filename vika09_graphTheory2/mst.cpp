#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair<int, vii> ivii;

// AC, kattis time: 0.36 sec

#define INF (1 << 30)

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

ivii kruskal(vvii &g)
{
    vii tree;
    priority_queue<iii> s;
    union_find uf(g.size());
    int res = 0;
    for (int i = 0; i < g.size(); ++i)
    {
        for (auto x : g[i])
        {
            s.push(iii(-x.first, ii(x.second, i)));
        }
    }
    while (uf.size(0) < g.size())
    {
        if (s.empty()) // if there are no more edges to check
        {
            tree.clear();                 // just saving memory for fun
            return make_pair(-INF, tree); // No MST possible
        }
        auto x = s.top();
        s.pop();
        if (uf.united(x.second.first, x.second.second))
            continue;

        // adding edge to the tree
        if (x.second.first < x.second.second)
            tree.push_back(make_pair(x.second.first, x.second.second));
        else
            tree.push_back(make_pair(x.second.second, x.second.first));
        res -= x.first;
        uf.unite(x.second.first, x.second.second);
    }
    return make_pair(res, tree);
}

int main()
{
    queue<int> costOutput;
    queue<vii> treeOutput;
    queue<int> nQueue;
    while (true)
    {
        int n, m, u, v, w;
        cin >> n >> m;
        vvii g(n, vii());
        if (n == 0 && m == 0)
        {
            break;
        }
        nQueue.push(n);
        ivii output;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            g[u].push_back(ii(w, v));
            g[v].push_back(ii(w, u));
        }
        output = kruskal(g);
        costOutput.push(output.first);
        treeOutput.push(output.second);
    }

    vii tree;
    while (!costOutput.empty())
    {
        if (costOutput.front() == -INF)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << costOutput.front() << endl;
            tree = treeOutput.front();
            sort(tree.begin(), tree.end());
            for (ii par : tree)
            {
                cout << par.first << " " << par.second << endl;
            }
        }
        costOutput.pop();
        treeOutput.pop();
        nQueue.pop();
    }
    return 0;
}