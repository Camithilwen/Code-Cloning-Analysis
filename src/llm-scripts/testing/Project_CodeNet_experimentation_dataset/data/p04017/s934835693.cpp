#include<bits/stdc++.h>
using namespace std;

#define w cout
#define e '\n'
#define int long long
#define sz(x) (int)x.size()
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

int mod = 998244353;

void solve() {
	int n ; cin >> n;
	int v[n + 1] = {};
	for(int i = 1 ; i <= n ;i ++) cin >> v[i];
	int dd[n + 1][30];
	
	memset(dd , 0, sizeof dd);
	
	int l , q; cin >> l >> q;
	
	for(int i = 1; i <= n ;i ++){
		int can = v[i] - l;
		dd[i][0] = max(1ll , (int)(lower_bound(v + 1 , v + n + 1 , can) - v));
	}
	for(int i = 1; i <= n ;i ++) {
		for(int j = 1; j <= 17 ;j ++) {
			dd[i][j] = dd[dd[i][j-1]][j-1];
		}
	}
	
	while(q--) {
		int a ,b ; cin >> a >> b;
		if(a > b) swap(a , b);
		int ans = 0;
		
		for(int j = 17 ; j >= 0; j --) {
			if(dd[b][j] > a) {
				ans += pow(2 , j);
				b = dd[b][j];
			}
		}
		w << ans + 1 << e;
	}
}

signed main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1; 
	//~ cin >> t;
	while(t--) {
		solve();
	}
} 
