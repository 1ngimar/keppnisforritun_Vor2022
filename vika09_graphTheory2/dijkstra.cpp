#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

// From Atli Fannar Franklín
// For finding the smallest distance of travel from any vertex to the last vertex
// 

vi dijkstra(vvii &g, int s)
{
    vi dist(g.size(), INT_MAX);
    priority_queue<ii> pq;
    dist[s] = 0;
    pq.push(ii(0, s));
    while (!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        if (-t.first != dist[t.second])
            continue;
        for (ii x : g[t.second])
        {
            if (dist[t.second] + x.first < dist[x.second])
            {
                dist[x.second] = dist[t.second] + x.first;
                pq.push(ii(-dist[x.second], x.second));
            }
        }
    }
    return dist;
}

int main()
{
    int n, m, a, b, weight;

    cin >> n >> m;
    vvii g(n+1, vii()); // ef hnútar eru merktir frá 1 til n
    // líka er hægt að gera bara inntakshnútur-1 ef hnútar eru frá 1 til n 
    
    // vvii g(n, vii()); // ef hnútar eru merktir frá 0 til n-1
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> weight;
        g[a].push_back(ii(weight, b));
    }

    vi distances = dijkstra(g, 1); // ef hnútar eru merktir frá 1 til n
    // vi distances = dijkstra(g, 0); // ef hnútar eru merktir frá 0 til n-1
    for (auto item : distances)
        cout << item << endl;

    return 0;
}