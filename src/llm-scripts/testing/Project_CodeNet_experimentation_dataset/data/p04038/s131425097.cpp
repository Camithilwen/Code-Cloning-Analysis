#include <bits/stdc++.h>
#define DEBUG
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll read(){
	char c=getchar();bool flag=0;ll x=0;
	while(c<'0'||c>'9'){if(c=='-')flag=1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return flag?-x:x;
}
#define N 2010 
const ll p=1e9+7;
ll dp[N][N],fac[N*N],inv[N*N];
ll fpow(ll a,ll x){
	ll ans=1;
	while(x){
		if(x&1) ans=ans*a%p;
		a=a*a%p,x=x/2; 
	}
	return ans;
}
ll Cnt(ll n,ll m){
	return fac[m]*inv[n]%p*inv[m-n]%p;
}
int main(){
	ll n=read(),k=read();
	if(k==1){
		printf("1");
		return 0;
	}
	fac[0]=1;
	for(ll i=1;i<=n*k;i++) fac[i]=fac[i-1]*i%p;
	inv[n*k]=fpow(fac[n*k],p-2);
	for(ll i=n*k-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%p;
	for(ll i=1;i<=n;i++) dp[i][0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=i;j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1]*(n-(j-1))%p*Cnt(k-2,n*k-i-(j-1)*(k-1)-1)%p;
			dp[i][j]%=p;
		}
	}
	printf("%lld",dp[n][n]); 
}
