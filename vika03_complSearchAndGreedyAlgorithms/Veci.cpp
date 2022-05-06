// Your program will be given an integer X.
// Find the smallest number larger than X consisting of the same digits as X.

// Input:
// The first line of input contains the integer X (1 ? X ? 999999).
// The first digit in X will not be a zero.

// Output:
// Output the result on a single line. If there is no such number, output 0.

#include <bits/stdc++.h>

// AC, kattis time: 0.00 sec

using namespace std;

int veci(vector<int> x_ints, int n, int i, int j)
{
    bool myBool = false;
    int temp = 0, result = 0;
    string s = "";
    while (i > 0)
    {
        while (j > 0)
        {
            if (x_ints[i] > x_ints[--j])   
            {
                temp = x_ints[j];
                x_ints[j] = x_ints[i];
                x_ints[i] = temp;
                myBool = true;
                break;
            }
        }
        if (myBool)
        {
            break;
        }
        i--;
        j = i;
    }
    if (myBool)
    {
        vector<int> rest;
        vector<int> result_vec;
        int k = 0;
        for (k = j+1; k < n; k++)
        {
            rest.push_back(x_ints[k]);
        }
        sort(rest.begin(), rest.end());
        for (k = 0; k < j+1; k++)
        {
            result_vec.push_back(x_ints[k]);
        }
        for (k = 0; k < rest.size(); k++)
        {
            result_vec.push_back(rest[k]);
        }
        for (auto item : result_vec)
            s += to_string(item);
        result = stoi(s);
    }
    return result;
}

int main()
{
    string x_str;
    cin >> x_str;
    int x_int_original = stoi(x_str);
    int result;

    int n = x_str.length();

    vector<int> x_ints;
    string s;
    for (int i = 0; i < n; i++)
    {
        s = x_str[i];
        x_ints.push_back(stoi(s));
    }

    int i = n - 1, j = n - 1;
    result = veci(x_ints, n, i, j);
    cout << result << endl;
    return 0;
}