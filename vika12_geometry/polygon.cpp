#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdio.h>
#include <complex>
#include <map>
#include<tuple>

// Author: Marzuk Ingi

using namespace std;
typedef complex<double> pt;

#define EPS 1e-9

pt piv;

bool cmp(const tuple<pt, int> p1, const tuple<pt, int> p2) {
    pt a = get<0>(p1), b = get<0>(p2);

    if(abs(arg(a - piv) - arg(b - piv)) > EPS) {
        return arg(a - piv) < arg(b - piv);
    }

    return abs(a - piv) < abs(b - piv);
}

int main() {
    int c;

    complex<double> I = (0.0, 1.0);

    scanf("%d", &c);

    for(int iter = 0; iter < c; iter++) {
        int i, j, n;

        double x;
        double y;
        tuple<pt, int> positions;
        vector<tuple<pt, int>> p;
        int mn = 0;

        scanf("%d", &n);

        for(i = 0; i < n; i++) {
            scanf("%lf %lf", &x, &y);
            //cout << "x is: " << x << " and y is: " << y << endl;
            pt test = complex<double>(x, y);
            positions = make_tuple(test, i);
            p.push_back(positions);
            //positions.insert({test, i});
            //cout << "complex: " << test << " i: " << i << endl;
        }

        //cout << "coords read successfully" << endl;

        for(i = 0; i < n; i++) {
            if((imag(get<0>(p[i]) - get<0>(p[mn])) < 0.0) || (abs(imag(get<0>(p[i]) - get<0>(p[mn]))) < EPS) && (real(get<0>(p[i]) - get<0>(p[mn])) < 0.0)) mn = i;
        }

        pt t = get<0>(p[mn]); int pos = get<1>(p[mn]); get<0>(p[mn]) = get<0>(p[0]); get<1>(p[mn]) = get<1>(p[0]); get<0>(p[0]) = t; get<1>(p[0]) = pos; piv = get<0>(p[0]);

        // for(i = 0; i < n; i++) {
        //     cout << get<0>(p[i]) << " i: " << get<1>(p[i]) << endl;
        // }

        sort(p.begin()+1, p.end(), cmp);

        //Svolítið subbuleg lausn á edge case-inu
        double lastarc = abs(arg(get<0>(p[n-1]) - piv));
        double secondlast = abs(arg(get<0>(p[n-2]) - piv));
        int count = 2;
        int k = 3;

        if(lastarc - secondlast < EPS) {
            vector<tuple<pt,int>> switcheroo;
            switcheroo.push_back(p[n-1]);
            switcheroo.push_back(p[n-2]);

            while(lastarc - abs(arg(get<0>(p[n-k]))) < EPS) {
                switcheroo.push_back(p[n-k]);
                count++;
                k++;
            }

            for(i = 0; i < k; i++) {
                p[n-count] = switcheroo[i];
                count--;
            }
        }



        for(i = 0; i < n; i++) {
            cout << get<1>(p[i]) << " ";
        }

        //cout << "last: " << abs(arg(get<0>(p[n-1]) - piv)) << " second to last: " << abs(arg(get<0>(p[n-2]) - piv));

        cout << endl;
    }

    return 0;
}