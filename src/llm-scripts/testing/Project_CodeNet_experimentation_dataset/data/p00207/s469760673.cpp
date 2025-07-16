#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
bool solve(int x,int y,int c);
int ux[2][8]={{0,1,2,3,0,1,2,3},
	      {0,1,0,1,0,1,0,1}};
int uy[2][8]={{0,0,0,0,1,1,1,1},
	      {0,0,1,1,2,2,3,3}};
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int w,h,n;
int b[105][105];
int xs,ys,xg,yg;
int main(void){
  while(1){
    scanf("%d %d",&w,&h);
    if(!w && !h) break;
    memset(b,0,sizeof(b));
    scanf("%d %d %d %d",&xs,&ys,&xg,&yg);
    scanf("%d",&n);
    int c,d,tx,ty;
    for(int i=0;i<n;i++){
      scanf("%d %d %d %d",&c,&d,&tx,&ty);
      for(int j=0;j<8;j++){
	b[tx+ux[d][j]][ty+uy[d][j]]=c;
      }
    }
    if(b[xs][ys]!=0 && b[xg][yg]!=0 && b[xs][ys]==b[xg][yg] && solve(xs,ys,b[xs][ys])) puts("OK");
    else puts("NG");
  }
}

bool solve(int x,int y,int c){
  if(x==xg && y==yg) return true;
  b[x][y]=0;
  for(int i=0;i<4;i++){
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(0<nx && nx<=w && 0<ny && ny<=h){
      if(b[nx][ny]==c){
	if(solve(nx,ny,c)) return true;
      }
    }
  }
  return false;
}