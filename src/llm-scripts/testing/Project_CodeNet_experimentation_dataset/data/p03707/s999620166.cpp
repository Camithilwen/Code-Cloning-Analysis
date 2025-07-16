//Heaplax
//别让自己后悔
#include<bits/stdc++.h>
#define N 2005
#define LL long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
int n,m,q,v[N][N],xe[N][N],ye[N][N];
char s[N][N];
int main()
{
	re(n),re(m),re(q);
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			v[i][j]=s[i][j]-'0'+v[i-1][j];
			xe[i][j]=(s[i][j]=='1'&&s[i-1][j]=='1')+xe[i-1][j];
			ye[i][j]=(s[i][j]=='1'&&s[i][j-1]=='1')+ye[i][j-1];
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			v[i][j]+=v[i][j-1];
			xe[i][j]+=xe[i][j-1];
			ye[i][j]+=ye[i-1][j];
		}
	for(int a,b,c,d;q--;)
	{
		re(a),re(b),re(c),re(d);
		int ans=v[c][d]+v[a-1][b-1]-v[a-1][d]-v[c][b-1];
		ans-=xe[c][d]-xe[a][d]-xe[c][b-1]+xe[a][b-1];
		ans-=ye[c][d]-ye[a-1][d]-ye[c][b]+ye[a-1][b];
		printf("%d\n",ans);
	}
}
