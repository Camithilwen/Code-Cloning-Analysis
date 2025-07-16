#include <bits/stdc++.h>
#define int long long 
using namespace std;
typedef pair<int,int> ii;

int fact[2000005];
int mod = 998244353;
long long qexp(long long b, long long p){
    long long res = 1;
    while(p){
        if(p&1) res = (res * b) % mod;
        b = (b * b) % mod;
        p >>= 1;
    }
    return res;
}
int inv(long long b){ return qexp(b, mod-2); }
int choose(int N, int C){
	if(N < C) return 0;
	int res = fact[N];
	res *= inv(fact[C]);
	res %= mod;
	res *= inv(fact[N-C]);
	res %= mod;
	return res;
}
int split(int total, int N){ ///split total objects to N groups
	return choose(N + total - 1, N - 1);
}

int ans = 0;
void fix(int &x){
	x %= mod;
	if(x < 0) x += mod;
}
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	fact[0] = 1;
	for(int i = 1;i <= 2000000;i++) fact[i] = (fact[i-1] * i) % mod;
	
	int N, M; cin >> N >> M;
		
	for(int ones = 0;ones <= M;ones++){
		int zeros = N - ones;
		
		int leftover = 3*M - ones;
		if(leftover & 1) continue;
		
		leftover /= 2; ///The number of 2s to assign elsewhere
		
		int ways01 = choose(N, ones); ///ways to arrange the 0s and 1s
		
		int total2 = split(leftover, N); ///total ways to assign 
		int oneTooBig = ones * split(leftover - M, N);
		int zeroTooBig = zeros * split(leftover - M - 1, N);
		
		total2 -= oneTooBig;
		total2 -= zeroTooBig;
		
		fix(total2);
		ans += total2 * ways01;
		fix(ans);
	}
	
	cout << ans;
}


