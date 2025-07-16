//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 4 * 100 * 1000 + 17;

int n, a[4][MAXN], b[4][MAXN], p[MAXN], q[MAXN], fen[MAXN];
vector<int> v[2];

void add(int x) {
	for (; x <= n; x += x & (-x))
		fen[x]++;
}
int get(int x) {
	int res = 0;
	for (; x; x -= x & (-x))
		res += fen[x];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j], b[i][j] = j * 3 + i - 3, p[b[i][j]] = j, q[b[i][j]] = i;
	for (int j = 1; j <= n; j++) {
		if (p[a[1][j]] != p[a[2][j]] || p[a[2][j]] != p[a[3][j]] || q[a[2][j]] != 2 || p[a[1][j]] % 2 != j % 2)
			return cout << "No" << endl, 0;
		v[j % 2].pb(j);
	}
	for (int k = 0; k < 2; k++) {
		int inv = 0;
		for (int i = v[k].size() - 1; i >= 0; i--)
			(inv += get(p[a[1][v[k][i]]])) %= 2, add(p[a[1][v[k][i]]]);
		int up = 0;
		for (int i = 0; i < v[1 - k].size(); i++)
			if (a[1][v[1 - k][i]] % 3 == 0)
				up++;
		if (up % 2 != inv % 2)
			return cout << "No" << endl, 0;
		for (int i = 1; i <= n; i++)
			fen[i] = 0;
	}
	cout << "Yes" << endl;
	return 0;
}
