#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5 + 100, base = 13, m1 = 1e9 + 7, m2 = 1e9 + 9;

int n, a[maxN + 1], b[maxN + 1];
int ha[2][35][maxN + 1], hb[2][35], hc[2][35];
int pw[2][maxN + 1], ans[35][maxN + 1];

inline int read()
{
	int num = 0, f = 1;
	char ch = getchar();
	while( !isdigit( ch ) ) { if(ch == '-') f = -1; ch = getchar(); }
	while( isdigit( ch ) ) num = (num << 3) + (num << 1) + (ch ^ 48), ch = getchar();
	return num * f;
}

int main()
{
	n = read();
	for(int i = 1; i <= n; i++) a[i] = a[i + n] = read();
	for(int i = 1; i <= n; i++) b[i] = read();

	pw[0][0] = pw[1][0] = 1;
	for(int i = 1; i <= 2 * n; i++) pw[0][i] = 1ll * pw[0][i - 1] * base % m1, pw[1][i] = 1ll * pw[1][i - 1] * base % m2;

	for(int i = 1; i <= 2 * n; i++)
		for(int j = 0; j < 30; j++)
		{
			int x = (a[i] >> j) & 1;
			ha[0][j][i] = (1ll * ha[0][j][i - 1] * base % m1 + x) % m1;
			ha[1][j][i] = (1ll * ha[1][j][i - 1] * base % m2 + x) % m2;
		}

	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 30; j++)
		{
			int x = (b[i] >> j) & 1;
			hb[0][j] = (1ll * hb[0][j] * base % m1 + x) % m1;
			hb[1][j] = (1ll * hb[1][j] * base % m2 + x) % m2;
		}

	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 30; j++)
		{
			int x = ((~b[i]) >> j) & 1;
			hc[0][j] = (1ll * hc[0][j] * base % m1 + x) % m1;
			hc[1][j] = (1ll * hc[1][j] * base % m2 + x) % m2;
		}

	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 30; j++)
		{
			int t1 = ((ha[0][j][i + n - 1] - 1ll * ha[0][j][i - 1] * pw[0][n] % m1) % m1 + m1) % m1;
			int t2 = ((ha[1][j][i + n - 1] - 1ll * ha[1][j][i - 1] * pw[1][n] % m2) % m2 + m2) % m2;
			if(t1 == hb[0][j] && t2 == hb[1][j]) ans[j][i] = 0;
			else if(t1 == hc[0][j] && t2 == hc[1][j]) ans[j][i] = 1;
				else ans[j][i] = -1;
		}

	for(int i = 1; i <= n; i++)
	{
		bool flag = true;
		for(int j = 0; j < 30; j++)
			if(ans[j][i] == -1) { flag = false; break; }
		if(!flag) continue;
		int res = 0;
		for(int j = 0; j < 30; j++) res |= (ans[j][i] << j);
		printf("%d %d\n", i - 1, res);
	}
	return 0;
}
