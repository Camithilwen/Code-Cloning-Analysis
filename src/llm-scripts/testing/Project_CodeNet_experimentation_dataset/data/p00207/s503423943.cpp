#include <iostream>
using namespace std;

int f[102][102];

bool dfs(int ys,int xs,int yg,int xg,int c){
  if(f[ys][xs]!=c)return 0;

  if(ys==yg && xs==xg)return 1;;

  f[ys][xs]=0;

  bool flag=0;
  flag += dfs(ys+1,xs,yg,xg,c);
  flag += dfs(ys-1,xs,yg,xg,c);
  flag += dfs(ys,xs+1,yg,xg,c);
  flag += dfs(ys,xs-1,yg,xg,c);
  return flag;
}

void set(int c,bool d,int x,int y){
  if(d==0){
    for(int i=0; i<4; i++){
      f[y][x+i]=c;
      f[y+1][x+i]=c;
    }
  }else if(d==1){
    for(int i=0; i<4; i++){
      f[y+i][x]=c;
      f[y+i][x+1]=c;
    }
  }
}
;
int main(){
  while(1){

  int w,h;
  cin >> w >> h;
  if(w==0 && h==0)break;

  int xs,ys;
  cin >> xs >> ys;
  int xg,yg;
  cin >> xg >> yg;
  int n;
  cin >> n;

  for(int i=0; i<n; i++){
    bool d;
    int c,x,y;
    cin >> c >> d >> x >> y;
    set(c,d,x,y);
  }

  if(dfs(ys,xs,yg,xg,f[ys][xs])){
    cout << "OK\n";
  }else{
    cout << "NG\n";
  }
  }

  return 0;
}
