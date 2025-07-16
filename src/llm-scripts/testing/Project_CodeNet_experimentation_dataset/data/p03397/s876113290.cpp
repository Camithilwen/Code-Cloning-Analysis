#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5, mod = 1e9 + 7;
int tr[8][2], f[maxn + 10][8], n;
char s[maxn + 10];
int main() {
	tr[0][0] = 1; tr[0][1] = 2;
	tr[1][0] = 3; tr[1][1] = 4;
	tr[2][0] = 5; tr[2][1] = 6;
	tr[3][0] = 1; tr[3][1] = 1;
	tr[4][0] = 1; tr[4][1] = 2;
	tr[5][0] = 7; tr[5][1] = 2;
	tr[6][0] = 6; tr[6][1] = 6;
	tr[7][0] = 5; tr[7][1] = 5;
	scanf("%s", s + 1);
	n = strlen(s + 1); f[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 8; ++j)
			for (int k = 0; k < 2; ++k)
				if (s[i] == '?' || (k + '0' == s[i]))
					(f[i][tr[j][k]] += f[i - 1][j]) %= mod;
	printf("%d", (f[n][2] + f[n][6]) % mod);
}
