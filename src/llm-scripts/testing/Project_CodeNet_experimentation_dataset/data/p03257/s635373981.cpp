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
int p[10010],mn[10010];
ll a[510][510];
int n,tot;
void euler(int n)
{
	tot=0;
	for(int i=2;i<=n;i++){
		if(!mn[i])p[++tot]=i,mn[i]=tot;
		for(int j=1;j<=mn[i]&&i*p[j]<=n;j++)
			mn[i*p[j]]=j;
	}
}
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main()
{
	n=read();
	if(n==2){
		printf("4 7\n23 10\n");
		return 0;
	}
	euler(10000);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((i+j)&1){
				int x=(i-j+n+1)/2,y=(i+j+1)/2;
				a[i][j]=p[x]*p[n+y];
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!((i+j)&1)){
				ll cur=1;
				if(i>1)cur=cur/gcd(cur,a[i-1][j])*a[i-1][j];
				if(j>1)cur=cur/gcd(cur,a[i][j-1])*a[i][j-1];
				if(i<n)cur=cur/gcd(cur,a[i+1][j])*a[i+1][j];
				if(j<n)cur=cur/gcd(cur,a[i][j+1])*a[i][j+1];
				a[i][j]=cur+1;
			}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			writesp(a[i][j]);
		putchar('\n');
	}
	return 0;
}