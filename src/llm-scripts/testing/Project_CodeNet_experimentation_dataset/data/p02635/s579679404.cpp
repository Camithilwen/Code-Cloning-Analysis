// IOI 2021
#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll MOD = 998244353;
 
////////////////////////////////////////////////////////////////////
 
const int N = 3e2 + 5;

int A[N], DP[N][N][N];

void Add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int main() {
 
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mt19937 Rnd(time(0));

	string S; cin >> S;
	int m = 1, o = 0;
	for (char c : S) if (c == '0') m++; else A[m - 1]++, o++;
	reverse(A, A + m);
	DP[0][0][0] = 1;
	for (int i = 0; i < m; i++) for (int j = 0; j <= o; j++) for (int k = 0; k <= o; k++) {
		if (!DP[i][j][k]) continue;
		for (int l = 0; l <= A[i] + k; l++) Add(DP[i + 1][j + max(A[i] - l, 0)][k + A[i] - l], DP[i][j][k]);
	}
	int k; cin >> k;
	k = min(k, o);
	int ans = 0;
	for (int i = 0; i <= k; i++) Add(ans, DP[m][i][0]);
	cout << ans << endl;

	return 0;
}
