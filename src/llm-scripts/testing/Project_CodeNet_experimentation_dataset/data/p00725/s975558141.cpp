#include <cstdio>
#include <algorithm>
using namespace std;

int w, h;
int map[20][20];
int ans = 11;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y, int move){
//	printf("x:%d y:%d move:%d\n", x, y, move);
	if(move == 11) return 0;
	for(int i=0; i<4; i++){
//		printf(" direction:%d\n", i);
		int nx = x, ny = y;
		if(0<=x+dx[i] && x+dx[i]<w && 0<=y+dy[i] && y+dy[i]<h && map[x+dx[i]][y+dy[i]] != 1){
//			printf(" Start moving\n");
			while(1){
//				printf("  %d %d\n", nx, ny);
				if(nx+dx[i]<0 || w<=nx+dx[i] || ny+dy[i]<0 || h<=ny+dy[i]) break;
//				printf("  On board\n");
				if(map[nx+dx[i]][ny+dy[i]] == 3){
					ans = min(ans, move+1);
//					printf("Goal! move=%d\n", move+1);
					break;
				}
//				printf("  Not Goal\n");
				if(nx+dx[i]<0 || w<=nx+dx[i] || ny+dy[i]<0 || h<ny+dy[i]){
//					printf("  Fall from board\n");
					break;
				}
				if(map[nx+dx[i]][ny+dy[i]] == 1){
//					printf("  Stop moving\n");
					map[nx+dx[i]][ny+dy[i]] = 0;
					dfs(nx, ny, move+1);
					map[nx+dx[i]][ny+dy[i]] = 1;
					break;
				}
//				printf("  Continue moving\n");
				nx += dx[i];
				ny += dy[i];
//				printf("  next:%d, %d\n", nx, ny);
			}
		}
	}
	return 0;
}

int main(){
	while(1){
		scanf("%d %d", &w, &h);
		if(w == 0 && h == 0) break;

		ans = 11;
		for(int i=0; i<20; i++){
			for(int j=0; j<20; j++){
				map[i][j] = 0;
			}
		}


		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				scanf("%d", &map[j][i]);
			}
		}

		int sx, sy;
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(map[j][i] == 2){
					sx = j;
					sy = i;
					map[j][i] = 0;
				}
			}
		}
		dfs(sx, sy, 0);

		if(ans == 11) printf("-1\n");
		else printf("%d\n", ans);
	}

	return 0;
}