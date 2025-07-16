#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define F first
#define S second 
using namespace std;
typedef pair<int,int> P;
int w,h,sx,sy,gx,gy,fc;
int imap[110][110];
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
bool found;
void Init(){
  for(int i=0;i<110;i++){
    for(int j=0;j<110;j++){
      imap[i][j] = -1;
    }
  }
}

void display(){
 for(int i=0;i<=h;i++){
      for(int j=0;j<=w;j++){
	printf("%3d ",imap[i][j]);
      }
      cout << endl;
    }
}

void draw(int c,int d,int x,int y){
  int limy,limx;
  limy = d==1?4:2;
  limx = d==1?2:4;
  for(int i=0;i<limy && i<=h;i++){
    for(int j=0;j<limx && j<=w;j++){
      imap[y+i][x+j] = c;
    }
  }
}

void rec(int px,int py){
  if(px == gx && py == gy){
    found = true;
    return;
  }
  for(int i=0;i<4;i++){
    int nx = px+dx[i], ny = py+dy[i];
    if(!found && 0<=nx && nx <=w && 0<=ny && ny<=h && imap[ny][nx] == fc){
      imap[ny][nx] = -1;
      rec(nx,ny);
    }
  }
}


bool isMaze(){
  rec(sx,sy);
  if(found)return true;
  return false;
}

int main(){
  int n,c,d,x,y;
  while(cin >> w >> h  && w && h){
    found = false;
    cin >> sx >> sy;
    cin >> gx >> gy;
    cin >> n;
    Init();
    for(int i=0;i<n;i++){
      cin >> c >> d >> x >> y;
      draw(c,d,x,y);
    }

    
    fc = imap[sy][sx];
    if(fc == -1)cout << "NG" << endl;
    else{
      if(isMaze())cout << "OK" << endl;
      else cout << "NG" << endl;
    }

  }
  return 0;
}