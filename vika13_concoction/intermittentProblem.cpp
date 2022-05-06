#include <bits/stdc++.h>
using namespace std;

// WA

int main()
{
    set<int> mySet;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        mySet.insert(a);
        mySet.insert(b);
    }

    set<int>::iterator itr;
    int left = 0, right = 0, old = 0;
    cout << "Start of output" << endl;
    for (itr = mySet.begin(); itr != mySet.end(); itr++)
    {
        if (left == 0)
        {
            left = *itr;
            itr++;
            right = *itr;
            old = right;
        }
        else
        {
            left = old;
            right = *itr;
            old = right;
        }
        cout << left << " " << right << endl;
    }
    return 0;
}