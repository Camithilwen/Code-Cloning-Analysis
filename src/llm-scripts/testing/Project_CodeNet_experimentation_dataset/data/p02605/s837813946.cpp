#include "bits/stdc++.h"
#define ll long long
#define lld long double
#define MOD 998244353
#define inf 1000000000
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll power(ll x,ll y, ll md=inf){ll res = 1;x%=md;while(y){if(y&1)res = (res*x)%md;x *= x; if(x>=md) x %= md; y >>= 1;}return res;}
 
using namespace std;

#define endl '\n'
#define int ll


signed main() {
	fast;

	int n;
	cin>>n;
	vector<pair<pii,char>> v(n);

	for(int i=0;i<n;i++) cin>>v[i].f.f>>v[i].f.s>>v[i].s;

	map<int,set<int>> mn1, mn2;
	
	int f = 1;
	int ans = inf;

	for(int i=0;i<n;i++) {
		if(v[i].s=='U') {
			mn1[v[i].f.f].insert(v[i].f.s);
		}

		if(v[i].s=='R') {
			mn2[v[i].f.s].insert(v[i].f.f);
		}
	}

	for(int i=0;i<n;i++) {
		if(v[i].s=='D') {
			auto it = mn1[v[i].f.f].lower_bound(v[i].f.s);
			if(it!=mn1[v[i].f.f].begin()) {
				it--;
				f = 0;
				ans = min(ans, 5*(v[i].f.s-*it));
			}
		}
		if(v[i].s=='L') {
			auto it = mn2[v[i].f.s].lower_bound(v[i].f.f);
			if(it!=mn2[v[i].f.s].begin()) {
				it--;
				f = 0;
				ans = min(ans, 5*(v[i].f.f-*it));
			}
		}
	}

	sort(all(v));

	map<int,int> st[4];
	for(int i=0;i<n;i++) {
		int x = v[i].f.f + v[i].f.s;

		if(v[i].s=='U' && st[3].count(x)) {
			f = 0;
			ans = min(ans, 10*abs(v[i].f.f-st[3][x]));
		}
		if(v[i].s=='L' && st[1].count(x)) {
			f = 0;
			ans = min(ans, 10*abs(v[i].f.f-st[1][x]));
		}

		if(v[i].s=='U') st[0][x] = v[i].f.f;
		if(v[i].s=='D') st[1][x] = v[i].f.f;
		if(v[i].s=='L') st[2][x] = v[i].f.f;
		if(v[i].s=='R') st[3][x] = v[i].f.f;
	}

	map<int,int> dt[4];
	for(int i=0;i<n;i++) {
		int x = v[i].f.f - v[i].f.s;

		if(v[i].s=='D' && dt[3].count(x)) {
			f = 0;
			ans = min(ans, 10*abs(v[i].f.f-dt[3][x]));
		}
		if(v[i].s=='L' && dt[0].count(x)) {
			f = 0;
			ans = min(ans, 10*abs(v[i].f.f-dt[0][x]));
		}

		if(v[i].s=='U') dt[0][x] = v[i].f.f;
		if(v[i].s=='D') dt[1][x] = v[i].f.f;
		if(v[i].s=='L') dt[2][x] = v[i].f.f;
		if(v[i].s=='R') dt[3][x] = v[i].f.f;
	}

	if(f) cout<<"SAFE";
	else cout<<ans;
}