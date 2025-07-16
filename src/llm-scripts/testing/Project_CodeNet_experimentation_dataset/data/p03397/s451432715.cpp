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
int To[8][2] = {{3, 1}, {5, 2}, {2, 2}, {4, 7}, {3, 3}, {6, 1}, {5, 5}, {3, 1}};
ll f[MAXN][8];

int main() {
	register int i, j;
	scanf("%s", S + 1); N = strlen(S + 1);
	f[1][0] = 1;
	for(i = 1; i <= N; ++i)
		for(j = 0; j < 8; ++j) {
			if(S[i] != '0') (f[i + 1][To[j][1]] += f[i][j]) %= Mod;
			if(S[i] != '1') (f[i + 1][To[j][0]] += f[i][j]) %= Mod;
		}
	printf("%lld\n", (f[N + 1][1] + f[N + 1][2]) % Mod);
	return 0;
}