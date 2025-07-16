#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

#ifdef BTK
#define DEBUG if(1)
#else
#define CIN_ONLY if(1)
struct cww {cww() {CIN_ONLY{ios::sync_with_stdio(false); cin.tie(0);}}
}star;
#define DEBUG if(0)
#endif

#define ALL(v) (v).begin(),(v).end()
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline bool chmin(T &l, T r){bool a = l>r; if (a)l = r; return a;}
template <typename T>inline bool chmax(T &l, T r){bool a = l<r; if (a)l = r; return a;}
template <typename T>istream& operator>>(istream &is, vector<T> &v){for (auto &it : v)is >> it;return is;}

class range {private: struct I { int x; int operator*() { return x; }bool operator!=(I& lhs) { return x<lhs.x; }void operator++() { ++x; } }; I i, n;public:range(int n) :i({ 0 }), n({ n }) {}range(int i, int n) :i({ i }), n({ n }) {}I& begin() { return i; }I& end() { return n; }};
typedef vector<int> V;
typedef vector<V> VV;
int col[612][612][2];
int N;
void coloring(int r, int c, int k, VV& edge) {
	for (auto &e : edge) {
		int nr = r + e[0];
		int nc = c + e[1];
		if (nr < 0 || N <= nr)continue;
		if (nc < 0 || N <= nc)continue;
		if (col[nr][nc][k] != -1)continue;
		col[nr][nc][k] = 1 - col[r][c][k];
		coloring(nr, nc, k, edge);
	}
}
int main() {
	LL latte, malta;
	cin >> N >> latte >> malta;
	N *= 2;
	vector<VV> e(2);
	for (int i : range(-N,N+1))for (int j : range(-N,N+1)) {
		if (i*i + j*j == latte)e[0].push_back({ i,j });
		if (i*i + j*j == malta)e[1].push_back({ i,j });
	}
	for (int i : range(N))for (int j : range(N))for (int k : range(2))col[i][j][k] = -1;
	for (int i : range(N))for (int j : range(N))for (int k : range(2))if (col[i][j][k] == -1) {
		col[i][j][k] = 0;
		coloring(i, j, k, e[k]);
	}
	int cnt[2][2] = { {0,0},{0,0} };
	for (int i : range(N))for (int j : range(N)) {
		cnt[col[i][j][0]][col[i][j][1]]++;
	}
	int ai = 0, aj = 0;
	for (int i : range(2))for (int j : range(2)) {
		if (cnt[ai][aj] < cnt[i][j])ai = i, aj = j;
	}
	int M = N * N / 4;
	for (int i : range(N))for (int j : range(N)) {
		if (col[i][j][0] == ai && col[i][j][1] == aj && M > 0) {
			cout << i << " " << j << endl;
			M--;
		}
	}

	return 0;
}
