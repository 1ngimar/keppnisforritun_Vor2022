#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

// WA, þessi lausn virkar ekki fyrir mínustölur í punktum á y-ás

int main()
{
    list<list<int>> output;
    int c;
    cin >> c;
    while (c-- > 0)
    {
        list<int> sub_output;
        int n, x, y;
        cin >> n;
        viii a;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            a.push_back(iii(i, ii(x, y)));
        }
        vii b;
        iii big_pair;
        ii s_pair;
        for (int i = 0; i < n; i++)
        {
            big_pair = a[i];
            s_pair = big_pair.second;
            x = s_pair.first;
            if (s_pair.second < 0)
            {
                x *= -10000;
            }
            else
                x *= 10000;
            x += s_pair.second;
            b.push_back(ii(x, a[i].first));
        }

        sort(b.begin(), b.end());

        for (auto item : b)
        {
            sub_output.push_back(item.second);
        }
        output.push_back(sub_output);
    }
    for (auto list_i : output)
    {
        for (auto item : list_i)
        {
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}