#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define rep2(x,from,to) for(int x = (from); x < (to); ++(x))
#define rep(x,to) rep2(x,0,to)
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int b[14][14];
void dfs(int y, int x) {
	if(!b[y][x]) return;
	b[y][x] = 0;
	rep(i,4) {
		dfs(y+dy[i], x+dx[i]);
	}
}
int main() {
	string s;
	while(cin >> s) {
		rep(i,14) {
			b[0][i] = b[i][0] = 0;
			b[13][i] = b[i][13] = 0;
		}
		rep(i,12) {
			b[1][i+1] = s[i] - '0';
		}
		rep2(i,2,13) {
			cin >> s;
			rep(j,12) {
				b[i][j+1] = s[j] - '0';
			}
		}
		int cnt = 0;
		rep(i,14) {
			rep(j,14) {
				if(b[i][j]) {
					dfs(i,j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}