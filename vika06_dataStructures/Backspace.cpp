#include <bits/stdc++.h>

#define MAXN 1000001

// AC, kattis time: 0.07 sec

using namespace std;

int main()
{
    string str = "";
    getline(cin, str);

    char c;
    list<char> cl;
    for (int i = 0; i < str.length(); i++)
    {
        c = str[i];
        if (c == '<')
        {
            cl.pop_back();
        }
        else 
        {
            cl.push_back(c);
        }
    }

    string res = "";
    for (auto item : cl)
    {
        res += item;
    }

    cout << res << endl;
    return 0;
}