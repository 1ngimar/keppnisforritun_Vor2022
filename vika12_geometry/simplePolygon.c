#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#define EPS 1e-9

// UNFINISHED, simplePolygon.cpp has the solution

typedef double _Complex pt;
const int n = 4;

int ccw(pt a, pt b, pt c)
{
    if (cabs(a - b) < EPS || fabs(cimag((c - a) / (b - a))) < EPS)
        return 0;
    return cimag((c - a) / (b - a)) > 0.0 ? 1 : -1;
}

pt piv;
// me� tvo punkta sem eru � sama l�nustriki, �� skilar �etta reiknirit bara ��rum �eirra ... RED ALERT?
int cmp(const void *p1, const void *p2)
{
    pt a = *(pt *)p1, b = *(pt *)p2;
    if (fabs(carg(a - piv) - carg(b - piv)) > EPS)
        return carg(a - piv) < carg(b - piv) ? -1 : 1; // reikna stefnuhorni�
    if (fabs(cabs(a - piv) - cabs(b - piv)) < EPS)
        return 0;
    return cabs(a - piv) < cabs(b - piv) ? -1 : 1; // skilar punktinum sem er n�r
}

// int cmp2(const pair<int, pt> &p1, const pair<int, pt> &p2)
// {
//     pt a = p1.second;
//     pt b = p2.second;
//     double c1, c2, c3, c4, c5, c6, c7, c8;
//     bool b1, b2, b3, b4;
//     c1 = arg(a - piv); // skilar stefnuhorni a og piv ???
//     c2 = arg(b - piv);
//     c3 = abs(c1 - c2);
//     if (c3 > EPS)
//     {
//         if (c1 < c2)
//         {
//             return -1;
//         }
//         return 1;
//     }

//     c4 = abs(a - piv); // fjarl�g� milli a og piv
//     c5 = abs(b - piv); // fjarl�g� milli b og piv
//     c6 = abs(c4 - c5); // � �etta a� vera fabs e�a abs ?, fjarl�g� milli fjarl�g�a???
//     if (c6 < EPS) // ef sami punkturinn ??
//     {
//         return 0;
//     }

//     if (c4 < c5) // ef fjarl�g� a til piv er minni en fjarl�g� b til piv
//     {
//         return -1;
//     }
//     return 1;
// }

int convex_hull(pt *p, pt *h, int n, int *indices)
{
    pt arr[n];
    int i, j = 0, mn = 0;
    // mn er min-punkturinn: �.e.a.s. hann er ne�st til vinstri
    for (i = 1; i < n; i++)
        if (cimag(p[i] - p[mn]) < 0.0 || fabs(cimag(p[i] - p[mn])) < EPS && creal(p[i] - p[mn]) < 0.0)
            mn = i;

    // setjum min-punktinn fremst og �ann fremsta � s�ti� sem min-punkturinn var
    pt t = p[mn];
    p[mn] = p[0];
    p[0] = t;
    // setjum min-punktinn sem pivot punktinn
    piv = p[0];

    // R��um punktum p + 1 til n - 1
    qsort(p + 1, n - 1, sizeof *p, cmp); // g�ti �urft a� vera **p

    for (i = 0; i < n; i++)
    {
        
    }
    

    return 0;
    // for (i = 0; i < n; i++)
    // {

    //     // res[j] = i;
    //     // arr[j] = p[i];
    //     // h[j++] = p[i++];
    // }

    // held a� vi� �urfum ekki rest �v� a� �a� er bara til a� �tiloka mi�ju hn�ta

    // i = 1;
    // for (i = 1; i < n && cabs(p[0] - p[i]) < EPS; i++) // finna fyrsta punktinn sem er ekki s� sami og pivot punkturinn
    //     ;                                              // svo a� �etta hunsar alla punkta sem eru eins, svo vi� �urfum �etta � raun ekki

    // if (i == n) // ef i == n "�� er �etta allt sami punkturinn svo vi� setjum hann fremst � hla�ann"
    // {
    //     res[j] = 0;
    //     arr[j] = p[0];
    //     h[j++] = p[0];
    // }
    // else if (i == n - 1) // ef �a� er bara einn punktur eftir, �� setjum vi� �� b��a � hla�ann
    // {
    //     res[j] = 0;
    //     arr[j] = p[0];
    //     h[j++] = p[0];

    //     res[j] = n - 1;
    //     arr[j] = p[n - 1];
    //     h[j++] = p[n - 1];
    // }
    // if (i >= n - 1)
    // {
    //     return j; // ef fyrri if e�a else if setningin a� ofan keyr�i �� keyrist �essi
    // }
    // res[j] = n - 1;
    // arr[j] = p[n - 1];
    // h[j++] = p[n - 1]; // setjum aftasta punktinn fremst � hla�ann

    // res[j] = 0;
    // arr[j] = p[0];
    // h[j++] = p[0]; // setjum fremsta punktinn nr. 2 � hla�ann

    // res[j] = i;
    // arr[j] = p[i];
    // h[j++] = p[i]; // setjum annan punktinn (punktur nr. 2) � nr. 3 � hla�ann
    // // vegna �ess a� i er fyrsti punkturinn sem er �l�kur fremsta punktinum

    // if (ccw(h[0], h[1], h[2]) == 0) // ef allir �essir punktar liggja � s�mu l�nunni
    // {
    //     return j - (cabs(h[0] - h[1]) < EPS ? 2 : 1);
    // }
    // for (i++; i < n;)
    // {
    //     res[j] = i;
    //     arr[j] = p[i];
    //     h[j++] = p[i++]; // b�tum punkti vi� polygon
    // }
    // return --j;
}

#if 0
9
-1 1
0 1
1 1
-1 0
0 0
1 0
-1 -1
0 -1
1 -1
#endif

int main()
{
    int c;
    scanf("%d", &c);
    while (c > 0)
    {
        c--;
        int i, m, x, y;
        scanf("%d", &n);
        int output[n];
        pt a[n], h[n];
        // pt (*a)[n][2] = malloc(sizeof *a);
        // a = malloc(n * sizeof *a);
        int indices[n];
        pt temp;
        for (i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            temp = x + y * I;
            a[i] = temp;
            h[i] = temp;
            indices[i] = i;
            // (*a)[i][0] = x + y * I;
            // (*a)[i][1] = i;
        }
        m = convex_hull(a, h, n, indices);
        for (i = 0; i < n; i++)
        {
            printf("%d ", indices[i]);
        }
        printf("\n");
    }
    return 0;
}
