//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0xccccccc;
const ll LINF = 922337203685477580LL;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

const int N = 310;

//head

int n;
int a[N], cnt[4];
ld _[N][N][N];

ld dfs(int i, int j, int k) {
	if(_[i][j][k] > -0.5) return _[i][j][k];
	ld &res = _[i][j][k] = 0;
	int n_ = i+j+k;
	if(i) res += dfs(i-1, j, k) * i/n_;
	if(j) res += dfs(i+1, j-1, k) * j/n_;
	if(k) res += dfs(i, j+1, k-1) * k/n_;
	if(n_) res += (ld)n/n_;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n) cnt[a[i]]++;
	rep(i, n+1) rep(j, n+1) rep(k, n+1) _[i][j][k] = -1;
	cout << fixed << setprecision(20) << dfs(cnt[1], cnt[2], cnt[3]) << endl;
}