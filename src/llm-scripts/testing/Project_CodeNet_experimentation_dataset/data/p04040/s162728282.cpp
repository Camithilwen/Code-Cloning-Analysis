#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pcc pair<char,char>
#define vi vector <int>
#define vl vector <ll>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d",x)
#define plld(x) printf("%lld",x)
#define pds(x) printf("%d ",x)
#define pllds(x) printf("%lld ",x)
#define pdn(x) printf("%d\n",x)
#define plldn(x) printf("%lld\n",x)
#define INF 2e9
#define INFLL 4e18
using namespace std;
ll powmod(ll base,ll exponent,ll mod){ // with mod < 1e9
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent/=2;
	}
	return ans;
}
ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
const int upperlimit = 2e5+100;
const int mod = 1e9+7;
ll fact[upperlimit];
ll invfact[upperlimit];
ll ways(int x1,int y1,int x2,int y2){
	ll ans=fact[abs(x2-x1)+abs(y2-y1)];
	ans*=invfact[abs(x2-x1)];ans%=mod;
	ans*=invfact[abs(y2-y1)];ans%=mod;
	return ans;
}
int main() {
	fact[0]=1;invfact[0]=1;
	for(int i = 1; i < upperlimit; i++){
		fact[i]=fact[i-1];fact[i]*=i;fact[i]%=mod;
		invfact[i]=powmod(fact[i],mod-2,mod);
	}
	int h,w,r,c;
	sd(h);sd(w);sd(r);sd(c);
	ll ans=ways(0,0,h-1,w-1);
	for(int i = 0; i < c; i++){
		ll calc=ways(0,0,h-r-1,i);
		calc*=ways(h-r,i,h-1,w-1);calc%=mod;
		ans-=calc;
		if(ans<0) ans+=mod;
	}
	plld(ans);
	return 0;
}