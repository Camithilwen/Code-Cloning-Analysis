#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define ll long long
#define maxn 200010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
inline void write(ll x)
{
	static int buf[20],len; len=0;
	if(x<0)x=-x,putchar('-');
	for(;x;x/=10)buf[len++]=x%10;
	if(!len)putchar('0');
	else while(len)putchar(buf[--len]+'0');
}
inline void writeln(ll x){write(x); putchar('\n');}
inline void writesp(ll x){write(x); putchar(' ');}
int a[maxn],d[maxn];
int cur[maxn],ans[maxn];
int n,m;
ll k;
int mul(int* a,int* b,int n)
{
	static int t[maxn];
	for(int i=1;i<=n;i++)
		t[i]=a[b[i]];
	for(int i=1;i<=n;i++)
		a[i]=t[i];
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	int S=a[1];
	for(int i=1;i<n;i++)
		d[i]=a[i+1]-a[i];
	m=read(); k=read();
	for(int i=1;i<n;i++)
		cur[i]=ans[i]=i;
	for(int i=1;i<=m;i++){
		int x=read();
		std::swap(cur[x-1],cur[x]);
	}
	for(;k;k>>=1,mul(cur,cur,n-1))
		if(k&1)mul(ans,cur,n-1);
	ll X=a[1];
	for(int i=1;i<=n;i++){
		writeln(X);
		X+=d[ans[i]];
	}
	return 0;
}