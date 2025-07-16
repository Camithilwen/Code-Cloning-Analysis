#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<climits>
#include<map>
#include<string>
#include<functional>
#include<iomanip>
#include<deque>
#include<random>
#include<set>
#include<bitset>
#include<cassert>

using namespace std;
typedef long long ll;
typedef double lldo;
#define mp make_pair
#define pub push_back
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define chmax(x,y) x = max(x,y)
ll gcd(ll a, ll b) { if (a % b == 0) { return b; } else  return gcd(b, a % b); }
ll lcm(ll a, ll b) { if (a == 0) { return b; }return a / gcd(a, b) * b; }
template<class T>ll LBI(vector<T>& ar, T in) { return lower_bound(ar.begin(), ar.end(), in) - ar.begin(); }
template<class T>ll UBI(vector<T>& ar, T in) { return upper_bound(ar.begin(), ar.end(), in) - ar.begin(); }

ll h, w, a, b;
map<ll, ll> m;
multiset<ll> vals;

int main() {
	cin >> h >> w;
	rep(i, w) {
		m[i] = i;
		vals.insert(0);
	}
	rep(i, h) {
		cin >> a >> b;
		a--;
		auto it = m.lower_bound(a);
		ll mr = -1;
		while (it != m.end() && it->first <= b) {
			mr = it->second;
			vals.erase(vals.find(it->first - it->second));
			it = m.erase(it);
		}
		if (b == w)mr = -1;
		if (mr != -1) {
			m[b] = mr;
			vals.insert(b - mr);
		}
		if (vals.size()) {
			cout << *vals.begin() + i + 1 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}