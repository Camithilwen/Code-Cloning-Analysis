#include<bits/stdc++.h>
using namespace std;
int w,h,sy,sx,gx,gy,n;
int color;
int c,d,x,y;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int maps[105][105];
int mem[105][105];
int dfs(int nowx,int nowy);
main(){
  while(1){
    cin>>w>>h;
    if(w==0&&h==0)break;
    cin>>sx>>sy>>gx>>gy;
    cin>>n;
    memset(maps,0,sizeof(maps));
    memset(mem,0,sizeof(maps));
    for(int i=0;i<n;i++){
      cin>>c>>d>>x>>y;
      for(int i=0;i<4;i++){
	if(d==0){
	  maps[y][x+i]=c;
	  maps[y+1][x+i]=c;
	}
	else{
	  maps[y+i][x]=c;
	  maps[y+i][x+1]=c;
	}
      }
    }
    /*
    for(int i=1;i<=h;i++){
      for(int j=1;j<=w;j++){
	cout<<maps[i][j]<<" ";
      }
      cout<<endl;
    }
    */
    color=maps[sy][sx];
    if(dfs(sx,sy)==1){
      cout<<"OK"<<endl;
    }
    else{
      cout<<"NG"<<endl;
    }
  }
}
int dfs(int nowx,int nowy){
  int check=0;
  if(nowx==gx&&nowy==gy){
    return 1;
  }
  else{
    for(int i=0;i<4;i++){
      if(nowx+dx[i]>=1&&nowx+dx[i]<=w&&nowy+dy[i]>=1&&nowy+dy[i]<=h&&maps[nowy+dy[i]][nowx+dx[i]]==color&&mem[nowy+dy[i]][nowx+dx[i]]==0){
	mem[nowy+dy[i]][nowx+dx[i]]=1;
	check=max(dfs(nowx+dx[i],nowy+dy[i]),check);
      }
    }
    return check;
  }
}
  