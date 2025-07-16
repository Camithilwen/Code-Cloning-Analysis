#include<bits/stdc++.h>
using namespace std;

const int MAXN = 110;
int n, m, ex, ey;
int dp[2][MAXN][MAXN][MAXN];
int C[MAXN][MAXN], R[MAXN][MAXN];
char s[MAXN][MAXN];

inline int QR(int p, int l, int r) {
	if(l >= r) return 0;
	return R[p][r]-R[p][l];
}

inline int QC(int p, int l, int r) {
	if(l >= r) return 0;
	return C[p][r]-C[p][l];
}

inline void chkmax(int &cur, int val) {
	if(cur < val) cur = val;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%s", s[i]+1);
	for(int i = 1; i <= n; i++) {
		C[i][0] = 0;
		for(int j = 1; j <= m; j++) {
			C[i][j] = C[i][j-1]+(s[i][j]=='o');
			if(s[i][j] == 'E') ex = i, ey = j;
		}
	}
	for(int i = 1; i <= m; i++) {
		R[i][0] = 0;
		for(int j = 1; j <= n; j++) 
			R[i][j] = R[i][j-1]+(s[j][i]=='o');
	}

	for(int l = 0; l < ex; l++) {
		for(int d = 0; d < ey; d++) 
			for(int r = 0; r <= n-ex; r++) 
				for(int u = 0; u <= m-ey; u++) {
					int val = dp[l&1][d][r][u];
					if(l != ex-1) {
						if(ex-l-1 <= r) chkmax(dp[l&1^1][d][r][u], val);
						else {
							int lef = max(ey-d, u+1), rig = min(ey+u, m-d);
							chkmax(dp[l&1^1][d][r][u], val+QC(ex-l-1, lef-1, rig));
						}
					}
					if(d != ey-1) {
						if(ey-d-1 <= u) chkmax(dp[l&1][d+1][r][u], val);
						else {
							int lef = max(ex-l, r+1), rig = min(ex+r, n-l);
							//if(d == 0 && r == 1 && u == 1) printf("!\n");
							chkmax(dp[l&1][d+1][r][u], val+QR(ey-d-1, lef-1, rig));
						}
					}
					if(r != n-ex) {
						if(ex+r+1 > n-l) chkmax(dp[l&1][d][r+1][u], val);
						else {
							int lef = max(ey-d, u+1), rig = min(ey+u, m-d);
							//if(d == 1 && r == 0 && u == 1) printf("!!\n");
							chkmax(dp[l&1][d][r+1][u], val+QC(ex+r+1, lef-1, rig));
						}
					}
					if(u != m-ey) {
						if(ey+u+1 > m-d) chkmax(dp[l&1][d][r][u+1], val);
						else {
							int lef = max(ex-l, r+1), rig = min(ex+r, n-l);
							//if(d == 1 && r == 1 && u == 0) printf("!!!\n");
							chkmax(dp[l&1][d][r][u+1], val+QR(ey+u+1, lef-1, rig));
						}
					}
				}
		if(l == ex-1) break;
		for(int d = 0; d < ey; d++) 
			for(int r = 0; r <= n-ex; r++) 
				for(int u = 0; u <= m-ey; u++) 
					dp[l&1][d][r][u] = 0;
	}
	printf("%d\n", dp[(ex-1)&1][ey-1][n-ex][m-ey]);
	return 0;
}
