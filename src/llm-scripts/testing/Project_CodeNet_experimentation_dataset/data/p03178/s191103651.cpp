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
const int N = 1e4 + 10;

int dp[N][2][100];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string k;
	int d;
	cin >> k >> d;
	int n = k.length();
	dp[0][1][0] = 1;
	for(int i = 1; i <= n; i++) {
		int cur = k[i - 1] - '0';
		for(int j = 0; j <= 9; j++) {
			for(int rem = 0; rem < d; rem++) {
				dp[i][0][(rem + j) % d] = (dp[i][0][(rem + j) % d] + dp[i - 1][0][rem]) % mod;
				if(j < cur) {
					dp[i][0][(rem + j) % d] = (dp[i][0][(rem + j) % d] + dp[i - 1][1][rem]) % mod;
				}
				if(j == cur) {
					dp[i][1][(rem + j) % d] = (dp[i][1][(rem + j) % d] + dp[i - 1][1][rem]) % mod;
				}
			}
		}
	}
	cout << (dp[n][0][0] + dp[n][1][0] - 1 + mod) % mod;

	return 0;
}