#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define all(c) (c).begin(),(c).end()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const ll inf = 2e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;

int dp[1 << 16], sum[1 << 16];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	int a[n][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	sum[0] = 0;
	for(int mask = 1; mask < (1LL << n); mask++) {
		vi v;
		for(int i = 0; i < n; i++) {
			if(mask & (1LL << i)) {
				v.pb(i);
			}
		}
		for(int i = 0; i < v.size(); i++) {
			for(int j = i + 1; j < v.size(); j++) {
				sum[mask] += a[v[i]][v[j]];
			}
		}
	}
	memset(dp, -63, sizeof(dp));
	dp[0] = 0;
	for(int mask = 1; mask < (1LL << n); mask++) {
		for(int s = mask; s > 0; s = mask & (s - 1)) {
			dp[mask] = max(dp[mask], sum[s] + dp[mask ^ s]);
		}
	}
	cout << dp[(1 << n) - 1];

	return 0;
}