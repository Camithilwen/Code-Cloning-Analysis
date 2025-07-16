#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define MAX 100100
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
int a[MAX],n,m,S[MAX],top;
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		a[i]=read();
		if(a[i]&1)S[++top]=i;
	}
	if(top>2){puts("Impossible");return 0;}
	if(top)swap(a[1],a[S[1]]);
	if(top>1)swap(a[m],a[S[2]]);
	if(m==1)
	{
		if(a[1]==1)printf("1\n1\n1\n");
		else printf("%d\n2\n%d 1\n",a[1],a[1]-1);
		return 0;
	}
	for(int i=1;i<=m;++i)printf("%d ",a[i]);puts("");
	printf("%d\n",m-(a[m]==1));
	printf("%d ",a[1]+1);
	for(int i=2;i<m;++i)printf("%d ",a[i]);
	if(a[m]>1)printf("%d ",a[m]-1);
	puts("");return 0;
}
