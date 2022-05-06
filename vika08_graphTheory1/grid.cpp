#include <bits/stdc++.h>

// AC, kattis time: 0.02 sec

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, m;

int main()
{
    cin >> n >> m;

    vvi g_init;
    for (int i = 0; i < n; i++)
    {
        vi gn;
        string input, tempStr;
        int digits[m], x;
        cin >> input;
        for (int j = 0; j < m; j++)
        {
            tempStr = input[j];
            x = stoi(tempStr);
            gn.push_back(x);
        }
        g_init.push_back(gn);
        gn.clear();
    }

    int visited[n][m], dist[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = -1;
            visited[i][j] = false;
        }
    }

    ii par;
    queue<ii> q1;
    int i, j, stepSize, temp;
    q1.push(make_pair(0, 0));
    visited[0][0] = true;
    dist[0][0] = 0;
    while (!q1.empty())
    {
        ii current = q1.front();
        q1.pop();
        i = current.first;
        j = current.second;
        stepSize = g_init[i][j];
        for (int dir = 0; dir < 4; dir++) // check all directions
        {
            switch (dir)
            {
            case 0: // right
                temp = j + stepSize;
                if (temp < m)
                {
                    if (!visited[i][temp])
                    {
                        par = make_pair(i, temp);
                        q1.push(par);
                        visited[i][temp] = true;
                        dist[i][temp] = dist[i][j] + 1;
                    }
                }
                break;
            case 1: // down
                temp = i + stepSize;
                if (temp < n)
                {
                    if (!visited[temp][j])
                    {
                        par = make_pair(temp, j);
                        q1.push(par);
                        visited[temp][j] = true;
                        dist[temp][j] = dist[i][j] + 1;
                    }
                }
                break;
            case 2: // left
                temp = j - stepSize;
                if (temp >= 0)
                {
                    if (!visited[i][temp])
                    {
                        par = make_pair(i, temp);
                        q1.push(par);
                        visited[i][temp] = true;
                        dist[i][temp] = dist[i][j] + 1;
                    }
                }
                break;
            case 3: // up
                temp = i - stepSize;
                if (temp >= 0)
                {
                    if (!visited[temp][j])
                    {
                        par = make_pair(temp, j);
                        q1.push(par);
                        visited[temp][j] = true;
                        dist[temp][j] = dist[i][j] + 1;
                    }
                }
                break;
            default:
                break;
            }
        }
    }
    cout << dist[n-1][m-1] << endl;

    return 0;
}