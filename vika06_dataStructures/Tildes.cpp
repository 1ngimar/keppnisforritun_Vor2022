// Here we use union find
// AC, kattis time: 1.23 sec

#include<bits/stdc++.h>
#define MAXN 1000001

using namespace std;

int p[MAXN]; // = [-1, -1, ..., -1]
int find(int x)
{
	return p[x] < 0 ? x : (p[x] = find(p[x]));
}

void join(int x, int y)
{
	int rx = find(x), ry = find(y);
	if (rx == ry) return;
	if (p[rx] > p[ry]) p[ry] += p[rx], p[rx] = ry;
	else p[rx] += p[ry], p[ry] = rx;
}

int main()
{
    list<int> output;
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) p[i] = -1;

    char c;
    int a, b, q_iter = 0;
    while (q_iter < q)
    {
        cin >> c;
        cin >> a;
        if (c == 't')
        {
            cin >> b;
            join(a, b);
        }
        else
        {
            output.push_back(-p[find(a)]);
        }
        q_iter++;
    }

    for (auto item : output)
    {
        cout << item << endl;
    }
    return 0;
}