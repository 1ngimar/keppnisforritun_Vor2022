#include <bits/stdc++.h>

using namespace std;

// typedef vector<int> vi;
// typedef vector<vi> vvi;

// typedef pair<int, int> pii;
// typedef vector<pii> vpii; // for edges and also for verticesID and degree of that vertex

int main()
{
    int n, m, a, b;
    // vpii edges; // fylki af pörum (a, b)
    int id, deg;
    map<int, int> v_id_deg;

    // cout << "ready" << endl;
    cin >> n >> m;

    // initialize all vertices in a map with degree of 0
    for (int i = 1; i <= n; i++)
    {
        v_id_deg[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        // pii edge = make_pair(a, b);
        v_id_deg[a]++; // update degree of vertex a
        v_id_deg[b]++; // update degree of vertex b
        // g.push_back(e);
    }

    // Hugmynd:
    // teljum við hve margir hnútar hafa gráðu = 1 og gráðu  = 0
    // fjöldi hnúta með gráðu = 1 = deg1
    // fjöldi hnút með gráðu = 0 = deg0
    // result = 0
    // result += deg0
    // result += deg1 / 2

    int i = 1, j = 2, deg0 = 0, result = 0;
    double deg1 = 0.0;
    for (int i = 1; i <= n; i++)
    {
        if (v_id_deg[i] == 0)
        {
            deg0++;
        }
        else if (v_id_deg[i] == 1)
        {
            deg1++;
        }
    }

    if (deg0 > 0)
    {
        result += deg0 + 1;

        for (int i = 1; i <= n; i++)
        {
            if (v_id_deg[i] == 0)
            {
                if (deg1 > 1)
                {
                    deg1--;
                }
            }
        }
    }

    // int temp = result, i = 1;
    // while (temp > 0)
    // {
    //     if (v_id_deg[i] == 0)
    //     {
    //         v_id_deg[i] = 1;
    //         deg0--;
    //         temp--;
    //     }
    //     else if (v_id_deg[i] == 1)
    //     {
    //         v_id_deg[i] = 2;
    //         deg1--;
    //         temp--;
    //     }
    //     i++;
    // }

    result += ceil(deg1 / 2.0);
    cout << result << endl;
    return 0;
}