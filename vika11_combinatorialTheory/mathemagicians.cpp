#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

// UNFINISHED

#define MAXN 100010

char initial_char[MAXN], preferred_char[MAXN];
int n;

int count_spells(char *arr)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[(i + 1) % n]) // tékkum á öllum mönnum 'hægra-ish' megin við hvern mann
            res++;
    }
    return res;
}

int main()
{
    string initial_str, preferred_str;
    cin >> n >> initial_str >> preferred_str;
    for (int i = 0; i < n; i++)
    {
        char c1 = initial_str[i];
        char c2 = preferred_str[i];
        initial_char[i] = c1;
        preferred_char[i] = c2;
    }

    int count_initial = count_spells(initial_char);
    int count_preferred = count_spells(preferred_char);

    if (count_initial > count_preferred)
    {
        cout << "yes" << endl;
        return 0;
    }
    if (count_initial == n || count_initial == 0 || count_initial < count_preferred)
    {
        cout << "no" << endl;
        return 0;
    }
    cout << "yes" << endl;
    return 0;
}