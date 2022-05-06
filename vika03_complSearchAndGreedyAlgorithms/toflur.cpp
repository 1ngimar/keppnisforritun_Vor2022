#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
// best kattis time 0.32


int main()
{
    int n, i;
    long long sum = 0;
    cin >> n;
    vector<long long> a(n);
    for (i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (i = 0; i < n-1; i++)
    {
        sum += pow((a[i] - a[i+1]), 2);
    }
    cout << sum << endl;
    return 0;
}