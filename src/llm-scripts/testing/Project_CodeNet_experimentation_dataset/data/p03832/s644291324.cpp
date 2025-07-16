#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<list>
#include <cstring>
#include <functional>
//#include<unordered_map>
//#include<unordered_set>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF ((Int)1<<60)
#define EPS (1e-10)
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
#define RREP(i,n) for(int i=1; i<=(int)(n); ++i)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);++i)
typedef long long Int;
typedef pair<Int, Int> P;
typedef vector<double> vec;
typedef vector<vec> mat;
const int N = 100005;
//////////////////////////////

void add(int64_t& a, int64_t b) {
	a = (a + b) % MOD;
}
void mul(int64_t& a, int64_t b) {
	a = a*b % MOD;
}

vector<int64_t> fact, seq_inv, fact_inv;

void create_fact_mod(int num) {
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= num; i++) fact[i] = fact[i - 1] * i % MOD;
}

void create_seq_inv_mod(int num) {
	seq_inv[0] = seq_inv[1] = 1;
	for (int i = 2; i <= num; i++) seq_inv[i] = (MOD - MOD / i) * seq_inv[MOD%i] % MOD;
}

void create_fact_inv_mod(int num) {
	fact_inv[0] = fact_inv[1] = 1;
	for (int i = 2; i <= num; i++) fact_inv[i] = fact_inv[i - 1] * seq_inv[i] % MOD;
}

void create_mod_tables(int num) {
	fact.resize(num + 1);
	seq_inv.resize(num + 1);
	fact_inv.resize(num + 1);
	create_fact_mod(num);
	create_seq_inv_mod(num);
	create_fact_inv_mod(num);
}

int64_t comb_mod(int n, int k) {
	return fact[n] * fact_inv[n - k] % MOD * fact_inv[k] % MOD;
}

int64_t perm_mod(int n, int k) {
	return fact[n] * fact_inv[n - k] % MOD;
}

int64_t power_mod(int64_t num, int64_t power) {
	int64_t prod = 1;
	num %= MOD;
	while (power > 0) {
		if (power & 1) prod = prod * num % MOD;
		num = num * num % MOD;
		power >>= 1;
	}
	return prod;
}

int64_t extgcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
	int64_t d = a;
	if (b != 0) {
		d = extgcd(b, a%b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}

int64_t inv_mod(int64_t a) {
	int64_t x, y;
	extgcd(a, MOD, x, y);
	return (MOD + x%MOD) % MOD;
}


void solve()
{
	int M, A, B, C, D;
	cin >> M >> A >> B >> C >> D;
	create_mod_tables(1000);

	static int64_t dp[1001][1001];
	dp[A - 1][0] = 1;
	for (int i = A; i <= B; i++) 
		for (int j = 0; j <= M; j++) {
			add(dp[i][j], dp[i - 1][j]);
			int n = M - j;
			int64_t pw = power_mod(fact_inv[i], C);
			for (int k = C; k <= D && i*k <= n; k++) {
				int64_t res = comb_mod(n, i*k) * fact[i*k] % MOD * pw % MOD * fact_inv[k] % MOD;
				mul(pw, fact_inv[i]);
				add(dp[i][j + i*k], dp[i - 1][j] * res);
			}
		}

	cout << dp[B][M] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}

