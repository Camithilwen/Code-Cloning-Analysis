#include<bits/stdc++.h>
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

struct st {
	int f[20][20], cnt, x, y, id;
};
int dx[]{ 1,-1,0,0 }, dy[]{ 0,0,1,-1 };
int main() {
	st in;
	int w, h;
	while (scanf("%d%d", &w, &h), w) {
		rep(i, h)rep(j, w) {
			scanf("%d", &in.f[i][j]);
			if (in.f[i][j] == 2)in.x = i, in.y = j;
		}
		in.cnt = 0;
		in.id = -1;
		queue<st>que;
		que.push(in);
		int Min = INT_MAX;
		while (!que.empty()) {
			st s = que.front(); que.pop();
			if (s.f[s.x][s.y] == 3) {
				Min = min(Min, s.cnt);
				continue;
			}
			if (s.id == -1) {
				rep(i, 4) {
					int nx = s.x + dx[i], ny = s.y + dy[i];
					if (0 <= nx&&nx < h && 0 <= ny&&ny < w&&s.f[nx][ny] != 1) {
						st p = s; p.cnt++; p.x = nx; p.y = ny; p.id = i;
						if (p.cnt <= 10 && p.cnt < Min)que.push(p);
					}
				}
			}
			else {
				int nx = s.x + dx[s.id], ny = s.y + dy[s.id];
				if (0 <= nx&&nx < h && 0 <= ny&&ny < w) {
					if (s.f[nx][ny] == 1) {
						st p = s; p.f[nx][ny] = 0; p.id = -1;
						que.push(p);
					}
					else {
						st p = s; p.x = nx; p.y = ny;
						que.push(p);
					}
				}
			}
		}
		if (Min == INT_MAX)puts("-1");
		else printf("%d\n", Min);
	}
}