#include <algorithm>
// #include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <bitset>
using namespace std;
typedef long long LL;
typedef double db;
const int oo=2139063143;
const int N=17;
const int P=1000000007;
const db eps=1e-7;
#define pritnf printf
//char buf[1<<22],*p1=buf,*p2=buf,obuf[1<<22],*O=obuf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template <typename T>
inline void sc (T &x)
{
    x=0; static int p; p=1; static char c; c=getchar();
    while (!isdigit(c)) { if (c=='-') p=-1; c=getchar(); }
    while ( isdigit(c)) { x=(x<<1)+(x<<3)+(c-48); c=getchar(); }
    x*=p;
}
template <typename T>
inline void print (T x)
{
    if (x< 0) putchar('-'),x=-x;
    if (x>=10) print(x/10);
    putchar(x%10+'0');
}
template <typename T>
inline void pr (T x) { print(x),putchar('\n'); }
template <typename T1,typename T2>
void chkmax (T1 &A,T2 B) { A=A>=B?A:B; }
template <typename T1,typename T2>
void chkmin (T1 &A,T2 B) { A=A<=B?A:B; }
int n,m,e[N][N],e0=0,g[1<<N|1],f[1<<N|1][N];

int main ()
{
    // freopen (".in","r",stdin);
    // freopen (".out","w",stdout);
	sc(n),sc(m);
	for (int i=1; i<=m; i++)
	{
		int x,y; sc(x),sc(y),sc(e[x][y]),e[y][x]=e[x][y];
		e0+=e[x][y];
	}
	int S=(1<<n)-1;
	for (int s=1; s<=S; s++)
		for (int i=1; i<=n; i++) if (s>>(i-1)&1)
			for (int j=i; j<=n; j++) if (s>>(j-1)&1)
				g[s]+=e[i][j];
	for (int s=0; s<=S; s++)
		for (int i=0; i<=n; i++)
			f[s][i]=-2e9;
	f[1][1]=0;
	for (int s=1; s< S; s++)
		for (int u=1; u<=n; u++) if (s>>(u-1)&1)
		{
			for (int v=1; v<=n; v++) if (!(s>>(v-1)&1)&&e[u][v])
				chkmax (f[s|(1<<(v-1))][v],f[s][u]+e[u][v]);
			int ss=S^s;
			for (int t=ss; t; t=(t-1)&ss)
				chkmax (f[s|t][u],f[s][u]+g[t|(1<<(u-1))]);
		}
	pr(e0-f[S][n]);

    return 0;
}
