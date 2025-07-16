#include <iostream>
using namespace std;

int F[102][102];

void setblock(int c, int d, int x, int y){
  if(d==0){
    for(int i=0;i<4;i++){
      F[y][x+i]=c;
      F[y+1][x+i]=c;
    }
  }else{
    for(int i=0;i<4;i++){
      F[y+i][x]=c;
      F[y+i][x+1]=c;
    }
  }

}

void DFS(int Y, int X, int c){
  if(F[Y][X]!=c)
    return;

  F[Y][X] = 6;

  DFS(Y-1, X  ,c);
  DFS(Y  , X+1,c);
  DFS(Y+1, X  ,c);
  DFS(Y  , X-1,c);
}

int main(){
  int w,h,xs,ys,xg,yg,n;
  while(true){
  cin >> w >> h;
  for(int i=0;i<h;i++){
   for(int k=0;k<w;k++){
     F[i][k]=-1;
   }
  }
  if(w==0&&h==0){
    break;
  }
  cin >> xs >> ys;
  cin >> xg >> yg;
  cin >> n;
  for(int i=0; i<n; i++){
    int c,d,x,y;
    cin >> c >> d >> x >> y;
    setblock(c,d,x,y);
  }

  DFS(ys,xs,F[ys][xs]);
  if(F[yg][xg]==6){
    cout << "OK" << endl;
  }else{
    cout << "NG" << endl;
  }
}
  return 0;
}

