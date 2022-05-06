#include <bits/stdc++.h>
#define MAXQ 11
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)

// UNFINISHED -------------------------------------------------------------------

using namespace std;

typedef long long ll;
typedef long double ld;

int threk1[5 * MAXQ], threk2[5 * MAXQ];
int skyns1[5 * MAXQ], skyns2[5 * MAXQ];
int n;

int mmin(int a, int b)
{
    if (a < b && a > 0)
    {
        return a;
    }
    return b;
}

int max(int a, int b) { return a > b ? a : b; }

void prop1(int x, int y, int e)
{ // Fall sem dreifir lygnum uppf�rslum ni�ur um eina h��.
    threk1[e] += (y - x + 1) * threk2[e];
    if (x != y)
        threk2[LEFT(e)] += threk2[e], threk2[RIGHT(e)] += threk2[e];
    threk2[e] = 0;
}
void prop2(int x, int y, int e)
{ // Fall sem dreifir lygnum uppf�rslum ni�ur um eina h��.
    skyns1[e] += (y - x + 1) * skyns2[e];
    if (x != y)
        skyns2[LEFT(e)] += skyns2[e], skyns2[RIGHT(e)] += skyns2[e];
    skyns2[e] = 0;
}

// finna l�gsta skynsemisgildi starfsmanns sem hefur �rek � bilinu [c,d]
int qrec11(int i, int j, int x, int y, int e)
{ // Vi� erum a� leita a� bili [x, y] og erum � [i, j].
    prop2(i, j, e);
    if (x == i && y == j)
        return skyns1[e];
    int m = (i + j) / 2;
    if (y <= m)
        return qrec11(i, m, x, y, LEFT(e));
    else if (x > m)
        return qrec11(m + 1, j, x, y, RIGHT(e));
    return min(qrec11(i, m, x, m, LEFT(e)), qrec11(m + 1, j, m + 1, y, RIGHT(e)));
}
int query11(int x, int y)
{ // Finnum l�sta skynsemisgildi sem hefur �rek � bilinu [c,d]
    return qrec11(0, skyns1[0] - 1, x, y, 1);
}

// // finna h�sta skynsemisgildi starfsmanns sem hefur �rek � bilinu [c,d]
int qrec12(int i, int j, int x, int y, int e)
{ // Vi� erum a� leita a� bili [x, y] og erum � [i, j].
    prop2(i, j, e);
    if (x == i && y == j)
        return skyns1[e];
    int m = (i + j) / 2;
    if (y <= m)
        return qrec12(i, m, x, y, LEFT(e));
    else if (x > m)
        return qrec12(m + 1, j, x, y, RIGHT(e));
    return max(qrec12(i, m, x, m, LEFT(e)), qrec12(m + 1, j, m + 1, y, RIGHT(e)));
}
int query12(int x, int y)
{ // Finnum h�sta skynsemisgildi sem hefur �rek � bilinu [c,d]
    return qrec12(0, skyns1[0] - 1, x, y, 1);
}

int qrec21(int i, int j, int x, int y, int e)
{ // Vi� erum a� leita a� bili [x, y] og erum � [i, j].
    prop1(i, j, e);
    if (x == i && y == j)
        return threk1[e];
    int m = (i + j) / 2;
    if (y <= m)
        return qrec21(i, m, x, y, LEFT(e));
    else if (x > m)
        return qrec21(m + 1, j, x, y, RIGHT(e));
    return min(qrec21(i, m, x, m, LEFT(e)), qrec21(m + 1, j, m + 1, y, RIGHT(e)));
}
int query21(int x, int y)
{ // Finnum l�sta �rekgildi sem hefur skynsemisgildi � bilinu x,y
    return qrec21(0, threk1[0] - 1, x, y, 1);
}

