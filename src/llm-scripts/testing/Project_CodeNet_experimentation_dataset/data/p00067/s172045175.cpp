#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

typedef pair<int, int> P;

int data[12][12] = {};
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1 ,0 ,-1};

void dfs(int sx, int sy) {
  queue<P> que;
  data[sx][sy] = 2;
  que.push(P(sx, sy));
  
  while(que.size()) {
    P p = que.front();
    que.pop();
    
    for(int i = 0; i < 4; i++) {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if(0 <= nx && nx < 12 && 0 <= ny && ny < 12 && data[nx][ny] == 1 ){
	que.push(P(nx, ny));
	data[nx][ny] = 2;
      }
    }
  }
}


int main(){
  while(~scanf("%1d", &data[0][0])) {
    int cnt = 0, i, j = 1;
    for(i = 0; i < 12; i++, j=0)
      for(;j < 12; j++) {
	scanf("%1d", &data[i][j]);
      }
    for(i = 0; i < 12; i++)
      for( j = 0; j < 12; j++)
	if(data[i][j] == 1){
	  dfs(i, j);
	  cnt++;
	}
    cout << cnt << endl;
  }
  return 0;
}