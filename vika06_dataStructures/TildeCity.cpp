#include <bits/stdc++.h>
#define MAXN 100000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)

// AC, kattis time: 0.34 sec

using namespace std;

typedef long long ll;
typedef long double ld;

ll p[5 * MAXN], o[5 * MAXN];
ll p2[5 * MAXN], o2[5 * MAXN];
int n;

// Segment tree functions #################################################
void prop(ll x, ll y, ll e) // Hjálparfall
{                              // Fall sem dreifir lygnum uppfærslum niður um eina hæð.
    p[e] += (y - x + 1) * o[e];
    if (x != y)
    {
        o[LEFT(e)] += o[e];
        o[RIGHT(e)] += o[e];
    }
    o[e] = 0;
}
void prop2(ll x, ll y, ll e) // Hjálparfall
{                               // Fall sem dreifir lygnum uppfærslum niður um eina hæð.
    p2[e] += (y - x + 1) * o2[e];
    if (x != y)
    {
        o2[LEFT(e)] += o2[e];
        o2[RIGHT(e)] += o2[e];
    }
    o2[e] = 0;
}

ll qrec(ll i, ll j, ll x, ll y, ll e) // Hjálparfall
{                                           // Við erum að leita að bili [x, y] og erum í [i, j].
    prop(i, j, e);
    if (x == i && y == j)
        return p[e];
    ll m = (i + j) / 2;
    if (y <= m)
        return qrec(i, m, x, y, LEFT(e));
    else if (x > m)
        return qrec(m + 1, j, x, y, RIGHT(e));
    return qrec(i, m, x, m, LEFT(e)) + qrec(m + 1, j, m + 1, y, RIGHT(e));
}
ll qrec2(ll i, ll j, ll x, ll y, ll e) // Hjálparfall
{                                            // Við erum að leita að bili [x, y] og erum í [i, j].
    prop2(i, j, e);
    if (x == i && y == j)
        return p2[e];
    ll m = (i + j) / 2;
    if (y <= m)
        return qrec2(i, m, x, y, LEFT(e));
    else if (x > m)
        return qrec2(m + 1, j, x, y, RIGHT(e));
    return qrec2(i, m, x, m, LEFT(e)) + qrec2(m + 1, j, m + 1, y, RIGHT(e));
}

ll query(ll x, ll y)
{ // Finnum summu aldurs allra íbúa yfir [x, y].
    return qrec(1, n, x, y, 1);
}
ll query2(ll x, ll y)
{ // Finnum summu fjölda íbúa yfir [x, y].
    return qrec2(1, n, x, y, 1);
}

void urec(ll i, ll j, ll x, ll y, ll z, ll e) // Hjálparfall
{                                                   // Við erum að leita að bili [x, y] og erum í [i, j].
    prop(i, j, e);
    if (x == i && y == j)
    {
        o[e] = z;
        return;
    }
    ll m = (i + j) / 2;
    p[e] += (y - x + 1) * z;
    if (y <= m)
        urec(i, m, x, y, z, LEFT(e));
    else if (x > m)
        urec(m + 1, j, x, y, z, RIGHT(e));
    else
        urec(i, m, x, m, z, LEFT(e)), urec(m + 1, j, m + 1, y, z, RIGHT(e));
}
void urec2(ll i, ll j, ll x, ll y, ll z, ll e) // Hjálparfall
{                                                    // Við erum að leita að bili [x, y] og erum í [i, j].
    prop2(i, j, e);
    if (x == i && y == j)
    {
        o2[e] = z;
        return;
    }
    ll m = (i + j) / 2;
    p2[e] += (y - x + 1) * z;
    if (y <= m)
        urec2(i, m, x, y, z, LEFT(e));
    else if (x > m)
        urec2(m + 1, j, x, y, z, RIGHT(e));
    else
        urec2(i, m, x, m, z, LEFT(e)), urec2(m + 1, j, m + 1, y, z, RIGHT(e));
}

void update1(ll x, ll y, ll z)
{                           // Bætum z við stökin á bilinu [x, y] (aldurs-summa)
    urec(1, n, x, y, z, 1); // uppfæri po biltréð
}
void update2(ll x, ll y, ll z)
{                            // Bætum z við stökin á bilinu [x, y] (fjöldi)
    urec2(1, n, x, y, z, 1); // uppfæri p2o2 biltréð
}
// ####################################################################

int main()
{
    list<ld> output;
    int q;
    cin >> n >> q;

    for (int i = 0; i <= n; i++)
        p[i] = o[i] = p2[i] = o2[i] = 0;

    ll k, a, b;
    for (ll i = 1; i <= n; i++)
    {
        cin >> k;
        update2(i, i, k);
        for (ll j = 1; j <= k; j++)
        {
            cin >> a;
            update1(i, i, a); // set aldur íbúa sem lauf í bæði biltré po og í biltré p2o2
        }
    }

    ll queryNumber, A = 0;
    ld count_d, sum_d;
    for (ll i = 0; i < q; i++)
    {
        cin >> queryNumber;
        if (queryNumber == 1)
        { // Nýr einstaklingur sem eru b ára gamall flytur í hús a
            cin >> a >> b;
            update1(a, a, b - A);
            update2(a, a, 1);
            // ath: einstaklingurinn sem er b ára gamall er NÝR!
        }
        else if (queryNumber == 2)
        { // allir íbúar eldast um a ár
            cin >> a;
            A += a;
        }
        else if (queryNumber == 3)
        { // reiknum meðalaldur allra íbúa frá og með húsi a til og með húsi b
            cin >> a >> b;
            sum_d = (ld)query(a, b);    // finnum summu ALDURS íbúa í húsum á bilinu [a, b]
            count_d = (ld)query2(a, b); // finnum summu FJÖLDA íbúa í húsum á bilinu [a, b]
            sum_d += A * count_d;
            output.push_back(sum_d / count_d);
        }
    }

    for (auto item : output)
    {
        // printf("%.10g\n", item);
        printf("%Lf\n", item);
        // cout << item << endl; // prentum út alla útreikninga fyrir hvert queryNumber == 3
    }
    return 0;
}