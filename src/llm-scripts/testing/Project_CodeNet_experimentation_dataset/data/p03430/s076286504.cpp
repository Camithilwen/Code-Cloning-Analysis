#include <bits/stdc++.h>

#define ll long long
#define pii pair <int, int>
#define x first
#define y second

using namespace std;

string s;
int dp[301][301][301];

inline int solve(int l, int r, int k) {
    if (k < 0)
        return INT_MIN;
    if (r - l < 1)
        return r - l + 1;
    if (dp[l][r][k] != -1)
        return dp[l][r][k];
    return dp[l][r][k] = max(solve(l + 1, r - 1, k - (s[l] != s[r])) + 2, max(solve(l + 1, r, k), solve(l, r - 1, k)));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k;
    cin >> s >> k;
    memset(dp, -1, sizeof(dp));
    return cout << solve(0, s.length() - 1, k), 0;
}
