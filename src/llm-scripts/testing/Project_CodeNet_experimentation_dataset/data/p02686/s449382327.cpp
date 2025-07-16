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
 
ll N;

void solve() {
    cin >> N;
    vector<string> a(N);
    vector<l_l> adds, subs;
    
	int tlc = 0, trc = 0;
 
    for (int i = 0; i < N; i++) {
		int lc = 0, rc = 0;
		cin >> a[i];
		for (auto& c : a[i]) {
			if (c == '(') {
				lc++;
			} else {
				if (lc) lc--;
				else rc++;
			}
		}
		if (lc && !rc) tlc += lc;
		else if (!lc && rc) trc += rc;
		else if (lc && rc) {
			if (lc >= rc) adds.push_back({rc, lc});
			else subs.push_back({lc, rc});
		}
	}
	sort(adds.begin(), adds.end());
    sort(subs.begin(), subs.end(), greater<pair<int, int>>());
    
    bool pos = true;
    for (auto& i : adds) {
		if (i.first > tlc) {
			pos = false;
			break;
		} else {
			tlc -= i.first;
			tlc += i.second;
		}
	}
	
	for (auto& i : subs) {
		if (i.second > tlc) {
			pos = false;
			break;
		} else {
			tlc -= i.second;
			tlc += i.first;
		}
	}
    
    if (pos && tlc == trc) cout << "Yes";
    else cout << "No";
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
