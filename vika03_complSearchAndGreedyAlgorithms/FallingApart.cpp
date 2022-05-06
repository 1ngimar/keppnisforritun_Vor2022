#include <iostream>
#include <vector>
#include <algorithm>

// AC

using namespace std;

int main()
{
    int n, item, Alice = 0, Bob = 0;
    vector<int> digits;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        digits.push_back(item);
    }
    sort(digits.begin(), digits.end());

    while (!digits.empty())
    {
        Alice += digits.back();
        digits.pop_back();
        if (!digits.empty())
        {
            Bob += digits.back();
            digits.pop_back();
        }
    }
    cout << Alice << " " << Bob << endl;
}