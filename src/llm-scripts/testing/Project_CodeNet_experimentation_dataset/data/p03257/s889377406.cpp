#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define REP(i,n) for( (i)=0 ; (i)<(n) ; (i)++ )
#define rep(i,x,n) for( (i)=(x) ; (i)<(n) ; (i)++ )
#define REV(i,n) for( (i)=(n) ; (i)>=0 ; (i)-- )
#define FORIT(it,x) for( (it)=(x).begin() ; (it)!=(x).end() ; (it)++ )
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define rforeach(it,c) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)
#define foreach2d(i, j, v) foreach(i,v) foreach(j,*i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define SZ(x) ((int)(x).size())
#define MMS(x,n) memset(x,n,sizeof(x))
#define mms(x,n,s) memset(x,n,sizeof(x)*s)
#define pb push_back
#define mp make_pair
#define NX next_permutation
#define UN(x) sort(all(x)),x.erase(unique(all(x)),x.end())
#define CV(x,n) count(all(x),(n))
#define FIND(x,n) find(all(x),(n))-(x).begin()
#define ACC(x) accumulate(all(x),0)
#define PPC(x) __builtin_popcountll(x)
#define LZ(x) __builtin_clz(x)
#define TZ(x) __builtin_ctz(x)
#define mxe(x) *max_element(all(x))
#define mne(x) *min_element(all(x))
#define low(x,i) lower_bound(all(x),i)
#define upp(x,i) upper_bound(all(x),i)
#define NXPOW2(x) (1ll << ((int)log2(x)+1))
#define PR(x) cout << #x << " = " << (x) << endl ;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;

const int OO = (int) 2e9;
const double eps = 1e-9;

const int N = 100005;

int di[] = { -1, 0, 0, 1 };
int dj[] = { 0, -1, 1, 0 };

int n;
bool p[100005];
vi primes;

void sieve() {
	MMS(p, 1);
	p[0] = p[1] = 0;
	for (int i = 2; i < N; i++) {
		if (p[i]) {
			for (int j = 2 * i; j < N; j += i)
				p[j] = 0;
		}
	}
	for (int i = 2; i < N; i++) {
		if (p[i])
			primes.pb(i);
	}
}

ll a[501][501];

ll setV(int i, int j) {
	int d0 = (i + j) >> 1;
	int d1 = n + ((i - j + n - 1) >> 1);
	return primes[d0] * 1LL * primes[d1];
}

ll get(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= n)
		return -1;
	return a[i][j];
}

ll calc(int i, int j) {
	ll res = 1;
	for (int d = 0; d < 4; d++) {
		int ni = i + di[d];
		int nj = j + dj[d];
		ll v = get(ni, nj);
		if (v != -1)
			res = res / __gcd(res, v) * v;
	}
	return res + 1;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);
#endif
	sieve();
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (((i + j) & 1) == 0) {
				a[i][j] = setV(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (((i + j) & 1)) {
				a[i][j] = calc(i, j);
			}
		}
	}
	if (n == 2) {
		a[1][0] *= 2;
		a[1][0]--;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " \n"[j == n - 1];
		}
	}
	return 0;
}