int qrec22(int i, int j, int x, int y, int e)
{ // Vi� erum a� leita a� bili [x, y] og erum � [i, j].
    prop1(i, j, e);
    if (x == i && y == j)
        return threk1[e];
    int m = (i + j) / 2;
    if (y <= m)
        return qrec22(i, m, x, y, LEFT(e));
    else if (x > m)
        return qrec22(m + 1, j, x, y, RIGHT(e));
    return max(qrec22(i, m, x, m, LEFT(e)), qrec22(m + 1, j, m + 1, y, RIGHT(e)));
}
int query22(int x, int y)
{ // Finnum h�sta �rekgildi sem hefur skynsemisgildi � bilinu x,y
    return qrec22(0, threk1[0] - 1, x, y, 1);
}

void urec1(int i, int j, int x, int y, int z, int e)
{ // Vi� erum a� leita a� bili [x, y] og erum � [i, j].
    prop1(i, j, e);
    if (x == i && y == j)
    {
        skyns2[e] = z;
        return;
    }
    int m = (i + j) / 2;
    skyns1[e] += (y - x + 1) * z;
    if (y <= m)
        urec1(i, m, x, y, z, LEFT(e));
    else if (x > m)
        urec1(m + 1, j, x, y, z, RIGHT(e));
    else
        urec1(i, m, x, m, z, LEFT(e)), urec1(m + 1, j, m + 1, y, z, RIGHT(e));
}
void update1(int x, int y, int z)
{ // B�tum z af skynsemi vi� st�kin � bilinu [x, y]
    urec1(0, skyns1[0] - 1, x, y, z, 1);
}

void urec2(int i, int j, int x, int y, int z, int e)
{ // Vi� erum a� leita a� bili [x, y] og erum � [i, j].
    prop2(i, j, e);
    if (x == i && y == j)
    {
        threk2[e] = z;
        return;
    }
    int m = (i + j) / 2;
    threk1[e] += (y - x + 1) * z;
    if (y <= m)
        urec2(i, m, x, y, z, LEFT(e));
    else if (x > m)
        urec2(m + 1, j, x, y, z, RIGHT(e));
    else
        urec2(i, m, x, m, z, LEFT(e)), urec2(m + 1, j, m + 1, y, z, RIGHT(e));
}
void update2(int x, int y, int z)
{ // B�tum z af �reki vi� st�kin � bilinu [x, y]
    urec2(0, threk1[0] - 1, x, y, z, 1);
}

void init(int n)
{
    int i;
    for (i = 0; i < 5 * n; i++)
        threk1[i] = threk2[i] = skyns1[i] = skyns2[i] = 0;
    threk1[0] = n;
    skyns2[0] = n;
}

int main()
{
    list<list<int>> output;
    cout << "ready" << endl;
    cin >> n;

    init(n);

    int t, c, d;
    list<int> templist;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> c >> d;
        if (t == 1)
        {
            update1(c, d, c);
            update2(c, d, d);
        }
        else if (t == 2)
        {
            update1(c, d, -c);
            update2(c, d, -d);
        }
        else if (t == 3)
        {
            // finna l�gsta skynsemisgildi starfsmanns sem hefur �rek � bilinu [c,d]
            templist.push_back(query11(c, d));
            // finna h�sta skynsemisgildi starfsmanns sem hefur �rek � bilinu [c,d]
            templist.push_back(query12(c, d));
            output.push_back(templist);
        }
        else if (t == 4)
        {
            // finna l�gsta �rekgildi starfsmanns sem hefur skynsemi � bilinu [c,d]
            templist.push_back(query21(c, d));
            // finna h�sta �rekgildi starfsmanns sem hefur skynsemi � bilinu [c,d]
            templist.push_back(query22(c, d));
            output.push_back(templist);
        }
        templist.clear();
    }

    while (!output.empty())
    {
        list<int> tempList2 = output.front();
        for (auto item : tempList2)
        {
            // if (item == 0)
            // {
            //     cout << "Enginn!";
            //     break;
            // }
            // else
            cout << item << " ";
        }
        cout << endl;
        output.pop_front();
    }

    return 0;
}