#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
int w,h,ans = inf,gx,gy;
int grid[21][21];
int syoki[21][21];
int x[4] = {-1,0,1,0};
int y[4] = {0,1,0,-1};

bool in(int a,int b){
  if(a< 0 || b<0 || w<=a || h<=b)return false;
  return true;
}

void dfs(int w1,int h1,int count){
  //  cout<<h1<<" "<<w1<<" "<<count<<endl;
  if(count == 10)return;
  for(int i = 0;i < 4;i++){
    int a = w1,b = h1;
    if(in(a+y[i],b+x[i]) && grid[b+x[i]][a+y[i]]==0){
      while(1){
	if(!in(a+y[i],b+x[i]))break;
	if((b+x[i])==gy && (a+y[i]) == gx){
	  ans = min(ans,count+1);
	  return;
	}
	else if(grid[b+x[i]][a+y[i]] == 1){
	  grid[b+x[i]][a+y[i]] = 0;
	  dfs(a,b,count+1);
	  grid[b+x[i]][a+y[i]] = 1;
	  break;
	}
	a += y[i];
	b += x[i];
      }
    }
  }
}
  
int main(){
  int sx,sy;
  while(1){
    cin >> w >> h;
    if(w == 0)break;
    for(int i = 0;i < h;i++){
      for(int j = 0;j < w;j++){
	cin >> grid[i][j];
	if(grid[i][j] == 2){
	  sx = j;
	  sy = i;
	  grid[i][j]=0;
	}
	if(grid[i][j] == 3){
	  gx = j;
	  gy = i;
	  grid[i][j]=0;
	}

      }
    }
    ans = inf;
    dfs(sx,sy,0);
    if(ans == inf)cout << -1 <<endl;
    else cout << ans <<endl;
  }
  return 0;
}