#include <bits/stdc++.h>
#define MOD 998244353LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

ll fact[400005];

ll mod_pow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1LL){
			res=res*x%MOD;
		}
		x=x*x%MOD;
		n>>=1LL;
	}
	return res;
}

ll extgcd(ll a,ll b,ll& x,ll& y){
	ll d=a;
	if(b!=0LL){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else{
		x=1;
		y=0;
	}
	return d;
}

ll mod_inverse(ll a,ll m){
	ll x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}

ll mod_fact(ll n,ll p,ll& e){
	e=0;
	if(n==0)return 1;
	ll res=mod_fact(n/p,p,e);
	e+=n/p;
	if(n/p%2!=0){
		return res*(p-fact[n%p])%p;
	}
	return res*fact[n%p]%p;
}

ll mod_comb(ll n,ll k,ll p){
	if(n<0 || k<0 || n<k)return 0;
	ll e1,e2,e3;
	ll a1=mod_fact(n,p,e1),a2=mod_fact(k,p,e2),a3=mod_fact(n-k,p,e3);
	if(e1>e2+e3)return 0;
	return a1*mod_inverse(a2*a3%p,p)%p;
}

int n,m,k;

int main(void){
	fact[0]=1;
	fact[1]=1;
	for(ll i=2;i<=400000;i++){
		fact[i]=fact[i-1]*i%MOD;
	}
	scanf("%d%d%d",&n,&m,&k);
	ll ans=mod_pow(m,n);
	ll co=1;
	for(int i=k+1;i<n;i++){
		ll ch=n-i-1;
		ll val=m;
		val=val*mod_pow(m-1,ch)%MOD;
		val=val*mod_comb(n-1,ch,MOD)%MOD;
		ans-=val;
		if(ans>=MOD){
			ans-=MOD;
		}
		if(ans<0){
			ans+=MOD;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
