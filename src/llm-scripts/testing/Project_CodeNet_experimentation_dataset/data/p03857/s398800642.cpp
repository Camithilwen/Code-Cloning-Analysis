#include <bits/stdc++.h>
#ifdef _WIN32
#include "debug.hpp"
#endif
using namespace std;

#define rep(i, N)  for(int i = 0; i < (N); i++)
#define reps(i, N) for(int i = 1; i <= (N); i++)
#define repr(i, N) for(int i = (N) - 1; i >= 0; i--)
#define pub push_back

template<typename T> 
void chmax(T &a, T b){ a = max(a, b); };
template<typename T> 
void chmin(T &a, T b){ a = min(a, b); };

typedef long long ll;
typedef pair<int, int> P;
const int INF = 100000000;
const ll LINF = 10000000000000000;
const int MOD = 1000000007;
const int dx[9] = { 0, 1,  0, -1, 1,  1, -1, -1, 0};
const int dy[9] = { 1, 0, -1,  0, 1, -1, -1,  1, 0};
//--------------------------------------//
int N, K, L;
vector<int> G[2][200000];

int d[2][200000];

int ans[200000];
map<P, int> m;
void bfs(int s, int c, int b){
	queue<int> q;
	q.push(s);
	d[b][s] = c;
	while(!q.empty()){
		int n = q.front(); q.pop();
		rep(i, G[b][n].size()){
			int to = G[b][n][i];
			if(d[b][to] == 0){
				d[b][to] = c;
				q.push(to);
			}
		}
	}
}
void solve(){
	rep(i, 2){
		int c = 1;
		rep(j, N){
			if(d[i][j] == 0){
				bfs(j, c, i);
				c++;
			}
		}
	}
	rep(i, N){
		m[P(d[0][i], d[1][i])]++;
	}
	rep(i, N){
		cout << m[P(d[0][i], d[1][i])] << (i == N - 1 ? '\n' : ' ');
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> K >> L;
	rep(i, K) {
		int p, q;
		cin >> p >> q;
		p--; q--;
		G[0][p].pub(q);
		G[0][q].pub(p);
	}
	rep(i, L) {
		int r, s;
		cin >> r >> s;
		r--; s--;
		G[1][r].pub(s);
		G[1][s].pub(r);
	}
	solve();
	return 0;
}
