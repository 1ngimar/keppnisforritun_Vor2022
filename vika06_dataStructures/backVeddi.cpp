#include <bits/stdc++.h>
using namespace std;

int main()
{
    size_t i;
    string str;
    cin >> str;
    // cout << str << endl;
    while ((i = str.find("<")) != str.npos)
    {
        if (i == str.length() - 1)
        {
            str.replace(i-1, 1, "");
        }
        else
        {
            str = str.replace(i, 1, "\b");
        }
    }

    cout << str;

    return 0;
}