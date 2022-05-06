#include<bits/stdc++.h>
#define MAXN 10
#define MAXK 100000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)

using namespace std;

int p[5 * MAXN], o[5 * MAXN], n;


void prop(int x, int y, int e) // Hjálparfall
{							   // Fall sem dreifir lygnum uppfærslum niður um eina hæð.
	p[e] += (y - x + 1) * o[e];
	if (x != y)
		o[LEFT(e)] += o[e], o[RIGHT(e)] += o[e];
	o[e] = 0;
}
int qrec(int i, int j, int x, int y, int e) // Hjálparfall
{											// Við erum að leita að bili [x, y] og erum í [i, j].
	prop(i, j, e);
	if (x == i && y == j)
		return p[e];
	int m = (i + j) / 2;
	if (y <= m)
		return qrec(i, m, x, y, LEFT(e));
	else if (x > m)
		return qrec(m + 1, j, x, y, RIGHT(e));
	return qrec(i, m, x, m, LEFT(e)) + qrec(m + 1, j, m + 1, y, RIGHT(e));
}
int query(int x, int y)
{ // Finnum summuna yfir [x, y].
	return qrec(1, n, x, y, 1);
}
void urec(int i, int j, int x, int y, int z, int e) // Hjálparfall
{													// Við erum að leita að bili [x, y] og erum í [i, j].
	prop(i, j, e);
	if (x == i && y == j)
	{
        o[e] = z;
		return;
	}
	int m = (i + j) / 2;
	p[e] += (y - x + 1) * z;
	if (y <= m)
		urec(i, m, x, y, z, LEFT(e));
	else if (x > m)
		urec(m + 1, j, x, y, z, RIGHT(e));
	else
		urec(i, m, x, m, z, LEFT(e)), urec(m + 1, j, m + 1, y, z, RIGHT(e));
}
void update(int x, int y, int z)
{ // Bætum z við stökin á bilinu [x, y]
	urec(1, n, x, y, z, 1);
}
int slow(int *a, int l, int r)
{
	int x = 0;
	while (l <= r)
		x += a[l++];
	return x;
}

int main()
{
    list<int> output;

    for (int i = 0; i <= n; i++)
		p[i] = o[i] = 0;

    int k;
    cin >> n >> k;

    char c;
    int i, from, to, old;
    for (int j = 0; j < k; j++)
    {
        cin >> c;
        if (c == 'F')
        {
            cin >> i;
            // framkvæma F query, flippa i-ta bitanum í memory
            old = query(i, i);
            if (old == 0)
                update(i, i, 1);
            else
                update(i, i, 0); 
        }
        else {
            cin >> from >> to;
            output.push_back(query(from, to)); // framkvæma C query, sækja fjölda bita sem eru = 1 á bilinu [from, to]
        }
    }

    for (auto item : output)
        cout << item << endl;

    return 0;
}