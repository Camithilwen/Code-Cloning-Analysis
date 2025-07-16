#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>

#include <string>
#include <cstring>
#include <vector>
#include <bitset>

#include <queue>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <ctime>
////
//#include <random>//
/////////

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

////定数
const int INF = (int)1e9 + 10;
const LL MOD = (LL)1e9 + 7;
const LL LINF = (LL)4e18 + 20;
const LD PI = acos(-1.0);
const double EPS = 1e-9; 
/////////
using namespace::std;
void chmax(LL& a, LL b) {
	a = max(a, b);
}
//////////////
vector<LL> kai(200001);
vector<LL> kai_inv(200001);

LL powMod(LL num, LL n, LL mod = (LL)MOD) {//(num**n)%mod
	num %= mod;//
	if (n == 0) {
		return (LL)1;
	}
	LL mul = num;
	LL ans = (LL)1;
	while (n) {
		if (n & 1) {
			ans = (ans * mul) % mod;
		}
		mul = (mul * mul) % mod;
		n >>= 1;
	}
	return ans;
}
LL mod_inverse(LL num, LL mod = MOD) {
	return powMod(num, MOD - 2, MOD);
}

LL nCk(LL N, LL k, LL mod = MOD) {
	LL ans = 1;
	if (k == 0 || k == N) {
		return 1;
	}
	ans = (kai[N] * kai_inv[N - k]) % mod;
	ans = (ans * kai_inv[k]) % mod;
	return ans;
}

LL cal(LL H, LL W,LL K) {
	LL ans = 0;
	LL base = nCk(H * W - 2, K - 2);
	base = (base * H) % MOD;
	base = (base * H) % MOD;
	for (LL i = 0; i < W; ++i) {
		ans += i * (W - i);
		ans %= MOD;
	}
	/*
	for (int w1 = 0; w1 < W; ++w1) {
		for (int w2 = w1; w2 < W; ++w2) {
			ans += abs(w1 - w2);
			ans %= MOD;
		}
	}
	*/
	ans = (ans * base) % MOD;
	return ans;
}
void solve() {
	LL N, M, K;
	cin >> N >> M >> K;

	kai[0] = 1; //kai_inv[0] = mod_inverse(1);
	kai[1] = 1; kai_inv[1] = mod_inverse(1);

	for (int i = 2; i <= 200000; ++i) {
		kai[i] = (kai[i - 1] * i) % MOD;
		kai_inv[i] = mod_inverse(kai[i]);
	}
	LL ans = (cal(N, M, K) + cal(M, N, K)) % MOD;
	cout << ans << endl;
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
