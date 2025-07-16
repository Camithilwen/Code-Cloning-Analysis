#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 0x3f3f3f3f
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
	static char buf[20];
	int len=0;
	if(x<0)putchar('-'),x=-x;
	for(;x;x/=10)buf[len++]=x%10+'0';
	if(!len)putchar('0');
	else while(len)putchar(buf[--len]);
}
inline void writesp(ll x){write(x); putchar(' ');}
inline void writeln(ll x){write(x); putchar('\n');}
int a[maxn];
int n,m;
int main()
{
	n=read(); m=read();
	if(m==1){
		writeln(n);
		if(n==1){
			writeln(1);
			writeln(n);
		}
		else{
			writeln(2);
			writesp(n-1); writeln(1);
		}
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		a[i]=read();
		cnt+=(a[i]&1);
	}
	if(cnt>2){
		puts("Impossible"); return 0;
	}
	int flag=0;
	for(int i=1;i<=m;i++)
		if(a[i]&1){
			if(!flag)std::swap(a[1],a[i]),flag=1;
			else std::swap(a[m],a[i]);
		}
	for(int i=1;i<=m;i++)
		writesp(a[i]);
	putchar('\n');
	if(a[1]==1){
		writeln(m-1);
		for(int i=2;i<m;i++)
			writesp(a[i]);
		writeln(a[m]+1);
	}
	else{
		writeln(m);
		writesp(a[1]-1);
		for(int i=2;i<m;i++)
			writesp(a[i]);
		writeln(a[m]+1);
	}
	return 0;
}