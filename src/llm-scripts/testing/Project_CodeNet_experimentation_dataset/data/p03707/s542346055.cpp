#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;

const int maxn = 2005;
int v[maxn][maxn], e0[maxn][maxn], e1[maxn][maxn];
int n, m, Q, X1, X2, Y1, Y2;
char s[maxn];

int main() {
	scanf("%d%d%d", &n, &m, &Q);
	rep (i, 1, n) {
		scanf("%s", s + 1);
		rep (j, 1, m)
			v[i][j] = s[j] - '0';
	}
	rep (i, 1, n) rep (j, 1, m) if (v[i][j]) {
		if (v[i-1][j]) e0[i][j]++;
		if (v[i][j-1]) e1[i][j]++;
	}
	rep (i, 1, n) rep (j, 1, m) {
		v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];
		e0[i][j] += e0[i-1][j] + e0[i][j-1] - e0[i-1][j-1];
		e1[i][j] += e1[i-1][j] + e1[i][j-1] - e1[i-1][j-1];
	}
	while (Q--) {
		scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
		printf("%d\n", 
			v[X2][Y2] - v[X1-1][Y2] - v[X2][Y1-1] + v[X1-1][Y1-1]
		 - (e0[X2][Y2] - e0[X1][Y2] - e0[X2][Y1-1] + e0[X1][Y1-1])
		 - (e1[X2][Y2] - e1[X1-1][Y2] - e1[X2][Y1] + e1[X1-1][Y1])
		);
	}
	return 0;
}