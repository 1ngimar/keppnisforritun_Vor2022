#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// AC kattis time: 0.01 sec

map<string, ll> myMap;
ll modulo = pow(10, 9) + 7;

void init(int n)
{
    string outerBlimp, innerBlimp;
    ll h, s;
    for (int i = 0; i < n; i++)
    {
        cin >> ws;
        getline(cin, outerBlimp);
        cin >> h >> s;

        for (int j = 0; j < s; j++) 
        {
            // because the first blimp will have no inner blimps 
            // this will not run for the first one
            cin >> ws;
            getline(cin, innerBlimp);
            h += myMap[innerBlimp];
        }
        // add the outer blimp with the key = <it's name(or color)> and value = health of all inner blimps
        // myUMap[outerBlimp] = h - floor((h / modulo)) * modulo;
        myMap[outerBlimp] = h % modulo;
    }
}

int main()
{   
    int n, m;
    cin >> n >> m;
    init(n);

    string spawnedBlimps;
    ll countOfBlimps;
    unsigned long long result = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> ws;
        getline(cin, spawnedBlimps);
        cin >> countOfBlimps;
        result += myMap[spawnedBlimps] * countOfBlimps;
    }
    result = result % modulo;
    cout << result << endl;
    return 0;
}
