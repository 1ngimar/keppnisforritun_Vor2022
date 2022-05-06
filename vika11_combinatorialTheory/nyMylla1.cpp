#include <bits/stdc++.h>
using namespace std;

// UNFINISHED

int fyrri()
{
    cout << "Fyrri!" << endl;
    return 0;
}

int seinni()
{
    cout << "Seinni!" << endl;
    return 0;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    // base case: if the first player can't fill k boxes initially, then the second player wins
    if (n + m <= k)
    {
        seinni();
    }


    
    return 0;
}