#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define dump(x)  cout << #x << " = " << (x) << endl;	//debug
#define SZ(x) ((ll)(x).size())
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define pvd(v) cout << setprecision(16) << (v) << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, start_index, num)  (a).begin()+(start_index),(a).begin()+(num)

int main() {
	int n, k;
	cin >> n >> k;
	deque<ll> d;
	FOR(i, 1, n) {
		int v;
		cin >> v;
		d.push_back(v);
	}
	ll res = 0;
	int lim = min(k, n);
	FOR(i, 0, lim) {
		FOR(j, 0, i) {
			deque<ll> d2 = d;
			vector<ll> jw;
			FOR(left, 1, j) {
				jw.push_back(d2.front());
				d2.pop_front();
			}
			FOR(right, 1, i - j) {
				jw.push_back(d2.back());
				d2.pop_back();
			}
			sort(ALL(jw));
			FOR(index, 0, k - i - 1) {
				if (index <= i - 1 && jw[index] < 0) {
					jw[index] = 0;
				}
			}
			ll tmp = accumulate(ALL(jw), 0LL);
			res = max(res, tmp);
		}
	}

	pv(res)
}