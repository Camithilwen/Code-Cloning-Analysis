#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
int n,k;
LL fac[4000000],inv_fac[4000000],dp[2001];
void check_mod(LL &a) { if (a>=MOD) a%=MOD; }
int ksm(LL a, int b)
{
	LL ret=1ll;
	while (b) {
		if (b&1) ret*=a;
		check_mod(ret);
		a*=a;
		check_mod(a);
		b>>=1;
	}
	return ret;
}
int main()
{
	LL lt;
	int t;
	scanf("%d%d",&n,&k);
	if (k==1) {
		printf("1\n");
		return 0;
	}
	fac[0]=1;
	t=n*k;
	for (int i = 1; i < t; ++i) {
		fac[i]=1ll*i*fac[i - 1];
		check_mod(fac[i]);
	}
	inv_fac[t-1]=ksm(fac[t-1],MOD-2);
	for (int i=t-2;i;--i) {
		inv_fac[i]=1ll*(i+1)*inv_fac[i+1];
		check_mod(inv_fac[i]);
	}
	inv_fac[0]=1;
	dp[0]=1;
	t=-2;
	for (int i=1;i<=n;++i) {
		t+=k-1;
		for (int j=0;j<=i;++j) {
			++t;
			lt=fac[t]*inv_fac[t-k+2];
			check_mod(lt);
			lt*=inv_fac[k-2];
			check_mod(lt);
			dp[j]*=lt;
			if (j) dp[j]+=dp[j - 1];
			check_mod(dp[j]);
		}
		t-=i+1;
	}
	printf("%lld\n",dp[n]*fac[n]%MOD);
	return 0;
}