#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& x) {
	return os << "(" << x.first << "," << x.second << ")";
}
typedef long long ll;
typedef long double ld;
template <typename T>
struct Fenwick {
	int n;
	vector<T> bit;
	Fenwick(int _n) : n(_n) {
		bit.resize(n + 1);
	}
	void update(int p, T v) {
		for (; p <= n; p += p & -p) bit[p] += v;
	}
	T query(int p) {
		T ret{};
		for (; p; p -= p & -p) ret += bit[p];
		return ret;
	}
};
int main() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> A(3, vector<int>(n));
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < n; ++j) {
			scanf("%d", &A[i][j]);
			--A[i][j];
		}
	vector<int> flip(2);
	auto no = []() {
		printf("No\n");
		exit(0);
	};
	for (int c = 0; c < n; ++c) {
		if (A[0][c] / 3 != A[1][c] / 3 || A[1][c] / 3 != A[2][c] / 3 || A[1][c] % 3 != 1) {
			no();
		}
		if ((A[0][c] / 3) % 2 != (c % 2)) no();
		flip[c % 2] ^= A[0][c] % 3 == 2;
	}
	for (int p = 0; p < 2; ++p) {
		Fenwick<int> fenw(n);
		for (int c = p; c < n; c += 2) {
			int i = A[0][c] / 3;
			int greater = fenw.query(n) - fenw.query(i + 1);
			flip[1 - p] ^= greater & 1;
			fenw.update(i + 1, 1);
		}
	}
	printf(flip[0] == 0 && flip[1] == 0 ? "Yes\n" : "No\n");
}
