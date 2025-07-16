#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long ll;
const int MAXN = 3e5 + 10;
const int Mod = 1e9 + 7;
int N;
char S[MAXN];
ll f[MAXN][2][2][3], s[MAXN];
ll ans;

int main() {
	register int i, j, k, l;
	scanf("%s", S + 1); N = strlen(S + 1);
	for(s[N + 1] = 1, i = N; i; --i) s[i] = s[i + 1] * (S[i] == '?' ? 2 : 1) % Mod;
	f[1][0][0][0] = 1;
	for(i = 1; i <= N; ++i) {
		if(S[i] != '1')
			for(j = 0; j < 2; ++j)
				for(k = 0; k < 2; ++k)
					for(l = 0; l < 3; ++l)
						(f[i + 1][j][k][(l & 1) + 1] += f[i][j][k][l]) %= Mod;
		if(S[i] != '0')
			for(j = 0; j < 2; ++j)
				for(k = 0; k < 2; ++k) {
					if(!j && !k) (f[i + 1][1][1][0] += f[i][j][k][0]) %= Mod;
					else if(j && k) (ans += 1ll * f[i][j][k][0] * s[i + 1]) %= Mod;
					else (f[i + 1][!j][k][0] += f[i][j][k][0]) %= Mod;
					(f[i + 1][j][k][0] += f[i][j][k][1]) %= Mod;
					(f[i + 1][!j][k][0] += f[i][j][k][2]) %= Mod;
				}
	}
	printf("%lld\n", (ans + f[N + 1][1][1][0]) % Mod);
	return 0;
}