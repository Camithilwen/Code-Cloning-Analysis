//Badwaper gg
#include<bits/stdc++.h>
#define inf 1e9
#define eps 1e-6
#define mp make_pair
#define pb push_back
#define re register ll
#define fr first
#define sd second
#define FOR(i,a,b) for(re i=a;i<=b;i++)
#define REP(i,a,b) for(re i=a;i>=b;i--)
#define lowbit(x) (x&(-x))
#define Z(x) (x>=mod?x-mod:x)
#define N 41
#define M 200010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=getchar();
	ll s=0,w=1;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
const int mod=1e9+7;
int f[N][M],to[M][N];
int n,x,y,z;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),x=read(),y=read(),z=read();y+=x;z+=y;
	FOR(S,1,1<<z)FOR(i,1,10)
	{
		to[S][i]=1;
		FOR(k,0,z-i)if((S>>k)&1)if(!(k<x&&k+i>x)&&!(k<y&&k+i>y))to[S][i]|=(1<<(i+k));
		if((S==(1<<z))||(to[S][i]>=(1<<z)))to[S][i]=1<<z;
	}
	f[0][1]=1;
	FOR(i,0,n-1)FOR(S,1,(1<<z))FOR(j,1,10)f[i+1][to[S][j]]=Z(f[i+1][to[S][j]]+f[i][S]);
	printf("%d\n",f[n][1<<z]);
	return 0;
}
