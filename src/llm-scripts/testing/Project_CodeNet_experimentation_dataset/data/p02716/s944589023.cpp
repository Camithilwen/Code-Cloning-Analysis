#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const ll MMM = -1e18;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) cin >> a[i];
	int m = n/2;
	if (n&1) {
		ll ans = MMM;
		vector<ll> suff(m+1), pref(m+1), best_suff(m+1);
		// both end case
		for (int i=0; i<m; i++) {
			pref[i+1] = pref[i] + a[2*i];
		}
		for (int i=m-1; i>=0; i--) {
			suff[i] = suff[i+1] + a[2*i+2];
		}
		// single 3-jump
		for (int i=0; i<=m; i++) {
			ans = max(ans, pref[i] + suff[i]);
		}
		
		// double 2-jump
		for (int i=m-1; i>=0; i--) {
//			best_suff[i] = max(best_suff[i+1] + a[i*2+1], suff[i+1] + a[i*2+1]);
			best_suff[i] = max(best_suff[i+1], suff[i+1]) + a[i*2+1];
		}
		
		bool dbg = false;
		if (dbg) {
			cout << "PREF "; for (ll x : pref) cout << x << ' '; cout << '\n';
			cout << "SUFF "; for (ll x : suff) cout << x << ' '; cout << '\n';
			cout << "BEST "; for (ll x : best_suff) cout << x << ' '; cout << '\n';
		}
		
		ll best_pref = 0;
		ans = max(ans, best_suff[0]);
		for (int i=0; i<m; i++) {
			best_pref = max(best_pref, pref[i]) + a[i*2+1];
			ans = max(ans, best_pref + best_suff[i+1]);
		}
//		ans = max(ans, max(best_pref, pref[
		
		// one end case
		// should have covered by double 2-jump
		
		// neither end case
		ll tmp = 0;
		for (int i=0, idx=1; i<m; i++, idx+=2) tmp += a[idx];
		ans = max(ans, tmp);
		cout << ans;
	}
	else {
		vector<ll> suff(m+1);
		for (int i=m-1; i>=0; i--) {
			suff[i] = suff[i+1] + a[2*i+1];
		}
		ll ans = suff[0];
		ll pref = 0;
		for (int i=0; i<m; i++) {
			pref += a[i*2];
			ans = max(ans, pref + suff[i+1]);
		}
		cout << ans;
	}
}