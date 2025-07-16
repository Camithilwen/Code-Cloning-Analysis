#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <time.h>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) (min(a,b) <= (x) && (x) <= max(a,b)) //hei
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MODU 1000000007LL
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#define PI 3.141592653589


#define izryt bool
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
	std::fill((T*)array, (T*)(array + N), val);
}
pll Dir[4] = {
	{ -1 ,0 },{ 0 , 1 },{ 1 ,0 },{ 0 ,-1 }
};

//[a, b)
#define Getsum(ar, a,b) (ar[b] - ar[a])
#define INF 10000000000000000LL
#define chmax(a,b) a = max(a,b)
#define chmin(a,b) a = min(a,b)

struct Edge {
	int from, to;
	ll w;
	bool operator<(const Edge& rhs) const {
		return MP(w, MP(from, to)) < MP(rhs.w, MP(rhs.from, rhs.to));
	}
};

typedef vector<set<Edge>> Graph;

struct Segtree {

};

signed main(void) {

	int n, m;
	cin >> n >> m;

	vector<ll> a(n), b(m), upc(n * m + 1);
	multiset<ll> aa, ba;
	REP(i, n) {
		cin >> a[i];
		aa.insert(a[i]);
	}

	REP(i, m) {
		cin >> b[i];
		ba.insert(b[i]);
	}

	REP(i, n) {
		REP(j, m) {
			upc[min(a[i], b[j])]++;
		}
	}

	for (int i = n * m; 1 <= i; i--)
		upc[i - 1] += upc[i];

	ll used = 0;
	ll ans = 1;
	for (int i = n * m; 1 <= i; i--) {
		if (aa.count(i) > 1 || ba.count(i) > 1) {
			cout << 0 << endl;
			return 0;
		}
		if (aa.count(i)) {
			if (!ba.count(i)) {
				int cc = 0;
				REP(j, m) {
					cc += b[j] > i;
				}

				ans *= cc;
			}
		}

		else if (ba.count(i)) {
			if (!aa.count(i)) {
				int cc = 0;
				REP(j, n) {
					cc += a[j] > i;
				}

				ans *= cc;
			}
		}
		else {

			ans *= upc[i] - used;

		}
		ans %= MODU;
		used++;
	}

	cout << ans << endl;

	return 0;
}
