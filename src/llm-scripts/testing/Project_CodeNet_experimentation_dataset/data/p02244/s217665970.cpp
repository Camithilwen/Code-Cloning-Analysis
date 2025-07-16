#include <cstdio>
#include <vector>
#include <map>
using namespace std;
#define N 8

int board[N][N];
vector< pair<int,int> > queen;
vector< pair<int,int> > sol_queen;

bool check(int k, int x, int y)
{
  for(int i=0;i<k;i++)
  {
    int tx = queen[i].first;
    int ty = queen[i].second;
    if(x == tx) return false;
    if(y == ty) return false;
    if((x-tx)*(x-tx) == (y-ty)*(y-ty)) return false;
  }
  return true;
}

/*
void printQueen() {
  for(int i=0;i<N;i++) {
    printf("%d : (%d,%d)\n",i,queen[i].first,queen[i].second);
  }
}
*/

void setQueen(int k,bool is_solution) {
  if(k == N && !is_solution) {
    is_solution = true;
    sol_queen = queen;
    return;
  }
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      if(check(k,i,j)) {
        queen[k] = make_pair(i,j);
        setQueen(k+1,is_solution);
      }
    }
  }
}

int main() {
  // initialize
  queen.resize(N,make_pair(-1,-1));

  int k,r,c;
  scanf("%d",&k);
  for(int i=0;i<k;i++) {
    scanf("%d %d",&r,&c);
    queen[i] = make_pair(r,c);
  }

  setQueen(k,false);

  for(int k=0;k<N;k++) {
    board[sol_queen[k].first][sol_queen[k].second] = 1;
  }
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      if(board[i][j] == 0)
        printf(".");
      else
        printf("Q");
    }
    printf("\n");
  }
}