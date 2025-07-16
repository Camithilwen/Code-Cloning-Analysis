#include<cstdio>
#define RI int
#define CI const int&
using namespace std;
const int N=6005;
int n,mod,f[N][N<<1],ans;
inline void inc(int& x,CI y)
{
	if ((x+=y)>=mod) x-=mod;
}
int main()
{
	RI i,j,k,t; scanf("%d%d",&n,&mod); n*=3; f[0][n]=1;
	for (i=0;i<n;++i) for (j=-i;j<=i;++j) if (f[i][n+j])
	inc(f[i+1][n+j-1],f[i][n+j]),
	inc(f[i+2][n+j+1],1LL*f[i][n+j]*(i+1)%mod),
	inc(f[i+3][n+j],1LL*f[i][n+j]*(i+2)%mod*(i+1)%mod);
	for (i=-n;i<=0;++i) inc(ans,f[n][n+i]); return printf("%d",ans),0;
}