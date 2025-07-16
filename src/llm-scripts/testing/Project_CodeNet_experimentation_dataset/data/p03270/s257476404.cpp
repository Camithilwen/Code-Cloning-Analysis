#include "bits/stdc++.h"
using namespace std;
//template <typename... T> void read(T& ... t){ ((cin >> t), ...); }
//template <typename... T> void write(T ... t){ ((cout << t), ...); }
//#define int long long
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define size(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ln '\n'
#define space ' '
using LL = long long;
using pii = pair<int,int>;
const int INF = 2e9;
const int NN = 2e3;
const int MOD = 998244353;
namespace Mm{
	inline int mul(const LL &x, const LL &y) { return (x*y)%MOD; }
	inline int add(const LL &x, const LL &y) { return (x+y)%MOD; }
	inline int power(const LL &x, const LL &n){ if(n == 0) return 1; int y=power(x, n>>1); y=mul(y,y); return (n&1)?mul(y,x):y; }
	inline int inv(const LL &x){ return power(x, MOD-2); }
	// int _fact[2*NN] = {0};
	// inline int fact(const int &x){ return (x==0 ? 1 : (_fact[x]!=0 ? _fact[x] : _fact[x]=mul(x, fact(x-1)))); }
	// inline int cnk(const int &n, const int &k){ return (n<k)?0:mul(fact(n),inv(mul(fact(k),fact(n-k)))); }
	int _cnk[2*NN+1][2*NN+1] = {0};
	inline int cnk(const int &n, const int &k){ return (n<k)?0:(k==0)?1:(_cnk[n][k]!=0?_cnk[n][k]:_cnk[n][k]=add(cnk(n-1,k),cnk(n-1,k-1))); }
} using namespace Mm;
int n,k;
int dp[NN+1][NN+1];
int nbPairs[2*NN+1];

#define read(a,b) cin>>a>>b
#define write(a,b) cout<<a<<b

int32_t main(){ FAST;
	read(k,n);
	dp[0][0] = 1;
	for(int i=1; i<=NN; ++i){ // #pairs
		int prefSum = 0;
		for(int j=0; j<=NN; ++j){ // #items to distribute on pairs
			dp[i][j] = add(dp[i-1][j], add(prefSum, prefSum)); // k € [1;j]
			prefSum = add(prefSum, dp[i-1][j]);
		}
	}

	for(int i=1; i<=k; ++i) for(int j=i+1; j<=k; ++j) ++nbPairs[i+j];

	for(int i=2; i<=2*k; ++i){
		int ans = 0;
		int others = k - 2*nbPairs[i];

		if(i&1){
			if(others == 0){
				ans = dp[nbPairs[i]][n];
				write(ans, ln);
				continue;
			}

			for(int giveOthers=0; giveOthers<=n; ++giveOthers){
				int givePairs = n-giveOthers;
				ans = add(ans, mul(dp[nbPairs[i]][givePairs], cnk(others+giveOthers-1, giveOthers)));
			}
		}
		else{
			--others;
			if(others == 0){
				ans = add(dp[nbPairs[i]][n], dp[nbPairs[i]][n-1]);
				write(ans, ln);
				continue;
			}
			
			for(int giveOthers=0; giveOthers<=n; ++giveOthers){
				int givePairs = n-giveOthers;
				ans = add(ans, mul(dp[nbPairs[i]][givePairs], cnk(others+giveOthers-1, giveOthers)));
			}
			for(int giveOthers=0; giveOthers<=n-1; ++giveOthers){
				int givePairs = n-1-giveOthers;
				ans = add(ans, mul(dp[nbPairs[i]][givePairs], cnk(others+giveOthers-1, giveOthers)));
			}
		}

		write(ans, ln);
	}
}