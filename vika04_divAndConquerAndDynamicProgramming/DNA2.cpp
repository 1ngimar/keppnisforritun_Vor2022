#include <bits/stdc++.h>

// WRONG

using namespace std;

int main()
{
    int n, res = 0;
    string str = "";

    cin >> n;
    cin >> str;

    list<int> a, b;

    char c;
    int i = 0, tempCountA = 0, tempCountB = 0;
    while (i < n)
    {
        c = str[i];
        while (c == 'A')
        {
            tempCountA++;
            c = str[++i];
        }
        if (tempCountA > 0)
        {
            a.push_back(tempCountA);
        }
        while (c == 'B')
        {
            tempCountB++;
            c = str[++i];
        }
        if (tempCountB > 0)
        {
            b.push_back(tempCountB);
        }
        tempCountA = 0;
        tempCountB = 0;
    }
    // for (auto item : a_list) cout << item << " ";
    // cout << endl;
    // for (auto item : b_list) cout << item << " ";
    // cout << endl;

    int itr = 0;

    while (!b.empty() && !a.empty())
    {
        if (str[itr] == 'B' || (a.size() > 1 && a.front() > 1))
        {
            res++;
            itr += b.front();
            // itr += a.front();
            b.pop_front();
            // a.pop_front();
        }
        // vantar að halda utanum ef N = 1 (bæði ef A eða B)
        // vantar if setningar til að halda utan um að engin A eru í strengnum og ef að engin B eru
        else if (b.front() == a.front() && a.front() == 1)
        {
            res++;
            itr += a.front();
            itr += b.front();
            a.pop_front();
            b.pop_front();
        }
        else if (b.front() == a.front() && a.front() > 1)
        {
            res += 2;
            itr += a.front();
            itr += b.front();
            a.pop_front();
            b.pop_front();
        }
        else if (a.front() > b.front() && b.front() == 1)
        {
            res++;
            itr += a.front();
            itr += b.front();
            a.pop_front();
            b.pop_front();
        }
        else if (a.front() > b.front() && b.front() > 1)
        {
            res += 2;
            itr += a.front();
            itr += b.front();
            a.pop_front();
            b.pop_front();
        }
        else if (a.front() < b.front())
        {
            res += 2;
            itr += a.front();
            itr += b.front();
            a.pop_front();
            b.pop_front();
        }
        else if (a.front() > b.front() && b.front() > 1)
        {
            res += 2;
            itr += a.front();
            itr += b.front();
            a.pop_front();
            b.pop_front();
        }
    }
    cout << res << endl;
    return 0;
}