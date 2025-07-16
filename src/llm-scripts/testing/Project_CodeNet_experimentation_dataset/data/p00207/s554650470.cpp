#include <iostream>
#include <vector>
#include <string>
using namespace std;



typedef vector<vector<int> > Matrix;
int w,h,xs,ys,xg,yg,n,color;
string res = "NG";
Matrix board(101, vector<int>(101,0));

void write(Matrix &board,int c, int d, int x, int y){
  int width,length;
  if(d == 0){ width = 4; length =2; }
  if(d == 1){ width = 2; length =4; }
  for(int i=0; i<width; ++i){
    for(int j=0; j<length; ++j)
      board[x+i][y+j]=c;
  }
}
void func(Matrix &board,int nx,int ny){
  if(board[nx][ny] == 0){
    res = "NG";
    return;
  }
  if( nx==xg && ny==yg){
    res = "OK";
    return;
  }
  board[nx][ny] = 0;
  if( 0<=nx-1 && color==board[nx-1][ny])
    func(board,nx-1,ny);
  if( 0<=ny-1 && color==board[nx][ny-1])
    func(board,nx,ny-1);
  if( nx+1<=w && color==board[nx+1][ny])
    func(board,nx+1,ny);
  if( ny+1<=h && color==board[nx][ny+1])
    func(board,nx,ny+1);
}


int main(void){
  int c,d,x,y;
  while(cin >> w >> h,w||h){
    if( w==0 && h==0) return 0;
    res = "NG";
    cin >> xs >> ys >> xg >> yg >> n;
    xs--; ys--; xg--; yg--;
    //    Matrix board(w, vector<int>(h,0));
    for(int i=0; i<n; ++i){
      cin >> c >> d >> x >> y;
      --x; --y;
      write(board,c,d,x,y);
    }
    color = board[xs][ys];
    func(board,xs,ys);
    cout << res << endl;
    //    board.clear();
  }
  return 0;
}
  