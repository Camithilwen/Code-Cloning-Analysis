#include<bits/stdc++.h>
using namespace std;
int h,w;
int maps[101][101];
int check[101][101];
int dy[]={-1,0,1,0};
int dx[]={0,-1,0,1};
int color;
int sy,sx,gy,gx;
int by0[]={0,0,1,1,0,0,1,1};
int bx0[]={0,1,1,0,2,3,2,3};
int by1[]={0,0,1,1,2,3,2,3};
int bx1[]={0,1,1,0,0,0,1,1};

bool solve(int y,int x);
  
int main(){
  int n,c,d,x,y;
  while(cin>>w>>h,w|h){
    cin>>sx>>sy;
    cin>>gx>>gy;
    cin>>n;
    memset(check,0,sizeof(check));
    for(int i=0;i<n;i++){
      cin>>c>>d>>x>>y;
      x--;y--;
      if(d==0){
	for(int i=0;i<8;i++){
	  maps[y+by0[i]][x+bx0[i]]=c;
	}
      }
      if(d==1){
	for(int i=0;i<8;i++){
	  maps[y+by1[i]][x+bx1[i]]=c;
	}
      }
    }
    sy--;sx--;gy--;gx--;
    color=maps[sy][sx];
    if(solve(sy,sx))cout<<"OK"<<endl;
    else cout<<"NG"<<endl;
  }
}

bool solve(int y,int x){
  check[y][x]=1;
  if(y==gy && x==gx)return true;
  bool b=false;
  for(int i=0;i<4;i++){
    int ny=y+dy[i];
    int nx=x+dx[i];
    if(ny>=0 && ny<h && nx>=0 && nx<w && maps[ny][nx]==color && check[ny][nx]==0){
      b=b | solve(ny,nx);
    }
  }
  return b;
}
       
	
  