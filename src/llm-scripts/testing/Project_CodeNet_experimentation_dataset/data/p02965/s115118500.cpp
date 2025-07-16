#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<iostream>
#define llong long long
using namespace std;

inline int read()
{
	int x=0; bool f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=0;
	for(; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^'0');
	if(f) return x;
	return -x;
}

const int N = 2e6;
const int P = 998244353;
llong fact[N+3],finv[N+3];

llong quickpow(llong x,llong y)
{
	llong cur = x,ret = 1ll;
	for(int i=0; y; i++)
	{
		if(y&(1ll<<i)) {y-=(1ll<<i); ret = ret*cur%P;}
		cur = cur*cur%P;
	}
	return ret;
}
llong comb(llong x,llong y) {return x<0||y<0||x<y ? 0ll : fact[x]*finv[y]%P*finv[x-y]%P;}

llong calc(llong n,llong m,llong k)
{
	llong ret = 0ll;
	for(int i=0; i<=k; i++)
	{
		if((m-i)&1) continue;
		llong tmp = comb(n,i)*comb(((m-i)>>1)+n-1,n-1)%P;
		ret = (ret+tmp)%P;
	}
//	printf("calc %lld %lld %lld=%lld\n",n,m,k,ret);
	return ret;
}

int n,m;

int main()
{
	fact[0] = 1ll; for(int i=1; i<=N; i++) fact[i] = fact[i-1]*i%P;
	finv[N] = quickpow(fact[N],P-2); for(int i=N-1; i>=0; i--) finv[i] = finv[i+1]*(i+1)%P;
	scanf("%d%d",&n,&m);
	llong ans = calc(n,3*m,m);
	ans = (ans-n*(calc(n,m,m)-calc(n-1,m,m)+P)%P+P)%P;
	printf("%lld\n",ans);
	return 0;
}