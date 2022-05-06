#include <bits/stdc++.h>
#define MAXN 10
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)

using namespace std;

int p[MAXN * 5] = {0}, n;

int mySum(int i)
{
    int sum = 0;
    for (int j = i; j > 0; j &= j-1)
    {
        sum += p[j-1];
    }
    return sum;
}

void update(int x, int y)
{
	for (int i = x; i < n; i |= i+1)
    {
        p[i] += y;
    }
}

int query(int i)
{
    return mySum(i+1) - mySum(i);
}

int main()
{
    list<int> output;

    for (int i = 0; i <= n; i++)
        p[i] = 0;
    
    cout << "ready for input" << endl;

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
            // framkvæmi F query, flippa i-ta bitanum í memory
            old = query(i);
            if (old == 0)
                update(i, 1);
            else
                update(i, 0);
            // old = query(i);
        }
        else
        {
            cin >> from >> to;
            // framkvæmi C query, sækja fjölda bita sem eru = 1 á bilinu [from, to]
            output.push_back(mySum(to+1) - mySum(from)); 
        }
    }

    for (auto item : output)
        cout << item << endl;

    return 0;
}