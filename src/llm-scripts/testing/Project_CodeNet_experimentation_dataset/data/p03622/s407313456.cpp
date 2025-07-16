#include<bits/stdc++.h>
#define MAXN 1000005
#define P int(998244353)
using namespace std;
typedef long long ll;

int N,M;
ll fac[MAXN], ifac[MAXN];

ll qpow(ll x, int n){
	ll res = 1;
	while(n){
		if(n&1) res = res * x % P;
		x = x * x % P;
		n /= 2;
	}
	return res;
}

void init(){
	fac[0] = ifac[0] = 1;
	for(int i=1;i<=N+M;i++){
		fac[i] = fac[i-1] * i % P;
		ifac[i] = qpow(fac[i], P-2);
	}
}

ll comb(int n, int k){
	if(k > n) return 0;
	return fac[n] * ifac[k] % P * ifac[n-k] % P;
}


int main(){

//	freopen("1.in", "r", stdin);
//	freopen("1.ans", "w", stdout);

 	cin>>N>>M;
 	if(N < M) swap(N,M);
 	init();
 	
 	ll ans = 0;
 	for(int i=1;i<=M;i++){
 		ans = (ans + comb(N+M-2*i,M-i) * comb(2*i,i) % P) % P;
	}
 	ans = ans * qpow(comb(N+M, M), P-2) % P * qpow(2, P-2) % P;
 	ans = (ans + N) % P;
 	
    cerr<<"ans = "<<ans<<endl;
    printf("%lld\n", ans);

    return 0;
}