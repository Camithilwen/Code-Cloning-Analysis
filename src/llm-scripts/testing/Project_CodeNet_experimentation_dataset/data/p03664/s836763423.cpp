#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define gc() getchar()
inline int read(){int r=0,s=0,c=gc();for(;!isdigit(c);s=c,c=gc());for(;isdigit(c);(r*=10)+=c-48,c=gc());return s^45?r:-r;}
int f[16][32768], g[32768], w[16][16], n, E;
int main()
{
	n = read(), E = 1<<n; for(rint m = read(), a, b; m--; a = read()-1, b = read()-1, w[a][b] = w[b][a] = read()); for(rint i = 0; i < n; memset(f[i++],-1,E<<2));
	for(rint S = 1, T, i, j; S < E; S++) for(g[S] = g[T=S-(S&-S)], i = ilogb(S&-S), j = 0; j < n; j++) if(T&1<<j) g[S] += w[i][j]; f[0][1] = 0;
	for(rint S = 1, U = ~-E^1, T, i, j; S < E; S++, U = ~-E^S) for(i = 0; i < n; i++) if(f[i][S]>=0)
		{for(j = 0; j < n; w[i][j]&&U&1<<j?f[j][S|1<<j]=max(f[j][S|1<<j],f[i][S]+w[i][j]):0, j++); for(T = U; T; f[i][S|T] = max(f[i][S|T],f[i][S]+g[T|1<<i]), --T&=U);} printf("%d\n",g[~-E]-f[~-n][~-E]); return 0;
}