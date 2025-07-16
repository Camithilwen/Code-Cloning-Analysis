#include <bits/stdc++.h>
#define maxn 105

using namespace std;

int n, m;
char s[maxn][maxn];
short f[maxn][maxn][maxn][maxn];
int x, y;
int sum1[maxn][maxn], sum2[maxn][maxn];

inline void Max(short &x, short y){
	x = max(x, y);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(s[i][j] == 'E') x = i, y = j;
			sum1[i][j] = sum1[i][j - 1] + (s[i][j] == 'o');
			sum2[i][j] = sum2[i - 1][j] + (s[i][j] == 'o');
		}
	}
	int U = x - 1, D = n - x, L = y - 1, R = m - y;
	for(int i = 0;i <= U;i++){
		for(int j = 0;j <= D;j++){
			for(int k = 0;k <= L;k++){
				for(int o = 0;o <= R;o++){
					
					int l = max(o + 1, y - k), r = min(m - k, y + o);
					if(i < U) Max(f[i + 1][j][k][o], f[i][j][k][o] + (l <= r && x - i - 1 > j ? sum1[x - i - 1][r] - sum1[x - i - 1][l - 1] : 0));
					if(j < D) Max(f[i][j + 1][k][o], f[i][j][k][o] + (l <= r && x + j + 1 < n + 1 - i ? sum1[x + j + 1][r] - sum1[x + j + 1][l - 1] : 0));
					int u = max(j + 1, x - i), d = min(n - i, x + j);
					if(k < L) Max(f[i][j][k + 1][o], f[i][j][k][o] + (u <= d && y - k - 1 > o ? sum2[d][y - k - 1] - sum2[u - 1][y - k - 1] : 0));
					if(o < R) Max(f[i][j][k][o + 1], f[i][j][k][o] + (u <= d && y + o + 1 < m + 1 - k ? sum2[d][y + o + 1] - sum2[u - 1][y + o + 1] : 0));//, printf("%d %d %d %d %d %d %d %d %d %d--\n", i, j, k, o, l, r, u, d, y + o + 1, m + 1 - k);
					//printf("%d %d %d %d %d %d %d %d--\n", i, j, k, o, u, d, y - k - 1, f[i][j][k][o]);
				}
			}
		}
	}
	printf("%d", f[U][D][L][R]);
}