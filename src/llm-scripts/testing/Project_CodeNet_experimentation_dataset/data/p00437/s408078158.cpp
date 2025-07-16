#include <cstdio>
#include <list>

#define N 100

using namespace std;

/** Crazy Motor-Cycle */
struct cmc
{
  int a;
  int b;
  int c;
};

/** Application main entry point. */
int
main (
  int     argc,
  char  * argv[ ]
  )
{
  int i;

  for ( ; ; )
  {
    list<struct cmc> lis;
    int d[ 3 * N ];
    int a, b, c;
    int n;

    scanf ( "%d%d%d", &a, &b, &c );
    if ( !( a | b | c ) ) break ;
    b += a; c += b;
    for ( i = 0; i < c; ++i )
    {
      d[ i ] = 2;
    }

    scanf ( "%d", &n );
    while ( n-- )
    {
      struct cmc t;
      int s;

      scanf ( "%d%d%d%d", &t.a, &t.b, &t.c, &s );
      --t.a; --t.b; --t.c;
      if ( s )
      {
        d[ t.a ] =
        d[ t.b ] =
        d[ t.c ] = 1;
      }
      else
      {
        lis.push_back ( t );
      }
    }

    for ( list<struct cmc>::iterator it = lis.begin ( )
        ; it != lis.end ( ); )
    {
      if ( ( d[ it->a ] == 2 && d[ it->b ] == 1 && d[ it->c ] == 1 )
        || ( d[ it->a ] == 1 && d[ it->b ] == 2 && d[ it->c ] == 1 )
        || ( d[ it->a ] == 1 && d[ it->b ] == 1 && d[ it->c ] == 2 ) )
      {
        if      ( d[ it->a ] == 2 ) d[ it->a ]  = 0;
        else if ( d[ it->b ] == 2 ) d[ it->b ]  = 0;
        else                        d[ it->c ]  = 0;
        lis.erase ( it );
        it = lis.begin ( );
      }
      else ++it;
    }

    for ( i = 0; i < c; ++i )
    {
      printf ( "%d\n", d[ i ] );
    }
  }

  return ( 0 );
}