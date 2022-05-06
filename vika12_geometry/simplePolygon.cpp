#include <bits/stdc++.h>
using namespace std;
typedef complex<double> pt;
typedef pair<pt, int> pti;
typedef vector<pti> vpti;

// AC, kattis time: 0.07 s

#define EPS 1e-9 // ��arfi � �essu d�mi en h�fum samt af �v� bara

int ccw(pt a, pt b, pt c) // Stoli� fr� Bergi Snorrasyni
{
    if (abs(a - b) < EPS || abs(imag((c - a) / (b - a))) < EPS)
        return 0;
    return imag((c - a) / (b - a)) > 0.0 ? 1 : -1;
}

pt piv;
bool cmp(const pair<pt, int> &p1, const pair<pt, int> &p2) // Stoli� fr� Bergi Snorrasyni
{
    pt a = p1.first;
    pt b = p2.first;
    if (abs(arg(a - piv) - arg(b - piv)) > EPS)
        return arg(a - piv) < arg(b - piv) ? true : false;
    if (abs(abs(a - piv) - abs(b - piv)) < EPS)
        return false;
    return abs(a - piv) < abs(b - piv) ? true : false;
}

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
        vpti a1;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            a1.push_back(pti(pt(x, y), i));
        }

        int i, mn = 0;
        for (i = 1; i < n; i++)
            if (imag(a1[i].first - a1[mn].first) < 0.0 ||
                abs(imag(a1[i].first - a1[mn].first)) < EPS &&
                    real(a1[i].first - a1[mn].first) < 0.0)
                mn = i;

        // setjum min-punktinn fremst
        pti t = a1[mn];
        a1[mn] = a1[0];
        a1[0] = t;
        piv = a1[0].first; // min-punkturinn ver�ur pivot fyrir r��unina � cmp fallinu

        sort(a1.begin() + 1, a1.end(), cmp);

        // n� �arf a� athuga hvort sn�a �urfi vi� seinasta "geislanum" vegna
        // �ess a� annars myndi �etta falla � �essu input:
        // 1
        // 5 0 0 0 1 0 2 1 0 2 0

        // Athugum hvort vi� �urfum a� sn�a vi� seinasta geislanum
        int count = 0;
        int j = n - 1;
        while (ccw(a1[0].first, a1[j].first, a1[j - 1].first) == 0)
        {
            j--;
            count++;
        }

        if (count > 0)
        {
            // sn�um vi� seinasta geisla
            int stop = n - 1 - count;
            sort(a1.rbegin(), a1.rend() - stop, cmp);
        }

        for (auto item : a1)
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