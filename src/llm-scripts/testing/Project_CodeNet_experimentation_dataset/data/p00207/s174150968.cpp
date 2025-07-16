#include <stdio.h>
#include <cctype>
#include <limits.h>
#include <math.h>
#include <complex>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <iostream>

#define VARIABLE(x) cerr << #x << "=" << x << endl
#define BINARY(x) static_cast<bitset<16> >(x);
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)
#define if_range(x, y, w, h) if (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))

const int INF = 1e9;
const double EPS = 1e-8;
const double PI = 3.14159;
int dx[4]={0, 1, 0, -1}, dy[4]={-1, 0, 1, 0};
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
/* struct P {
	int x, y, n;
	P(int n, int x, int y):n(n), x(x), y(y){}
	P(){}
}; */

/** Problem0207 : Block **/
int main()
{
	int W, H;
	
	while (cin>>W>>H, W||H) {
		vector<vector<int> > board(W, vector<int>(H));
		int sx, sy, gx, gy;
		cin>>sx>>sy>>gx>>gy;
		sx--, sy--, gx--, gy--;
		
		int N; cin>>N;
		while (N--) {
			int c, d, x, y; cin>>c>>d>>x>>y;
			x--, y--;
			
			if (d==0) {
				board[x][y] = board[x+1][y] = board[x+2][y] = board[x+3][y] = c;
				board[x][y+1] = board[x+1][y+1] = board[x+2][y+1] = board[x+3][y+1] = c;
			} else {
				board[x][y] = board[x][y+1] = board[x][y+2] = board[x][y+3] = c;
				board[x+1][y] = board[x+1][y+1] = board[x+1][y+2] = board[x+1][y+3] = c;
			}
		}
		
		/**
		rep(i, H) {
			rep(j, W) {
				cerr << board[j][i] << " ";
			}
			cerr << endl;
		} **/
		
		queue<P> Q;
		bool vis[100][100]={0};
		Q.push(P(sx, sy));
		vis[sx][sy]=true;
		
		while (Q.size()) {
			P p = Q.front(); Q.pop();
			if (p.first == gx && p.second == gy) {
				cout << "OK" << endl;
				goto end;
			}
			rep(i, 4) {
				int nx = p.first+dx[i], ny = p.second+dy[i];
				if_range(nx, ny, W, H) {
					if (!vis[nx][ny] && board[nx][ny] == board[p.first][p.second]) {
						Q.push(P(nx, ny));
						vis[nx][ny] = true;
					}
				}
			}
		}
		cout << "NG" << endl;
	end:;
	}
}