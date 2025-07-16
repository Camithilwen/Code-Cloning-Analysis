#include <cstdio>
#include <functional>
#include <algorithm>

using namespace std;

/** Application main entry point. */
int main (
  int     argc,
  char  * argv[ ]
  )
{
  int d[ 5 ];
  int i;

  while ( scanf ( " %d,%d,%d,%d,%d"
                , d, d + 1, d + 2, d + 3, d + 4 ) == 5 )
  {
    int c[ 13 ] = { 0 };

    sort ( d, d + 5 );
    for ( i = 0; i < 5; ++i )
    {
      ++c[ d[ i ] - 1 ];
    }
    sort ( c, c + 13, greater< int > ( ) );

    if ( c[ 0 ] == 4 )
    {
      puts ( "four card" );
    }
    else if ( c[ 0 ] == 3 && c[ 1 ] == 2 )
    {
      puts ( "full house" );
    }
    else if ( ( d[ 0 ] == d[ 1 ] - 1
             && d[ 0 ] == d[ 2 ] - 2
             && d[ 0 ] == d[ 3 ] - 3
             && d[ 0 ] == d[ 4 ] - 4 )
           || ( d[ 0 ] == 1
             && d[ 1 ] == 10
             && d[ 2 ] == 11
             && d[ 3 ] == 12
             && d[ 4 ] == 13 ) )
    {
      puts ( "straight" );
    }
    else if ( c[ 0 ] == 3 )
    {
      puts ( "three card" );
    }
    else if ( c[ 0 ] == 2 && c[ 1 ] == 2 )
    {
      puts ( "two pair" );
    }
    else if ( c[ 0 ] == 2 )
    {
      puts ( "one pair" );
    }
    else
    {
      puts ( "null" );
    }
  }

  return ( 0 );
}