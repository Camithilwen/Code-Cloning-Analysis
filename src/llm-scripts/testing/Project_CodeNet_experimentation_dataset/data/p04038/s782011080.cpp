#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 3000;
const int MAXM = MAXN*MAXN;
const int MOD = int(1E9) + 7;

int pow_mod(int b, int p) {
	int ret = 1;
	for(int i=p;i;i>>=1,b=1LL*b*b%MOD)
		if( i & 1 ) ret = 1LL*ret*b%MOD;
	return ret;
}

int fct[MAXM + 5], ifct[MAXM + 5];
int comb(int n, int m) {
	return 1LL*fct[n]*ifct[m]%MOD*ifct[n-m]%MOD;
}
void init() {
	fct[0] = 1;
	for(int i=1;i<=MAXM;i++)
		fct[i] = 1LL*fct[i-1]*i%MOD;
	ifct[MAXM] = pow_mod(fct[MAXM], MOD - 2);
	for(int i=MAXM-1;i>=0;i--)
		ifct[i] = 1LL*ifct[i+1]*(i+1)%MOD;
}

int f[MAXN + 5][MAXN + 5];

int main() {
	init();
	int N, K; scanf("%d%d", &N, &K);
	if( K == 1 ) {
		puts("1");
		return 0;
	}
	for(int i=1;i<=N;i++) f[1][i] = 1;
	for(int i=2;i<=N;i++) {
		for(int j=1;j<=i;j++) {
			int m = (K - 1)*(i - 1) + j, n = K - 2;
			f[i][j] = 1LL*f[i-1][j]*comb(n+m-1, n)%MOD;
		}
		for(int j=1;j<=N;j++)
			f[i][j] = (f[i][j] + f[i][j-1]) % MOD;
	}
	printf("%lld\n", 1LL*f[N][N]*fct[N]%MOD);
}