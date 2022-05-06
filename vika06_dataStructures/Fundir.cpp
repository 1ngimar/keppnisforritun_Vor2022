#include <bits/stdc++.h>

#define MAXQ 100001
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)
int p[MAXQ*5], n;
int max(int a, int b) { return a > b ? a : b; }

int qrec(int i, int j, int x, int y, int e) // Hj�lparfall.
{ // Vi� erum a� leita a� bili [x, y] og erum � [i, j].
	if (x == i && y == j) return p[e];
	int m = (i + j)/2;
	if (x <= m && y <= m) return qrec(i, m, x, y, LEFT(e));
	if (x > m && y > m) return qrec(m + 1, j, x, y, RIGHT(e));
	return max(qrec(i, m, x, m, LEFT(e)), qrec(m + 1, j, m + 1, y, RIGHT(e)));
}
int query(int x, int y)
{ // Finnum st�rsta gildi� � [x, y].
	return qrec(0, n - 1, x, y, 1);
}

void urec(int i, int j, int x, int y, int e) // Hj�lparfall.
{ // Vi� erum a� leita a� laufinu [x, x] og erum � [i, j].
	if (i == j) p[e] = y;
	else
	{
		int m = (i + j)/2;
		if (x <= m) urec(i, m, x, y, LEFT(e));
		else urec(m + 1, j, x, y, RIGHT(e));
		p[e] = max(p[LEFT(e)], p[RIGHT(e)]);
	}
}
void update(int x, int y)
{ // L�tum x-ta staki� vera y.
	return urec(0, n - 1, x, y, 1);
}

int slow(int* a, int x, int y)
{ // L�nuleg �tf�rsla til a� bera saman.
	int r = -(1 << 30);
	while (x <= y) r = max(r, a[x++]);
	return r;
}

// �etta forrit pr�far max-range-query, point-assigment-update � slembnar uppf�rlsur.
// Eftir hverja uppf�rslu eru allar m�gulegar fyrirspurnir framkv�mdar.
// Svo forriti� er h�gt, n�nar O(n^3).
int main()
{
	srand(time(NULL));
	n = 10000;
	int i, j, x, y, z, q = 1000000, m = 100;
	int a[n];
	for (i = 0; i < n; i++) a[i] = 0;
	for (i = 0; i < 5*n; i++) p[i] = 0;
	while (q-- != 0)
	{
		x = rand()%n, y = x + rand()%(n - x), z = rand()%(2*m + 1) - m;
		update(x, z), a[x] = z;
		for (i = 0; i < n; i++) for (j = i; j < n; j++) assert(query(i, j) == slow(a, i, j));
	}
	return 0;
}
