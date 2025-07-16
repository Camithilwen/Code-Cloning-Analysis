#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#define N 2005
#define MOD 998244353
using namespace std;
int k,n;
int a[N];
int d[N][N];
int dy[N][N];
int main() {
	scanf("%d%d", &k,&n);
	int i, j;
	for (i = 1; i <= k; i++) d[1][i] = 1;
	for (i = 2; i <= n; i++) {
		int sum = 0;
		for (j = 1; j <= k; j++) {
			sum += d[i - 1][j]; sum %= MOD;
			d[i][j] = sum;
		}
	}
	dy[0][0] = 1;
	dy[1][0] = k;
	for (i = 1; i <= k; i++) {
		dy[0][i] = 1; dy[1][i] = k;
	}
	for (i = 2; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			dy[i][0] += d[i][j]; dy[i][0] %= MOD;
		}
		for (int ban = 1; ban <= k; ban++) {
			dy[i][ban] = dy[i][ban - 1] - dy[i - 2][ban - 1];
			if (dy[i][ban] < 0) dy[i][ban] += MOD;
		}
	}
	for (i = 2; i <= k+1 ; i++) {
		printf("%d\n", dy[n][i / 2]);
	}
	for (i = k ; i >= 2; i--) printf("%d\n", dy[n][i / 2]);
	return 0;
}