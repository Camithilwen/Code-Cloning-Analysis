#include<iostream>
#include<algorithm>
using namespace std;

int w,h;
int ans;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

bool canmove(int x,int y){
  return (0 <= x && x < w && 0 <= y && y < h);
}

struct Map{
  int map[20][20];
  int s,g;
  int cnt;
  int cur;
  Map(int m[20][20]){
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	map[i][j]=m[i][j];
	if(m[i][j]==2) s=i*32+j;
	if(m[i][j]==3) g=i*32+j;
      }
    }
    cnt=0;
    cur=s;
  }
  Map(int m[20][20],int curling,int _cnt){
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	map[i][j]=m[i][j];
	if(m[i][j]==2) s=i*32+j;
	if(m[i][j]==3) g=i*32+j;
      }
    }
    cnt=_cnt;
    cur=curling;
  }
  Map move(int direc){
    Map m(map,cur,cnt+1);
    int y=cur/32,x=cur%32;
    if(canmove(x+dx[direc],y+dy[direc]) && map[y+dy[direc]][x+dx[direc]]==1){
      m.cnt=100;
      return m;
    }
    int k=1;
    while(true){
      bool b=canmove(x+k*dx[direc],y+k*dy[direc]);
      int num=map[y+k*dy[direc]][x+k*dx[direc]];
      if(b && num==3){
	m.cur=g;
	break;
      }
      else if(b && num!=1) k++;
      else if(b && num==1){
	m.map[y+k*dy[direc]][x+k*dx[direc]]=0;
	k--;
	m.cur=(y+k*dy[direc])*32+x+k*dx[direc];
	break;
      }else{
	m.cnt=100;
	break;
      }
    }
    // cout<<m.cnt<<endl;
    return m;
  }
};

void dfs(Map m){
  if(m.cnt > 10) return;
  if(m.cnt >= ans) return; 
  if(m.cur == m.g){
    ans = min(m.cnt,ans);
    return;
  }
  for(int i=0;i<4;i++){
    dfs(m.move(i));
  }
}

int main(){
  while(cin>>w>>h,w+h){
    int map[20][20];
    ans=1000;
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin>>map[i][j];
    Map m(map);
    dfs(m);
    if(ans == 1000) cout<<-1<<endl;
    else cout<<ans<<endl;
  }
  return 0;
}