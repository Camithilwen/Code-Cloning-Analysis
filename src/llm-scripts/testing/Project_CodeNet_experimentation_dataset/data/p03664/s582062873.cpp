#include<bits/stdc++.h>
#define Rint register int
using namespace std;
const int N = 15;
int n, m, lim, wsum, edge[N][N], sum[1 << N], dp[N][1 << N];
inline int cost(int S, int T){return sum[S | T] - sum[S] - sum[T];}
inline bool chkmax(int &a, int b){return (a < b) ? (a = b,1) : 0;}
int main(){
	scanf("%d%d", &n, &m); lim = 1 << n;
	for(Rint i = 1;i <= m;i ++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c); -- a; -- b;
		edge[a][b] = edge[b][a] = c; wsum += c;
	}
	for(Rint S = 1;S < lim;S ++)
		for(Rint i = 0;i < n;i ++) if((S >> i) & 1)
			for(Rint j = i + 1;j < n;j ++) if((S >> j) & 1)
				sum[S] += edge[i][j];
	memset(dp, 0x80, sizeof dp);
	dp[0][1] = 0;
	for(Rint S = 1;S < lim;S += 2)
		for(Rint t = 0;t < n;t ++) if((S >> t) & 1){
			for(Rint u = 0;u < n;u ++) if(!((S >> u) & 1) && edge[t][u])
				chkmax(dp[u][S | (1 << u)], dp[t][S] + edge[t][u]);
			int SS = (lim - 1) ^ S;
			for(Rint T = SS;T;T = (T - 1) & SS)
				chkmax(dp[t][S | T], dp[t][S] + sum[T | (1 << t)]);
		}
	printf("%d\n", wsum - dp[n - 1][lim - 1]);
}