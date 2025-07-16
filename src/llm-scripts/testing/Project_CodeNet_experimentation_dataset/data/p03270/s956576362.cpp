#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define int ll

#define rep(i, a) for (int i = 0; (i) < (int) (a); (i)++)
#define reps(i, a, b) for (int i = (int) (a); (i) < (int) (b); (i)++)
#define rrep(i, a) for (int i = (int) a-1; (i) >= 0; (i)--)
#define rreps(i, a, b) for (int i = (int) (a)-1; (i) >= (int) (b); (i)--)
#define MP(a, b) make_pair((a), (b))
#define PB(a) push_back((a))
#define all(v) (v).begin(), (v).end()
#define PERM(v) next_permutation(all(v))
#define UNIQUE(v) sort(all(v));(v).erase(unique(all(v)), v.end())
#define CIN(type, x) type x;cin >> x
#define TRUE__  "Yes"
#define FALSE__ "No"
#define PRINT(f) if((f)){cout << (TRUE__) << endl;}else{cout << FALSE__ << endl;}
#define RS resize
#define CINV(v, N) do {\
	v.RS(N);\
	rep(i, N) cin >> v[i];\
} while (0);
#define RCINV(v, N) do {\
	v.RS(N);\
	rrep(i, N) cin >> v[i];\
} while (0);

#define MOD 998244353

template<class T>
inline T GET() {
	T x;
	cin >> x;
	return x;
}

void init();
void solve();

signed main()
{
	init();
	solve();
}

ll dp[2020][2020];
ll sum;
int K, N;

void init()
{
	cin >> K >> N;
	rep(i, K) {
		dp[N-1][i] = 1;
	}
	rrep(i, N-1) {
		ll a = 0;
		rrep(j, K) {
			a += dp[i+1][j];
			a %= MOD;
			dp[i][j] = a;
		}
	}
	rep(i, K) {
		sum += dp[0][i];
		sum %= MOD;
	}
}

struct comb {
#define MOD_COMB MOD
	vector<ll> fact;
	vector<ll> facti;
	comb(int n) {
		init(n);
	}
	void init(int n) {
		fact.resize(n);
		facti.resize(n);
		fact[0] = 1;
		for (int i = 1; i < n; i++) {
			fact[i] = fact[i-1] * i % MOD_COMB;
		}
		facti[n-1] = po(fact[n-1], MOD_COMB - 2);
		for (int i = n-2; i >= 0; i--) {
			facti[i] = facti[i+1] * (i + 1) % MOD_COMB;
		}
	}
	ll nCr(int a, int b) {
		return (fact[a] * facti[b] % MOD_COMB) * facti[a-b] % MOD_COMB;
	}
private:
	ll po(ll next, int cnt) {
		ll res = 1;
		if (cnt == 0) return 1;
		if (cnt & 1) res = res * next % MOD_COMB;
		return res * po(next * next % MOD_COMB, cnt >> 1) % MOD_COMB;
	}
};

void solve()
{
	vector<ll> res;
	comb co(2020);
	if (K == 1) {
		cout << 0 << endl;
		return;
	}
	int i = 0;
	reps(cnt, 3, K+3) {
		ll hugo = 1;
		ll ans = 0;
		rep(j, i+1) {
			ans += hugo * co.nCr(i+1, j+1) * dp[j*2+1][0];
			ans %= MOD;
			hugo *= -1;
		}
		res.PB(ans);
		res.PB(ans);
		cnt++;
		i++;
	}
	if (K%2) res.pop_back();
	rep(i, res.size()) {
		cout << (sum - res[i] + MOD) % MOD << endl;
	}
	rrep(i, res.size()-1) {
		cout << (sum - res[i] + MOD) % MOD << endl;
	}
}



