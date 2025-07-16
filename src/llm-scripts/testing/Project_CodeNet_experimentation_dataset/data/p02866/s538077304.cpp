#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> d(n);
	FOR(i, 0, n) cin >> d[i];
	const int mod = 998244353;
	bool ok = d[0] == 0;
	FOR(i, 1, n) ok &= d[i] > 0;
	if (!ok){
		cout << 0 << endl;
		return 0;
	}

	vector<int> cnt(n, 0);
	for(auto i: d) cnt[i]++;
	while(cnt.back() == 0) cnt.pop_back();
	for(auto i: cnt) if (!i){
		cout << 0 << endl;
		return 0;
	}

	int ans = 1;
	FOR(i, 1, SZ(cnt)) FOR(j, 0, cnt[i]) ans = (ans * (LL) cnt[i - 1]) % mod;
	cout << ans << endl;	
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}
