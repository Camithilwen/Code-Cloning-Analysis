#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


const int mod = 998244353;

const int N = 307;

int dp[N][N][2*N][2];

inline int sum(int x, int y) {
	if (x+y < 0) return x+y+mod;
	if (x+y >= mod) return x+y-mod;
	return x+y;
}
 
inline int mult(int x, int y) {
	return ((ll) x * y) % mod;
}

int main(){
#ifdef LOCAL
	freopen("I_input.txt", "r", stdin);
	//freopen("I_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int k;
	cin >> k;

	vector<int> arr;

	int R = 0;

	int now = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '1') {
			R++;
			now++;
		}
		else {
			arr.push_back(now);
			now = 0;
		}
	}

	arr.push_back(now);

	dp[0][0][0][0] = 1;

	int cur = 0;

	for (int i = 0; i < arr.size(); ++i) {

		for (int was = 0; was <= R; ++was) {
			for (int delta = 0; delta <= 2*s.size(); ++delta) {
				int T = sum(dp[i][was][delta][0], dp[i][was][delta][1]);
				if (T == 0) continue;

				for (int be = 0; be <= arr[i] && was+be <= R; ++be) {
					dp[i+1][was + be][delta + arr[i] - be][0] = sum(dp[i+1][was + be][delta + arr[i] - be][0], T);
				}

				if (i + 1 < arr.size() && was + arr[i] + 1 <= R) {
					dp[i+1][was+arr[i]+1][delta+1][1] = sum(dp[i+1][was+arr[i]+1][delta+1][1], T);
				}
			}
		}

		for (int was = 0; was <= R; ++was) {
			for (int delta = 0; delta <= 2*s.size(); ++delta) {
				if (dp[i+1][was][delta][1] && was+1 <= R) {
					dp[i+1][was+1][delta+1][1] = sum(dp[i+1][was][delta][1], dp[i+1][was+1][delta+1][1]);
				}
			}
		}

		cur += arr[i];

		for (int was = 0; was < cur; ++was) for (int delta = 0; delta <= 2*s.size(); ++delta) {
			dp[i+1][was][delta][0] = 0;
			dp[i+1][was][delta][1] = 0;
		}

	}

	//cout << dp[3][2][2][0] << " " << R << endl;

	int ans = 0;

	for (int delta = 0; delta <= 2*s.size(); ++delta) if (delta <= 2*k) {

		int T = sum(dp[arr.size()][R][delta][0], dp[arr.size()][R][delta][1]);

		ans = sum(ans, T);
	}

	cout << ans;

}
