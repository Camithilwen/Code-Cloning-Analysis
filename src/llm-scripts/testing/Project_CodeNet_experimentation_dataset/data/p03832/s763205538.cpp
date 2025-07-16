#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

//ａをbで割る
long long mod_div(long long a,long long b){
	if(a % b == 0)return a/b;
	long long tmp = MOD - 2,c = b,ret = 1;
	while(tmp > 0){
		if(tmp & 1){
			ret *= c;ret %= MOD;
		}
		c *= c;c %= MOD;tmp >>= 1;
	}
	return a*ret%MOD;
}
 
#define MAX_K 333333
vector<long long> kaijo(MAX_K);
long long combination(long long n, long long r){
    if(n < r || n < 0 || r < 0)
        return 0;
	if(kaijo[0] != 1){
		kaijo[0] = 1;
		for(long long i = 1;i < MAX_K;i++)kaijo[i] = (kaijo[i-1] * i) % MOD;
	}
    long long ret = kaijo[n];
	long long tmp = (kaijo[r] * kaijo[n-r]) % MOD;
    return mod_div(ret,tmp);
}

ll mpow(ll a,ll b){
	ll ret = 1;
	ll tmp = a;
	for(ll i = 0;i <= 60;i++){
		if(b & (1LL << i)){
			ret *= tmp;
			ret %= MOD;
		}
		tmp *= tmp;
		tmp %= MOD;
	}
	return ret;
}

ll comb[1111][1111];
ll dp[1111][1111];

int main(){
	
	ll n,a,b,c,d;cin >> n >> a >> b >> c >> d;
	dp[0][0] = 1;
	
	REP(i,1111){
		REP(j,1111){
			if(j == 0 || i == j)comb[i][j] = 1;
			else comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
		}
	}
		
	REP(i,b+1){
		REP(j,n+1)if(dp[i][j]){
			dp[i+1][j] += dp[i][j];
			dp[i+1][j] %= MOD;
			if(i < a)continue;
			ll kake = 1;
			for(ll k = 1;k <= d;k++){
				ll tmp = i * k;
				if(j + tmp > n)break;
				kake = (kake * comb[n-j-tmp+i][i]) % MOD;
				kake = mod_div(kake, k);
				if(k < c)continue;
				dp[i+1][j+tmp] += (dp[i][j] * kake) % MOD;
				dp[i+1][j+tmp] %= MOD;
			}
		}
	}
	
	SHOW2d(comb,10,10);
	SHOW2d(dp,10,10);
	
	cout << dp[b+1][n] << endl;
	
	return 0;
}
