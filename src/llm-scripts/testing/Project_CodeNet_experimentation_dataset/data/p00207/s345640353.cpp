#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

bool block[6][110][110];
bool visit[110][110];

int main(){
	int w, h;
	int xs, ys, xg, yg;
	int n, c, d, x, y;
	while(scanf("%d%d%d%d%d%d%d", &w, &h, &xs, &ys, &xg, &yg, &n) == 7){
		memset(block, 0, sizeof block);
		memset(visit, 0, sizeof visit);

		for(int i = 0; i < n; ++i){
			scanf("%d%d%d%d", &c, &d, &x, &y);
			
			int dx, dy;
			if(d){ dx = 2; dy = 4; }
			else{  dy = 2; dx = 4; }

			for(int j = 0; j < dy; ++j)
			for(int k = 0; k < dx; ++k){
				block[c][y + j][x + k] = true;
			}
		}

		for(c = 5; c > 1 && !block[c][ys][xs]; --c);

		if(c){
			queue<int> q;
			q.push(ys << 16 | xs);
			visit[ys][xs] = true;
			while(!q.empty()){
				y = q.front() >> 16;
				x = q.front() & 0xffff;
				q.pop();

				for(int dy = -1; dy <= 1; ++dy)
				for(int dx = -1; dx <= 1; ++dx){
					if(block[c][y+dy][x+dx] && !visit[y+dy][x+dx]){
						visit[y+dy][x+dx] = true;
						q.push(y+dy << 16 | x+dx);
					}
				}
			}
		}

		puts(visit[yg][xg] ? "OK" : "NG");
	}
}