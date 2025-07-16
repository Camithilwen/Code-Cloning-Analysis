#include <cstdio>

const int MAXN = 6000;

int f[4][2*MAXN + 5], N, M;

int main() {
	scanf("%d%d", &N, &M);
	
	f[0][MAXN] = 1;
	for(int i=1;i<=3*N;i++) {
		int lb = MAXN - (i - 1), ub = MAXN + (i - 1);
		for(int j=lb;j<=ub;j++) {
			for(int o=3;o>=1;o--)
				f[o][j] = f[o-1][j];
			f[0][j] = 0;
		}
		for(int j=lb;j<=ub;j++) {
			f[0][j+1] = (f[0][j+1] + f[1][j]) % M;
			int del = (i - 1);
			f[0][j-1] = (f[0][j-1] + 1LL*f[2][j]*del%M) % M;
			del = 1LL*(i - 1)*(i - 2)%M;
			f[0][j] = (f[0][j] + 1LL*f[3][j]*del%M) % M;
		}
	}
	int ans = 0;
	for(int i=MAXN;i<=MAXN+3*N;i++)
		ans = (ans + f[0][i]) % M;
	printf("%d\n", ans);
}