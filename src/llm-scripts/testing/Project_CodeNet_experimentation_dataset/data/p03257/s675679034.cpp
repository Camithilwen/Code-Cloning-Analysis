//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define inf 20021225
using namespace std;
int read()
{
	int s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')	t=-1; ch=getchar();}
	while(ch>='0' && ch<='9')	s=s*10+ch-'0',ch=getchar();
	return s*t;
}
bool np[10010]; int pri[5010],cnt;
void getprime(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!np[i])	pri[++cnt]=i;
		for(int j=1;j<=cnt&&pri[j]*i<=n;j++)
		{
			np[pri[j]*i]=1;
			if(i%pri[j]==0)	break;
		}
	}
}
#define N 510
ll a[N][N];
ll lcm(ll x,ll y){if(!x||!y)return x+y;return x/__gcd(x,y)*y;}
int main()
{
	getprime(1e4); int n=read();
	if(n==2)	return puts("4 7\n23 10"),0;
	for(int i=1;i<=n;i++)	for(int j=1;j<=n;j++)
		if(!((i+j)&1))	a[i][j]=1ll*pri[i+j>>1]*pri[n+(i-j>>1)+(n+1>>1)];
	for(int i=1;i<=n;i++)	for(int j=1;j<=n;j++)
		if((i+j)&1)	a[i][j]=lcm(lcm(a[i-1][j],a[i+1][j]),lcm(a[i][j-1],a[i][j+1]))+1;
	for(int i=1;i<=n;i++,puts(""))	for(int j=1;j<=n;j++)
		printf("%lld ",a[i][j]);
	return 0;
}