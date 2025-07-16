#include <iostream>
#include <algorithm>

#define MAXN 100
#define WHITE 0
#define BLACK 1

using namespace std;

int D[MAXN][MAXN];

bool judge ( int color, int i, int j)
{
  if ( i-1 >= 0 && j-1 >= 0 && D[i-1][j-1] == color ) return false;
  if ( i-1 >= 0 && D[i-1][j] == color ) return false;
  if ( i-1 >= 0 && j+1 < MAXN && D[i-1][j+1] == color ) return false;
  if ( i+1 < MAXN && j-1 >= 0 && D[i+1][j-1] == color ) return false;
  if ( i+1 < MAXN && D[i+1][j] == color ) return false;
  if ( i+1 < MAXN && j+1 < MAXN && D[i+1][j+1] == color ) return false;
  if ( j-1 >= 0 && D[i][j-1] == color ) return false;
  if ( j+1 < MAXN && D[i][j+1] == color ) return false;

  return true;
}

int main()
{
  int A,B;
  int cnt;

  cin >> A >>B;

  for ( int i = 0; i < 50; ++i ) {
    for ( int j = 0; j < MAXN; ++j ) D[i][j] = BLACK;
  }

  cnt = 1;
  for ( int i = 0; i < 49; ++i ) {
    for ( int j = 0; j < MAXN; ++j ) {
      if ( cnt == A ) break;
      if ( judge(WHITE, i,j) ) {
        D[i][j] = WHITE;
        ++cnt;
      }
    }
  }

  cnt = 1;
  for ( int i = 51; i < MAXN; ++i ) {
    for ( int j = 0; j < MAXN; ++j ) {
      if ( cnt == B ) break;
      if ( judge(1, i, j) ) {
        D[i][j] = 1;
        ++cnt;
      }
    }
  }


  cout << " " << MAXN << " " << MAXN <<"\n";
  for ( int i = 0; i < MAXN; ++i ) {
    for ( int j = 0; j < MAXN; ++j ) {
      if ( D[i][j] ) cout << '#';
      else cout << '.';
    }
    cout << "\n";
  }
}
