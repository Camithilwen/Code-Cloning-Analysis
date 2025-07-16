#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#define re register
const int MAXN=2e5+10;
int n,K,s[MAXN],a[MAXN],timee;
char fin[10010],*p1=fin,*p2=fin;
char getc()
{
	return p1==p2&&(p2=(p1=fin)+fread(fin,1,10000,stdin),p1==p2)?EOF:*p1++;
}
int read()
{
	re int x=0;
	re char ch=0;
	while(ch<'0'||ch>'9') ch=getc();
	while('0'<=ch&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getc();
	return x;
}
inline void insert(int x,int w)
{
	for(;x<=n;x+=x&-x) s[x]+=w;
}
inline int query(int x)
{
	re int res=0;
	for(;x;x-=x&-x) res+=s[x];
	return res;
}
int main()
{
	//freopen("t2.out","w",stdout);
	n=read();
	K=read();
	for(re int i=1;i<=n;i++) a[i]=read();
	while(K--)
	{
		re bool flag=1;
		memset(s,0,(n+5)*sizeof(int));
		for(re int i=1;i<=n;i++) insert(std::max(1,i-a[i]),1),insert(std::min(n,i+a[i])+1,-1);
		for(re int i=1;i<=n;i++) a[i]=query(i),flag&=(a[i]==n);
		if(flag) break;
	}
	for(re int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}
/*
5 1
1 0 0 1 0
*/