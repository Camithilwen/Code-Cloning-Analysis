/*  Perseverance can make miracle happens  */
/* If u identify me then u r my frnd */

#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define pq priority_queue<int>
#define mpi map<int,int>
#define pb push_back
#define ff first
#define ss second
#define forn(i,n) for(int i=0;i<n;i++)
#define M 1000000007
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)

int mod(long long x) {
	return ((x % M + M) % M);
}
int add(int a, int b) {
	return mod(mod(a) + mod(b));
}
int diff(int a, int b) {
	return mod(mod(a) - mod(b));
}

int mul(int a, int b) {
	return mod(mod(a) * mod(b));
}

void solve() {

	int n; cin >> n;
	int a[n];
	int s = 0;
	forn(i, n) {
		cin >> a[i];
		s += a[i];
	}

	int ps[n];
	ps[0] = a[0];
	for (int i = 1; i < n; i++) {
		ps[i] = add(ps[i - 1] , a[i]);
	}


	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = add(mod(ans) , mul(a[i] , (s - ps[i])));
	}

	cout << ans << endl;


}


int32_t main() {

	fastio;

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	// int t; cin >> t;
	int t = 1;

	while (t--) {
		solve();
	}

	return 0;
}