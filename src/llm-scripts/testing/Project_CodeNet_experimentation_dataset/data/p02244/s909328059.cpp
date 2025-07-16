#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <sstream>
#include <string>
#include <utility>
#include <map>
#include <memory>
#include <set>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <array>

using namespace std;

class EightQueen
{
public:
  vector<vector<int>> bd;
  EightQueen(){}
  EightQueen( int n ) : bd(n, vector<int>(n)) {}
  int solve();
  bool dfs( int r );
  bool conflict( int r, int c );
};

bool EightQueen::conflict( int r, int c )
{
  for ( auto i = 0; i < 8; ++i )
    for ( auto j = 0; j < 8; ++j )
      {
        if ( bd[i][j] == 0 ) continue;

        if ( i == r ) return false;
        if ( j == c ) return false;
        if ( r - c == i - j ) return false;
        if ( r + c == i + j ) return false;
      }
  return true;
}

bool EightQueen::dfs( int r )
{
  if ( r == 8 ) return true;

  for ( auto c = 0; c < 8; ++c )
    {
      if ( bd[r][c] == 2 )
        {
          if ( dfs( r + 1 ) ) return true;
        }
      else
        {
          if ( conflict( r, c ) )
            {
              bd[r][c] = 1;
              if ( dfs( r + 1 ) ) return true;
              bd[r][c] = 0;
            }
        }
    }
  
  return false;
}

int EightQueen::solve()
{
  dfs( 0 );

  for ( auto r = 0; r < 8; ++r )
    {
      for ( auto c = 0; c < 8; ++c )
        {
          if ( bd[r][c] )
            cout << "Q";
          else
            cout << ".";
        }
      cout << endl;
    }
      
  return 0;
}

int main()
{
  int n;
  cin >> n;

  EightQueen eq( 8 );

  for ( auto i = 0; i < n; ++i )
    {
      int r, c;
      cin >> r >> c;
      eq.bd[r][c] = 2;
    }
  
  eq.solve();

  return 0;
}