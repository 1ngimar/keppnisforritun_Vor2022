#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;


// Held að þetta sé eulerian circuit dæmi.
// Ef það er til eulerian circuit þá er lausn til.
// Að finna lausnina er vandamálið...


vi eulerCircuitWithSimpathy(vvi &g) 
{
    vi deg(g.size()), res;

    // get the degree of each vertex
    for (vi v : g) 
        for (int x : v)
            deg[x]++;

    // check if each vertex has an even degree, because if it does not
    // then there is no eulerian circuit possible
    // for (int i = 0; i < g.size(); i++)
    //     if (deg[i] % 2 != 0)
    //         return;
    
    




}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    vvi g(n, vi());

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }

    // cout << eulerCircuit(g) << endl;
    // if (mightBeEuler(g))
    // {

    // }
    // else
    // {
    //     cout << "Ekki haegt" << endl;
    // }
    return 0;
}