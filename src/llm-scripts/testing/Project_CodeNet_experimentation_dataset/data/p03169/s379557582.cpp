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

double dp[305][305][305];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	int cnt[4] = {0};
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	for(int k = 0; k <= cnt[3]; k++) {
		for(int j = 0; j <= cnt[2] + cnt[3]; j++) {
			for(int i = 0; i <= n; i++) {
				if(i + j + k == 0) {
					dp[i][j][k] = 0;
				}
				else {
					dp[i][j][k] = 1;
					if(i >= 1) {
						dp[i][j][k] += (1.0 * i / n) * dp[i - 1][j][k];
					}
					if(j >= 1) {
						dp[i][j][k] += (1.0 * j / n) * dp[i + 1][j - 1][k];
					}
					if(k >= 1) {
						dp[i][j][k] += (1.0 * k / n) * dp[i][j + 1][k - 1];
					}
					dp[i][j][k] /= (1 - (1.0 * (n - i - j - k) / n));
				}
			}
		}
	}
	cout << fixed << setprecision(12) << dp[cnt[1]][cnt[2]][cnt[3]];

	return 0;
}