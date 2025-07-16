#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define rep(i,n) for (int i=0;i<(n);i++)
#define Graph vector<vector<int>>

int main() {
  
  int H,W;
  scanf("%d%d",&H,&W);

  Graph A( H , vector<int> (W,0) );
  Graph count( H , vector<int> (W,0) );
  queue< pair<int,int> > que;

  rep(y,H){
    rep(x,W){

      char a;
      cin >> a;
      if( a == '#' ){
       A[y][x]=1;
       que.push( make_pair(x,y) );
      }
   
    }
  }

  vector<int> dx = { 0, 1, 0, -1 };
  vector<int> dy = { 1, 0, -1, 0 };
  int res = 0;
  
  while( !que.empty() ){

        pair<int,int> v = que.front();
        que.pop();

        int x = v.first;
        int y = v.second;

        rep(i,4) {

            int nv_x = x + dx[i];
            int nv_y = y + dy[i];

            //通れるか？
            if ( nv_x < 0 || nv_x >= W ) continue;
            if ( nv_y < 0 || nv_y >= H ) continue;
            if ( A[nv_y][nv_x] == 1 ) continue;
            
            A[nv_y][nv_x] = 1;
            count[nv_y][nv_x] = count[y][x] +1;
            res = count[nv_y][nv_x];
            que.push( make_pair(nv_x,nv_y) );

        }
    }
   
  printf("%d\n", res );
  return 0;

}
