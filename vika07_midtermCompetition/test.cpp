#include<bits/stdc++.h>

using namespace std;

int countDiv2(int a)
{
    int count = 0;
    while (a % 2 == 0)
    {
        a /= 2;
        count++;
    }
    return count;
}

int main()
{
    int test;
    cin >> test;

    cout << countDiv2(test) << endl;
    return 0;
}