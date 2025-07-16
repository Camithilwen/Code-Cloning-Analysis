#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define mod 1000000007 //1e9+7
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 30

int mm[SIZE][SIZE];
int w,h;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int dfs(int y,int x,int depth = 0){
  int ret = INF;

  if(depth >= 10) return INF;
  
  //
  for(int i=0;i<4;i++){
    int tx = x + dx[i];
    int ty = y + dy[i];
    
    if(ty<0 || h<=ty || tx<0 || w<=tx || mm[ty][tx]==1) continue;

    if(mm[ty][tx]==3) return depth+1;
    
    while(1){
      tx += dx[i];
      ty += dy[i];
      
      if(ty<0 || h<=ty || tx<0 || w<=tx) break;
      
      if(mm[ty][tx]==3) return depth+1;

      if(mm[ty][tx]==1){
	mm[ty][tx] = 0;
	ret = min(ret,dfs(ty-dy[i],tx-dx[i],depth+1));
	mm[ty][tx] = 1;
	break;
      }
    }

  }

  return ret;
}

int calc(){
  int sy,sx;
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      scanf("%d",mm[i]+j);
      if(mm[i][j]==2){
	sy = i;
	sx = j;
      }
    }
  }

  int ans = dfs(sy,sx);
  
  if(ans==INF) ans = -1;
  
  return ans;
}

int main(){

  while(1){
    scanf("%d%d",&w,&h);
    if(w==0) break;
    printf("%d\n",calc());
  }

  
  return 0;
}