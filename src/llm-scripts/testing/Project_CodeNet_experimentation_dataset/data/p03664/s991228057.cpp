#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define rint register int
#define gc() getchar()
inline int read(){int r=0,s=0,c=gc();for(;!isdigit(c);s=c,c=gc());for(;isdigit(c);(r*=10)+=c-48,c=gc());return s^45?r:-r;}
int f[16][32768], g[32768], w[16][16], n, E;
int main()
{
	n = read(), E = 1<<n; for(rint m = read(), a, b; m--; a = read()-1, b = read()-1, w[a][b] = w[b][a] = read()); for(rint i = 0; i < n; fill(f[i],f[i]+E,-INF), i++);
	for(rint S = 1, T, i, j; S < E; S&1 ? f[0][S] = g[S] : 0, S++) for(g[S] = g[T=S-(S&-S)], i = ilogb(S&-S), j = 0; j < n; j++) if(T&1<<j) g[S] += w[i][j];
	for(rint S = 1, T, i, j; S < E; S++) for(T = ~-S&S; T; --T&=S) for(i = 0; i < n-1; i++) if((S^T)&1<<i&&f[i][S^T]>=0)
		for(j = 1; j < n; T&1<<j&&w[i][j] ? f[j][S] = max(f[j][S],f[i][S^T]+g[T]+w[i][j]) : 0, j++); printf("%d\n",g[~-E]-f[~-n][~-E]); return 0;
}