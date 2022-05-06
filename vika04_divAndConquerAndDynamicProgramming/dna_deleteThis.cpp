#include<cstdio>
#include <bits/stdc++.h>

using namespace std;

inline int min( int a, int b )
{ return a>b?b:a; }

// char s[1000005];
// int f[1000005], g[1000005];

int main()
{
	int n;
    string s = "";
    cin >> n;
    cin >> s;


    vector<int> firstVec(n+1), secondVec(n+1);
	// f[0] = g[0] = 0;

	for(int i=0; i<n; i++)
		if( s[i] == 'B' )
		{
            secondVec[i+1] = secondVec[i];
			firstVec[i+1] = 1 + min( firstVec[i], secondVec[i] );
		}
		else
		{
			firstVec[i+1] = firstVec[i];
			secondVec[i+1] = 1 + min( firstVec[i], secondVec[i] );
		}
	printf("%d\n", firstVec.back());
}
