#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, m, n) for(int i=(m); i<(n); ++i)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define Cout(x) cout << (x) << endl
#define Cout2(x, y) cout << (x) << " " << (y) << endl
#define dump(x) cout << #x << " = " << (x) << endl;
#define forauto(i, a) for(auto i : a)cout << i << " "; puts("");
typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<vector<int>> VVI;
typedef pair<int, int> PII;
const int inf = 1e9;
const double pi = acos(-1.0);

int main() {
	int n, m;
	while (cin >> n >> m && (n || m)) {
		VI p(n); rep(i, n)cin >> p[i];
		sort(all(p)); reverse(all(p));

		int ans = 0;
		for (int i = 0; i < n; i += m) {
			for (int j = i; j < min(i + m - 1, n); j++) {
				ans += p[j];
			}
		}
		Cout(ans);
	}
}
