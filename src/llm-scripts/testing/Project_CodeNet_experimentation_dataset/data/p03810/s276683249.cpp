#include<iostream>
#include<cstdio>
#include<algorithm>
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
int n,s,a[MAX];
bool calc(int p)
{
	int s=0,mn=1e9;
	for(int i=1;i<=n;++i)s+=a[i]&1,mn=min(mn,a[i]);
	if((n-s)&1)return p;
	if(s>1||mn==1)return p^1;
	for(int i=1;i<=n;++i)a[i]>>=1;
	int d=a[1];
	for(int i=1;i<=n;++i)d=__gcd(d,a[i]);
	for(int i=1;i<=n;++i)a[i]/=d;
	calc(p^1);
}
int main()
{
	n=read();for(int i=1;i<=n;++i)a[i]=read();
	puts(calc(1)?"First":"Second");
	return 0;
}
