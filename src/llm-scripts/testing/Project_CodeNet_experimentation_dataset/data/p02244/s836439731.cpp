#include <bits/stdc++.h>
#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)
#define _all(arg) begin(arg),end(arg)

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0; }
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0; }

using namespace std;
using vi=vector<int>;

vector<int> m(8, -1);
vector<int> ans(8, -1);

bool valid() {
	bool board[8][8] = {0};
	rep(i, 8) {
		if(m[i] == -1) continue;
		board[i][m[i]] = true;
	}
	const int dr[4] = {1, 1, 0, -1};
	const int dc[4] = {0, 1, 1, 1};
	rep(i, 8) {
		if(m[i] == -1) continue;
		rep(j, 4) {
			int q_r = i+dr[j], q_c = m[i]+dc[j];
			while(0<=q_r && q_r<8
					&&0<=q_c && q_c<8) {
				if(board[q_r][q_c]) return false;
				q_r += dr[j], q_c += dc[j];
			}
		}
	}
	return true;
}

void dfs(int r) {
	if(r == 8) {
		ans = m;
		return;
	}

	if(m[r] != -1) {
		dfs(r+1);
		return;
	}

	rep(i, 8) {
		m[r] = i;
		if(valid()) dfs(r+1);
		m[r] = -1;
	}
}

int main(void){
	int k; cin >> k;
	rep(i, k) {
		int r, c; cin >> r >> c;
		m[r] = c;
	}
	dfs(0);
	// rep(i, 8) {
	// 	cerr << ans[i] << " ";
	// }
	char board[8][8] = {0};
	rep(i, 8) rep(j, 8) board[i][j] = '.';
	rep(i, 8) {
		board[i][ans[i]] = 'Q';
	}
	rep(i, 8) {
		rep(j, 8) {
			cout << board[i][j];
		}
		cout << endl;
	}

	return 0;
}