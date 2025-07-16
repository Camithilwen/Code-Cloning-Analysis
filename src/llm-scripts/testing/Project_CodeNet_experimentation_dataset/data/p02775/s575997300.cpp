#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const ll INF = 1e18;
const ll MOD = 998244353;
const ll MX = 1000001;

string N;

void solve() {
	cin >> N;
	int a[N.size()], inv[N.size()];
	ll ans = 0;
	for (int i = 0; i < (int)N.size(); i++) {
		a[i] = (int)(N[i] - '0');
		inv[i] = -1;
		// ans += dp[i];
	}
	
	// Figure out what segments are better to inverse
	for (int i = N.size() - 1; i >= 0; --i) {
		if (a[i] > 5) {
			inv[i] = i;
			if (i + 1 < (int)N.size() && inv[i + 1] != -1) inv[i] = inv[i + 1];
		} else if (a[i] == 5) {
			if (i + 1 < (int)N.size() && inv[i + 1] != -1) inv[i] = inv[i + 1];
			else if (i > 0 && a[i - 1] >= 5) inv[i] = i;
		} else if (a[i] == 4) {
			if (i > 0 && i < (int)N.size() - 1) {
				if (a[i - 1] >= 5 && inv[i + 1] != -1) {
					inv[i] = inv[i + 1];
				}
			}
			
		}
	}
	
	int end = -1;
	for (int i = 0; i < (int)N.size(); i++) {
		if (end == -1) {
			if (inv[i] == -1) ans += a[i];
			else {
				ans += 2;
				end = inv[i];
				ans += 9 - a[i];
			}
		} else {
			ans += 9 - a[i];
		}
		if (i == end) end = -1;
	}
	cout << ans;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    ll T = 1; // cin >> T;
    while (T--) solve();
    return 0;
    // You should actually read the stuff at the bottom
}

/* Stuff to Look For
 * -----------------
 * Int overflow, array bounds
 * Initializing all variables, avoid weird behavior
 * Edge cases(n = 0, n = 1)
 * Just return 0 after result
 */
