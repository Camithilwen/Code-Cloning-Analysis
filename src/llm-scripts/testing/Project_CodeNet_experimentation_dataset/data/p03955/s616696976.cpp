#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 100100
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
int n,a[4][MAX],b[4],c[MAX],t[2];
void WA(){puts("No");exit(0);}
int main()
{
	n=read();
	for(int i=1;i<=3;++i)
		for(int j=1;j<=n;++j)
		{
			int p=read();
			int x=(p-1)%3+1,y=(p+2)/3;
			if((i==2&&x!=2)||(i!=2&&x==2))WA();
			if((y&1)^(j&1))WA();
			a[i][j]=p;
		}
	for(int j=1;j<=n;++j)
	{
		for(int i=1;i<=3;++i)b[i]=a[i][j];
		int y=(b[1]+2)/3,x=3*y-3;
		for(int i=1;i<=3;++i)if(b[i]!=x+i&&b[i]!=x+4-i)WA();
		t[j&1]^=(a[1][j]>a[2][j]);c[j]=y;
	}
	for(int i=1;i<=n;++i)
	{
		while(c[i]!=i)
		{
			t[i&1^1]^=1;
			swap(c[i],c[c[i]]);
		}
	}
	if(t[0]||t[1])WA();
	puts("Yes");return 0;
}
