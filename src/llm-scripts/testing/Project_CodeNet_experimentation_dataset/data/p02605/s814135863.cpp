#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
typedef long double db;
#define pb push_back
#define mp make_pair
#define ub(v,val) upper_bound(v.begin(),v.end(),val)-v.begin()
#define lb(v,val) lower_bound(v.begin(),v.end(),val)-v.begin()
#define sortv(vec) sort(vec.begin(),vec.end())
#define rev(p) reverse(p.begin(),p.end());
#define v vector
#define PI 3.1415926535
#define len length()
#define repc(i,s,e) for(ll i=s;i<e;i++)
#define np(str) next_permutation(str.begin(),str.end())
#define fi first
#define se second
#define mset(a,val) memset(a,val,sizeof(a));
#define mt make_tuple
#define repr(i,n) for(i=n-1;i>=0;i--)
#define rep(i,n) for( i=0;i<n;i++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int M = 1e9 + 7;
ll INF = 1e7;
ll n, m;

int main() {
	// your code goes here
	IOS;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll  i, j,  k, x, y,   N;
	char z;
	cin >> n;
	unordered_map<ll, v<ll>> u, d, l, r, u1, u2, r1, r2, l1, l2, d1, d2;
	rep(i, n) {
		cin >> x >> y >> z;
		if (z == 'U') {
			u[x].pb(y);
			u1[x - y].pb(x);
			u2[x + y].pb(x);

		}
		if (z == 'R') {
			r[y].pb(x);
			r1[(x - y)].pb(x);
			r2[x + y].pb(x);

		}
		if (z == 'D') {
			d[x].pb(y);
			d1[(x - y)].pb(x);
			d2[x + y].pb(x);

		}
		if (z == 'L') {
			l[y].pb(x);
			l1[(x - y)].pb(x);
			l2[x + y].pb(x);
		}
	}
	for (auto &dm : u) {
		sortv(dm.se);
	}
	for (auto &dm : u1) {
		sortv(dm.se);
	}
	for (auto &dm : u2) {
		sortv(dm.se);
	}
	for (auto &dm : r) {
		sortv(dm.se);
	}
	for (auto &dm : r1) {
		sortv(dm.se);
	}
	for (auto &dm : r2) {
		sortv(dm.se);
	}
	for (auto &dm : l) {
		sortv(dm.se);
	}
	for (auto &dm : l1) {
		sortv(dm.se);
	}
	for (auto &dm : l2) {
		sortv(dm.se);
	}
	for (auto &dm : d) {
		sortv(dm.se);
	}
	for (auto &dm : d1) {
		sortv(dm.se);
	}
	for (auto &dm : d2) {
		sortv(dm.se);
	}
	ll ans = INF;
	//u and d;

	for (auto dm : u) {
		x = dm.fi;
		for (auto dm2 : u[x]) {
			auto ind = upper_bound(d[x].begin(), d[x].end(), dm2);
			if (ind != d[x].end()) {
				ans = min(ans, (*ind - dm2) * 5);
			}

		}
	}
	//r and l
	for (auto dm : r) {
		y = dm.fi;
		for (auto dm2 : r[y]) {
			auto ind = upper_bound(l[y].begin(), l[y].end(), dm2);
			if (ind != l[y].end()) {
				ans = min(ans, (*ind - dm2) * 5);
			}

		}
	}
	//u and l
	for (auto dm : u1) {
		ll diff = dm.fi;
		for (auto dm2 : u1[diff]) {
			auto ind = upper_bound(l1[diff].begin(), l1[diff].end(), dm2);
			if (ind != l1[diff].end()) {
				ans = min(ans, (*ind - dm2) * 10);
			}
		}
	}
	//u and r
	for (auto dm : r2) {
		ll sum = dm.fi;

		for (auto dm2 : r2[sum]) {
			auto ind = upper_bound(u2[sum].begin(), u2[sum].end(), dm2);
			if (ind != u2[sum].end()) {
				ans = min(ans, (*ind - dm2) * 10);
			}
		}
	}
	//d and l
	for (auto dm : d2) {
		ll sum = dm.fi;

		for (auto dm2 : d2[sum]) {
			auto ind = upper_bound(l2[sum].begin(), l2[sum].end(), dm2);
			if (ind != l2[sum].end()) {
				ans = min(ans, (*ind - dm2) * 10);
			}
		}
	}
	//d and r
	for (auto dm : r1) {
		ll diff = dm.fi;

		for (auto dm2 : r1[diff]) {
			auto ind = upper_bound(d1[diff].begin(), d1[diff].end(), dm2);
			if (ind != d1[diff].end()) {
				ans = min(ans, (*ind - dm2) * 10);
			}
		}
	}
	if (ans == INF)
		cout << "SAFE";
	else cout << ans;






	return 0;
}

