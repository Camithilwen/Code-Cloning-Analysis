#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

struct Combination {
	vector<long long> inv,finv,fac;
	Combination(int n, int kmax) : inv(kmax+1),finv(kmax+1),fac(kmax){
		if(kmax>=1){
			inv.at(1)=1;
			finv.at(1)=1;
			fac.at(0) = n;
		}
	for(int i=2; i<=kmax; i++) inv.at(i) = MOD - inv.at(MOD%i) * (MOD/i) %MOD;
	for(int i=2; i<=kmax; i++) finv.at(i) = finv.at(i-1) * inv.at(i) % MOD;
	for(int i=1; i<kmax; i++) fac.at(i) = fac.at(i-1) * (n-i) % MOD;
	}
	int comb(int k) {return (k ? fac.at(k-1) * finv.at(k) % MOD : 1 );}
};
ll exgcd(ll a,ll b,ll &x,ll &y){
	while(b){
		ll t{a/b};
		swap(a-=t*b, b);
		swap(x-=t*y, y);
	}
	return a;
}
ll exgcd(ll a,ll b){
	ll x{1},y{0};
	return exgcd(a,b,x,y);
}
ll inverse(ll a,ll mod){
	ll x{1},y{0};
	exgcd(a,mod,x,y);
	return (x%mod+mod)%mod;
}
int main(){
	int n,m,k; cin>>n>>m>>k;
	ll sum{};
	Combination c(n*m-2,k-2);
	for(ll i=0; i<n; i++){
		for(ll j=0; j<m; j++){
			sum += (i*(i+1)/2+(n-i)*(n-i-1)/2)*m;
			sum %= MOD;
			sum += (j*(j+1)/2+(m-j)*(m-j-1)/2)*n;
			sum %= MOD;
		}
	}
	sum *= c.comb(k-2);
	sum %= MOD; 
	sum *= inverse(2,MOD);
	sum %= MOD;
	cout << sum << endl;
	
}