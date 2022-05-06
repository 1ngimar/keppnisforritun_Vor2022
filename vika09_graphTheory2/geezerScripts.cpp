#include <bits/stdc++.h>
using namespace std;
typedef long long l;
typedef pair<l, l> ll;
typedef pair<ll, l> ll_l;
typedef pair<ll, ll> ll_ll;

typedef vector<l> vl;
typedef vector<ll> vll;
typedef vector<ll_l> vll_l;
typedef vector<vll> vvll;
typedef vector<vll_l> vvll_l;
typedef vector<ll_ll> vll_ll;

// I'm sorry for the bad typedefs
// AC, Kattis runtime: 0.12 s

l A, H;

l healthLostAfterBattle(ll enemy)
{
    if(enemy.first < 0)
        return enemy.first;
    if(enemy.second % A == 0)
        return enemy.first * ((enemy.second / A) - 1);
    else
        return enemy.first * (enemy.second / A);
}

vl dijkstra(vvll_l &g, l s)
{
    vl dist(g.size(), LLONG_MAX);
    l uHealthLost;
    priority_queue<ll_l> pq;
    dist[s] = 0;
    pq.push(ll_l(ll(0, 0), s));
    while (!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        if (-t.first.first != dist[t.second])
            continue;
        for (ll_l x : g[t.second])
        {
            uHealthLost = healthLostAfterBattle(x.first);
            if (dist[t.second] + uHealthLost < dist[x.second])
            {
                dist[x.second] = dist[t.second] + uHealthLost;
                pq.push(ll_l(ll(-dist[x.second], x.first.second), x.second));
            }
        }
    }
    return dist;
}

int main()
{
    l n, m, e, b, a, h;

    cin >> A >> H;
    cin >> n >> m;
    vvll_l g(n+1, vll_l());
    ll ah;
    for (int i = 0; i < m; i++)
    {
        cin >> e >> b >> a >> h;
        ah = ll(a, h);
        g[e].push_back(ll_l(ah, b));
    }

    vl distances = dijkstra(g, 1);

    if (H - distances[n] < 1)
        cout << "Oh no" << endl;
    else
        cout << H - distances[n] << endl; 

    return 0;
}