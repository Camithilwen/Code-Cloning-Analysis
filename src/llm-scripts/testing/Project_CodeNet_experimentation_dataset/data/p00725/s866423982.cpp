#include <iostream>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int field[20][20];

int dfs(int W, int H, int x, int y, int step, int limit){
	if(++step > limit){ return limit; }
	for(int i = 0; i < 4; ++i){
		int fx = x + dx[i], fy = y + dy[i];
		if(fx < 0 || fx >= W || fy < 0 || fy >= H){ continue; }
		while(!(fx < 0 || fx >= W || fy < 0 || fy >= H)){
			if(field[fy][fx] < 0){ return step; }
			if(field[fy][fx] > 0){
				fx -= dx[i]; fy -= dy[i];
				break;
			}
			fx += dx[i]; fy += dy[i];
		}
		if(fx < 0 || fx >= W || fy < 0 || fy >= H){ continue; }
		if(fx == x && fy == y){ continue; }
		field[fy + dy[i]][fx + dx[i]] = 0;
		limit = min(limit, dfs(W, H, fx, fy, step, limit));
		field[fy + dy[i]][fx + dx[i]] = 1;
	}
	return limit;
}

int main(){
	while(true){
		int w, h;
		cin >> w >> h;
		if(w == 0 && h == 0){ break; }
		int x = 0, y = 0;
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				cin >> field[i][j];
				if(field[i][j] == 2){
					x = j; y = i;
					field[i][j] = 0;
				}else if(field[i][j] == 3){
					field[i][j] = -1;
				}
			}
		}
		int answer = dfs(w, h, x, y, 0, 11);
		if(answer >= 11){ answer = -1; }
		cout << answer << endl;
	}
	return 0;
}