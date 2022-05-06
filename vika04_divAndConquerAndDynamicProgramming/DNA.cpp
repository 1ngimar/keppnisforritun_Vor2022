#include <bits/stdc++.h>

// WRONG

using namespace std;

int fun(vector<char> dna, int n, int i, int res)
{
    // for (int j = 0; j < n-1; j++)
    // {
    //     if (dna[j] == 'A' && dna[j + 1] == 'A' && j == n - 2)
    //     {
    //         return res;
    //     }
    // }
    bool myBool2 = false;
    for (char item : dna)
    {
        if (item == 'B')
        {
            myBool2 = true;
            break;
        }
    }
    if (!myBool2)
    {
        return res;
    }
    
    bool myBool = false;
    while (dna[i] == 'A' && i < n)
    {
        dna[i] = 'B';
        i++;
        myBool = true;
    }
    if (myBool)
    {
        return fun(dna, n, i, ++res);
    }
    while (dna[i] == 'B' && i < n && !myBool)
    {
        dna[i] = 'A';
        i++;
    }
    return fun(dna, n, i, ++res);
}

int main()
{
    int n, countA = 0, countB = 0, res = 0, temp, changes = 0;
    cin >> n;
    bool a_cameLast = false, b_cameLast = false;

    vector<char> dna;
    string str = "";
    cin >> str;

    char c;
    for (int i = 0; i < n; i++)
    {
        c = str[i];
        if (c == 'A' && a_cameLast)
        {
            dna.push_back('A');
            b_cameLast = false;
        }
        else if (c == 'A' && !a_cameLast)
        {
            dna.push_back('A');
            b_cameLast = false;
        }
        else if (c == 'B' && a_cameLast)
        {
            dna.push_back('B');
            a_cameLast = false;
        }
        else if (c == 'B' && !a_cameLast)
        {
            dna.push_back('B');
        }
        if (c == 'A' && !a_cameLast)
        {
            countA++;
            a_cameLast = true;
        }
        else if (c == 'B' && !b_cameLast)
        {
            countB++;
            b_cameLast = true;
        }
        
    }
    if (countA < countB)
    {
        res = fun(dna, n, 0, 0);
    }
    res += countB;
    cout << res << endl;
    return 0;
}