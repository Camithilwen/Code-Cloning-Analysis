#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
#include<stack>
#include<cstdio>
#include<bitset>
#include<unordered_map>
#include<climits>
#include<fstream>
using namespace std;
///////////////////library zone!!!!!!!!!!!!!!!!!!!!!!!!!!!!
typedef long long ll;
typedef long double ld;
#define all(a) (a).begin(),(a).end()
const ll Mod = 1000000007;
const ll mod = 998244353;
struct H {
	ll x, y;
	bool operator<(const H &b) const {
		if (x != b.x) return x < b.x;
		return y < b.y;
	}
	bool operator>(const H &b) const {
		if (x != b.x) return x > b.x;
		return y > b.y;
	}
	bool operator==(const H &b) const { return x == b.x&&y == b.y; }
	bool operator!=(const H &b) const { return (*this) != b; }
};
struct P {
	ll pos, cost;
	bool operator<(const P &b) const { return cost < b.cost; }
	bool operator>(const P &b) const { return cost > b.cost; }
};
struct B {
	ll to, cost;
};
struct E {
	ll from, to, cost;
	bool operator<(const E &b) const { return cost < b.cost; }
	bool operator>(const E &b) const { return cost > b.cost; }
};
template<typename T, typename U>
void chmin(T &a, U b) {
	if (a > b) a = b;
}
template<typename T, typename U>
void chmax(T &a, U b) {
	if (a < b) a = b;
}
template<typename T>
T max_0(T a) {
	if (a < 0) return 0;
	return a;
}
template<typename T>
T min_0(T a) {
	if (a > 0) return 0;
	return a;
}
ll read() {
	ll u;
	scanf("%lld", &u);
	return u;
}
ll gcd(ll i, ll j) {
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcd(j%i, i);
}
ll mod_pow(ll x, ll n, ll p) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % p;
		x = x * x % p;
		n >>= 1;
	}
	return res;
}//x^n%p
const ll Inf = 3023372036854775807;
const int inf = 1500000000;
#define int long long
//----------------------------------------------------
int h, w;
bool a[3000][3000];
int b[3000][3000];
signed main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < w; j++) {
			if (s[j] == '#') a[i][j] = 1;
		}
	}
	//bは、これより右でこことしたがの関係が同じところの長さ
	for (int j = w - 1; j >= 0; j--) b[h - 1][j] = w - j;
	for (int i = 0; i < h - 1; i++) {
		for (int j = w - 1; j >= 0; j--) {
			if (j == w - 1 || ((a[i][j] == a[i + 1][j]) != (a[i][j + 1] == a[i + 1][j + 1]))) {
				b[i][j] = 1;
			}
			else {
				b[i][j] = b[i][j + 1] + 1;
			}
		}
	}
	int ans = 0;
	for (int j = 0; j < w; j++) {
		stack<H>st;
		//x=高さ、y=場所
		for (int i = h - 1; i >= 0; i--) {
			if (!st.empty() && st.top().x > b[i][j]) {
				int k = i;
				while (!st.empty() && st.top().x > b[i][j]) {
					if (st.top().y == h - 1)
						ans = max(ans, (st.top().y - i)*st.top().x);
					else
						ans = max(ans, (st.top().y - i + 1)*st.top().x);
					k = st.top().y;
					st.pop();
				}
				st.push(H{ b[i][j],k });
			}
			else if (st.empty() || st.top().x < b[i][j]) {
				st.push(H{ b[i][j],i });
			}
		}
		while (!st.empty()) {
			if (st.top().y == h - 1)
				ans = max(ans, (st.top().y + 1)*st.top().x);
			else
				ans = max(ans, (st.top().y + 2)*st.top().x);
			st.pop();
		}
	}
	cout << ans << endl;
}