#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long MAXN=100005;
long long n;
long long a[MAXN];
long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
void pr(long long x)
{
	if(x==1)
		printf("First\n");
	else
		printf("Second\n");
	exit(0);
}
void dfs(long long x)
{
	long long s=0;
	for(long long i=1;i<=n;i++)
		s+=a[i]-1;
	if(s&1)
		pr(x^1);
	long long cnt=0;
	for(long long i=1;i<=n;i++)
		if(a[i]&1)
			cnt++;
	for(long long i=1;i<=n;i++)
		if(a[i]==1)
			cnt=903;
	if(cnt!=1)
		pr(x);
	for(long long i=1;i<=n;i++)
		if(a[i]&1)
		{
			a[i]--;
			break;
		}
	long long G=0;
	for(long long i=1;i<=n;i++)
		G=gcd(G,a[i]);
	for(long long i=1;i<=n;i++)
		a[i]/=G;
	dfs(x^1);
}
int main()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	dfs(0);
}