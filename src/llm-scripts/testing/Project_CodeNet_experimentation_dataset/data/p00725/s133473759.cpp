#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int h, w;
int grid[20][20];
int sx, sy, gx, gy;

bool ok(int x, int y)
{
	return x >= 0 && y >= 0 && x < h && y < w;
}

bool search(int d, int x, int y)
{
	if (d == 0){
		return x == gx && y == gy;
	}
	
	for (int dir = 0; dir < 4; dir++){
		int k = 0;
		while (true){
			int nx = x + dx[dir] * k;
			int ny = y + dy[dir] * k;
			int nnx = nx + dx[dir];
			int nny = ny + dy[dir];
			if (!ok(nx, ny)) break;
			if (grid[nx][ny] == 3){
				return true;
			}
			if (!ok(nnx, nny)) break;
			if (grid[nnx][nny] == 1){
				if (k == 0) break;
				grid[nnx][nny] = 0;
				if (search(d - 1, nx, ny)){
					grid[nnx][nny] = 1;
					return true;
				}
				grid[nnx][nny] = 1;
				break;
			}
			k++;
		}
	}
	
	return false;
}

int solve()
{
	for (int d = 1; d <= 10; d++){
		if (search(d, sx, sy)){
			return d;
		}
	}
	return -1;
}

int main()
{
	while (scanf("%d %d", &w, &h), w){
		fill_n(*grid, 20 * 20, 0);
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				scanf("%d", &grid[i][j]);
				if (grid[i][j] == 2){
					sx = i;
					sy = j;
				}
				else if (grid[i][j] == 3){
					gx = i;
					gy = j;
				}
			}
		}
		printf("%d\n", solve());
	}
	
	return 0;
}