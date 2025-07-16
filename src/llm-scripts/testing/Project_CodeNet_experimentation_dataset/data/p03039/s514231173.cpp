#include <iostream>

using ll = long long int;

constexpr ll mod = (1e9)+7;
constexpr int MAX = 2*1e5+10;

ll fac[MAX];

void init() {
	fac[0]=1;
	for(int i=1;i<MAX;++i)
		fac[i]=(fac[i-1]*i)%mod;
}

ll inv(ll x){
	ll n = mod-2;
	ll y = 1;
	ll z = 1;
	for(int i=0;i<40;++i){
		if(n&y) z = (z*x)%mod; 
		x=(x*x)%mod;
		y*=2;
	}
	return z;
}

ll func(ll x, ll y) {
	return ((x*(x+1)/2%mod)*y%mod + (y*(y+1)/2%mod)*x%mod)%mod;
}

ll g(ll x){return x*(x+1)/2%mod;}

int main(){
	init();
	int n, m, k;
	std::cin>>n>>m>>k;

	ll comb = (fac[n*m-2] * inv(fac[k-2]) % mod) * inv(fac[n*m-k]) % mod;

	ll sum = 0;

	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			sum+=func(i-1,j-1)+func(i-1,m-j)+func(n-i,j-1)+func(n-i,m-j)+g(i-1)+g(j-1)+g(m-j)+g(n-i);
			sum%=mod;
		}
	}
	

	std::cout<<((comb*sum)%mod)*inv(2)%mod<<std::endl;

	return 0;
}
