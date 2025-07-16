#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
typedef pair<int, int>P;
typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll MOD = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 5000100;
//max=({});
//条件式が真ならwhileの中身を回し続ける
//printf("%d\n", ans);

//pairの入力
//vector<pair<ll, ll>>work(n);
//rep(i, n) {
//	ll a, b;
//	cin >> a >> b;
//	work[i] = make_pair(a, b);
//for(auto p:mp)(mapの探索)
//printf("%.10f\n",なんちゃら)
//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	if (x == 0 || y == 0)return 0;
	return (x / gcd(x, y) * y);
}

//組み合わせの余りを求める
ll fac[MAX_N], finv[MAX_N], inv[MAX_N];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX_N; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll dx[8] = { 0,0,-1,1 };
ll dy[8] = { -1,1,0,0 };
ll dp[101010];

//union-find木について
ll par[101010];
ll rank2[101010];

void init(ll n) {
	rep(i, n) {
		par[i] = i;
		rank2[i] = 0;
	}
}

ll find(ll x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}

void unite(ll x, ll y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (rank2[x] < rank2[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rank2[x] == rank2[y]) {
			rank2[x]++;
		}
	}
}

long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

bool graph[101][101];
bool visit[101010];
vector<ll> to[101010];
vector<ll>ball(101010, 1);
vector<bool>flag(101010);

//long longしか使わない
//素数は1より大きい
int main() {
	ll x, y;
	cin >> x >> y;
	ll ans = 0;
	if (y >= x) {
		if (x >= 0) {
			ans = y - x;
		}
		else if (y <= 0) {
			ans = y - x;
		}
		else {
			ll min2 = min(abs(x), abs(y));
			ll max2 = max(abs(x), abs(y));
			ans = max2 - min2 + 1;
		}
	}
	else {
		if (y >= 0) {
			ans = x - y + 2;
			if (y == 0) {
				ans = abs(x) + 1;
			}
		}
		else if (x <= 0) {
			ans = x - y + 2;
			if (x == 0) {
				ans = abs(y) + 1;
			}
		}
		else {
			ll min2 = min(abs(x), abs(y));
			ll max2 = max(abs(x), abs(y));
			ans = max2 - min2 + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
