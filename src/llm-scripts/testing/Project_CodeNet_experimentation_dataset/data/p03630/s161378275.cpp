#include<iostream>
#include<cstdio>
using namespace std;
int a[2010][2010];char s[2010];
int h[2010][2010],r[2010][2010],l[2010][2010];
int top=0,ans=0,st[2010];
int main()
{
	int n,m;scanf("%d%d",&n,&m);ans=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for(int j=1;j<=m;j++)a[i][j]=(s[j-1]=='#');
	}
	for(int i=n;i>=1;i--)
	for(int j=m;j>=2;j--)a[i][j]^=a[i][j-1];
	for(int j=2;j<=m;j++)h[1][j]=1;
	for(int i=2;i<=n;i++)
	for(int j=2;j<=m;j++)if(a[i][j]==a[i-1][j])h[i][j]=h[i-1][j]+1;else h[i][j]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			while(top&&h[i][st[top]]>h[i][j]){r[i][st[top]]=j-1;top--;}
			st[++top]=j;
		}
		while(top)r[i][st[top--]]=m;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			while(top&&h[i][st[top]]>=h[i][j]){top--;}
			if(top==0)l[i][j]=2;else l[i][j]=st[top]+1;st[++top]=j;
		}
		top=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)ans=max(ans,(r[i][j]-l[i][j]+2)*h[i][j]);
	}
	printf("%d",ans);return 0;
}