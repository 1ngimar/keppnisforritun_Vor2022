#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 30)


int finds(long long n, vector<long long> a) {

    long long m1 = a[n-1] + a[n-2]; 
    // int m3 = m1;
    //optimal
    long long d[m1 + 1];
    for(long long i = 0; i < m1 + 1; i++) {
        d[i] = INF;
    }
    d[0] = 0;
    int xm = 0;
    for(long long i = 0; i < n; i++) {
        for(long long j = 0; j < m1 + 1 - a[i]; j++) {
            if(d[j] < INF) {
                // d[j + a[i]] = d[j] + 1;
                d[j + a[i]] = min(d[j + a[i]], d[j] + 1);
            }
            
        }
    }
    // end optimal 
    long long m2 = m1;
    for(long long i = m1; i >= 0; i--) {
        long long s = 0;
        long long b = 0;
        for(long long j = n - 1; j >= 0; j--) {
            if(a[j] + b <= m2) {
                b += a[j];
                j = n-1;
                s++;
            }
        }
        // cout << d[m2] << ' ';
        if(d[m2] != s){
            // cout << "non-canonical";
            return 2;
            // break;
        }
        if(i == 0) {
            // cout << "canonical" << endl;
            return 3;
            // break;
        }
        m2--; 
    }
    return 0;
}



int main() {

    long long n; // max 100
    cin >> n;
    long long t;
    // long long a[n];
    vector<long long> a;
    int kl = 0;
    for(long long i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
        if(i > 1) {
            int v = finds(a.size(), a);
            if(v == 2) {
                cout << "non-canonical";
                // break;
                return 0;
            }
            // else if(v == 3) {
            //     cout << "canonical" << endl;
            //     break;
            // } else {
            //     continue;
            // }
            // kl++;
        }
    }
    cout << "canonical" << endl;
    return 0;
    // cout << kl;
    // for(int i = 0; i < n; i++) {
    //     cout << a[i] << ' ';
    // }
    
    // finds(n, a);
    // long long m1 = a[n-1] + a[n-2]; 
    // // int m3 = m1;
    // //optimal
    // long long d[m1 + 1];
    // for(long long i = 0; i < m1 + 1; i++) {
    //     d[i] = INF;
    // }
    // d[0] = 0;
    // int xm = 0;
    // for(long long i = 0; i < n; i++) {
    //     for(long long j = 0; j < m1 + 1 - a[i]; j++) {
    //         if(d[j] < INF) {
    //             // d[j + a[i]] = d[j] + 1;
    //             d[j + a[i]] = min(d[j + a[i]], d[j] + 1);
    //         }
            
    //     }
    // }
    // // end optimal 
    // long long m2 = m1;
    // for(long long i = m1; i >= 0; i--) {
    //     long long s = 0;
    //     long long b = 0;
    //     for(long long j = n - 1; j >= 0; j--) {
    //         if(a[j] + b <= m2) {
    //             b += a[j];
    //             j = n-1;
    //             s++;
    //         }
    //     }
    //     // cout << d[m2] << ' ';
    //     if(d[m2] != s){
    //         cout << "non-canonical";
    //         break;
    //     }
    //     if(i == 0) {
    //         cout << "canonical" << endl;
    //         break;
    //     }
    //     m2--; 
    // }
        // 1 5 10 25 100 200

    // return 0;
}