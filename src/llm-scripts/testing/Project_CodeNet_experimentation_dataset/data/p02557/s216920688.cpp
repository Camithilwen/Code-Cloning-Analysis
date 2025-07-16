#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#define MOD 1000000007
#define MOD2 998244353
#define int long long
#define double long double
#define EPS 1e-9
//#define PI 3.14159265358979

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

template < typename T >
ostream &operator<<(ostream &os, const vector< T > &A) {
	for (int i = 0; i < A.size(); i++)
		os << A[i] << " ";
	os << endl;
	return os;
}
template <>
ostream &operator<<(ostream &os, const vector< vector< int > > &A) {
	int N = A.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < A[i].size(); j++)
			os << A[i][j] << " ";
		os << endl;
	}
	return os;
}
template < typename T, typename U >
ostream &operator<<(ostream &os, const pair< T, U > &p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}

typedef pair< int, int > pii;
typedef long long ll;

struct edge {
	int from, to, d, c, i;
	edge(int _from = 0, int _to = 0, int _d = 0, int _c = 0) {
		from = _from;
		to = _to;
		d = _d;
		c = _c;
	}
	bool operator<(const edge &rhs) const {
		return (d == rhs.d) ? (c < rhs.c) : (d < rhs.d);
	}
};
struct aabb {
	int x1, y1, x2, y2;
	aabb(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};

typedef vector< edge > edges;
typedef vector< edges > graph;
struct flow {
	int to, cap, rev, cost;
	flow(int to = 0, int cap = 0, int rev = 0, int cost = 0) : to(to), cap(cap), rev(rev), cost(cost) {}
};
typedef vector< vector< flow > > flows;

const int di[4] = {0, -1, 0, 1};
const int dj[4] = {-1, 0, 1, 0};
const int ci[5] = {0, 0, -1, 0, 1};
const int cj[5] = {0, -1, 0, 1, 0};
const ll LINF = LLONG_MAX / 2;
const int INF = INT_MAX / 2;
const double PI = acos(-1);

int pow2(int n) { return 1LL << n; }
template < typename T, typename U >
bool chmin(T &x, const U &y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}
template < typename T, typename U >
bool chmax(T &x, const U &y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}

template < typename A, size_t N, typename T >
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
struct initializer {
	initializer() {
		cout << fixed << setprecision(20);
	}
};
initializer _____;
bool BMdfs(vector< int > &M, vector< vector< int > > &G, vector< bool > &used, int v) {
	used[v] = true;
	rep(i, G[v].size()) {
		int u = G[v][i], w = M[u];
		if (w < 0 || !used[w] && BMdfs(M, G, used, w)) {
			M[v] = u;
			M[u] = v;
			return true;
		}
	}
	return false;
}
int BMatching(vector< vector< int > > &G, vector< int > &M) {
	vector< bool > used(G.size());
	M.assign(G.size(), -1);
	int ret = 0;
	rep(v, G.size()) {
		if (M[v] < 0) {
			used.assign(G.size(), false);
			if (BMdfs(M, G, used, v)) {
				ret++;
			}
		}
	}
	return ret;
}
int BMatching(vector< vector< int > > &G) {
	vector< int > M;
	return BMatching(G, M);
}
int N, M, K, T, Q, H, W;
signed main() {
	cin >> N;
	vector< int > A(N);
	rep(i, N) cin >> A[i];
	vector< int > B(N);
	rep(i, N) cin >> B[i];
	int j = 0;
	rep(i, N) {
		if (A[i] == B[i]) {
			while (j < N && (A[i] == A[j] || A[i] == B[j]))
				j++;
			if (j == N) {
				cout << "No" << endl;
				return 0;
			}
			swap(B[i], B[j]);
		}
		if (i < N - 1 && A[i] != A[i + 1])
			j = 0;
	}
	cout << "Yes" << endl;
	cout << B;
	return 0;
}