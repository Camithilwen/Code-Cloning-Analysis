#include<cstdio>
#include<iostream>
#include<cstring>
#define RG register
#define si short int
using namespace std;
const int N=101;
si n,m,x,y,ans,dp[N][N][N][N],sum[N][N];
char g[N][N];
template<typename I> inline void read(I &ot){
	I ch=getchar(), x=0, f=1;
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();	}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();	}
	ot=x*f;}
template<typename I, typename... U> inline void read(I &x,U&... y){read(x); read(y...);}
template<typename I>inline I mx(const I&a,const I&b){return a>b ? a : b;}
template<typename I>inline I mi(const I&a,const I&b){return a<b ? a : b;}
template<typename I>inline void swp(I&a,I&b){I t=a; a=b; b=t;}
inline void cmx(si &a,si b){if(b>a) a=b;}
inline si s(int a,int b,int c,int d){
	if(a>c) swp(a,c); if(b>d) swp(b,d);
	return sum[c][d]-sum[c][b-1]-sum[a-1][d]+sum[a-1][b-1];
}
int main()
{
//	freopen("Salvage Robots.in","r",stdin);
	read(n,m);
	for(RG int i=1;i<=n;i++) 
	{
		scanf("%s",g[i]+1);
		for(RG int j=1;j<=m;j++)
		{
			if(g[i][j]=='o') sum[i][j]=1;
			else if(g[i][j]=='E') x=i, y=j;
			sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}
	for(int i=x;i;i--)
	 for(int j=y;j;j--)
	  for(int k=x;k<=n;k++)
	   for(int l=y;l<=m;l++)
	   {
			ans=mx(ans,dp[i][j][k][l]);
			int li=l-y+1, ri=m-y+j, us=k-x+1, ds=n-x+i;
			if(i-1>=us) cmx(dp[i-1][j][k][l],dp[i][j][k][l]+s(i-1,mx(li,j),i-1,mi(ri,l)));
			if(j-1>=li) cmx(dp[i][j-1][k][l],dp[i][j][k][l]+s(mx(i,us),j-1,mi(k,ds),j-1));
			if(k+1<=ds) cmx(dp[i][j][k+1][l],dp[i][j][k][l]+s(k+1,mx(li,j),k+1,mi(ri,l)));
			if(l+1<=ri) cmx(dp[i][j][k][l+1],dp[i][j][k][l]+s(mx(i,us),l+1,mi(k,ds),l+1));
	   }
	cout<<ans<<endl;
	return 0;
}