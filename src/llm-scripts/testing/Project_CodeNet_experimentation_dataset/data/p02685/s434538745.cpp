#include <cstdio>
#include <algorithm>
#define mod 998244353
#define maxn 200010
#define LL long long
using namespace std;
LL fact[maxn],inv[maxn],ans,t[maxn],p;
int n,m,k,nm;
LL quick_pow(LL a,LL b){//a^b
	LL ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans%mod;
}
void init(){
	int i;
	scanf("%d%d%d",&n,&m,&k);
	nm=n,nm=max(nm,m),fact[0]=1;
	for(i=1;i<=nm;i++)fact[i]=fact[i-1]*i%mod;//fact[i]代表i!
	inv[nm]=quick_pow(fact[nm],mod-2);
	for(i=nm-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;//inv[i]代表i!的乘法逆元
}
LL C(LL a,LL b){//组合数计算
	return fact[a]*inv[a-b]%mod*inv[b]%mod;
}
int main(){
	int i;
	init();
	ans=0,p=quick_pow(m-1,n-k-1);
	for(i=n-k;i<=n;i++){
		ans=(ans+m*p%mod*C(n-1,i-1)%mod)%mod;//C(n-1,i-1)隔板法
		p=p*(m-1)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}