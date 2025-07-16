#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int n,m,h[2010][2010],l[2010][2010],r[2010][2010],ans;
char s[2010][2010];
int main()
{
	scanf("%d %d",&n,&m);getchar();
	ans=max(n,m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(j==1||i==1) h[i][j]=1;
			else h[i][j]=((s[i][j]==s[i][j-1])==(s[i-1][j]==s[i-1][j-1]))?h[i-1][j]:i;
		}
	for(int i=1;i<=n;i++)
	{
		if(i==1) for(int j=1;j<=m;j++) l[i][j]=1,r[i][j]=m;
		else
		{
			l[i][1]=1;for(int j=2  ;j<=m;j++) l[i][j]=(s[i][j]==s[i-1][j])==(s[i][j-1]==s[i-1][j-1])?l[i][j-1]:j;
			r[i][m]=m;for(int j=m-1;j>=1;j--) r[i][j]=(s[i][j]==s[i-1][j])==(s[i][j+1]==s[i-1][j+1])?r[i][j+1]:j;
		}
		for(int j=1;j<=m;j++)
		{
			if(h[i][j]==i) l[i][j]=1,r[i][j]=m;
			else l[i][j]=max(l[i][j],l[i-1][j]),r[i][j]=min(r[i][j],r[i-1][j]);
			int N=i-h[i][j]+1,M=r[i][j]-l[i][j]+1;
			ans=max(ans,N*M);
		}
	}
	printf("%d",ans);
}