#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
const int inf=1<<28;
char s[310];
int n,f[310][310],g[310][310],K;
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%d",&K);
	memset(f,-63,sizeof(f));
	for(int i=0;i<=K;i++) f[1][i]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
			for(int k=0;k<=K;k++) g[j][k]=f[j][k];
		for(int j=0;j<=K;j++) g[i][j]=1;
		for(int j=0;j<=K;j++)
		{
			int t1=0,t2=0;
			for(int k=i-1;k>=1;k--)
			{
				t1=max(t1,f[k+1][j]);
				if(j!=0) t2=max(t2,f[k+1][j-1]);
				if(s[k]==s[i]) g[k][j]=max(g[k][j],t1+2);
				else if(j!=0) g[k][j]=max(g[k][j],t2+2);
			}
		}
		for(int j=1;j<=i;j++) for(int k=1;k<=K;k++) g[j][k]=max(g[j][k],g[j][k-1]);
		for(int j=i-1;j>=1;j--) for(int k=0;k<=K;k++) g[j][k]=max(g[j][k],g[j+1][k]);
		for(int j=1;j<=i;j++) for(int k=0;k<=K;k++) f[j][k]=max(f[j][k],g[j][k]);
	}
	int ans=0;
	for(int i=1;i<=n;i++) for(int j=0;j<=K;j++) ans=max(ans,f[i][j]);
	printf("%d",ans);
}