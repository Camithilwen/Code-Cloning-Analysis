#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>

using namespace std;

typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef istringstream ISS;
typedef ostringstream OSS;

#define REP( i, m, n ) for ( int i = (int)( m ); i < (int)( n ); ++i )
#define EACH( v, c ) for ( auto &v : c )

#define ITER( c ) __typeof( (c).begin() )
#define IREP( c, it ) for ( ITER(c) it = c.begin(); it != c.end(); ++it )
#define ALL( c ) (c).begin(), (c).end()

#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define EXIST( c, e ) ( (c).find( e ) != (c).end() )

#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define DEBUG( x ) cerr << __FILE__ << ":" << __LINE__ << ": " << #x << " = " << ( x ) << endl

const int dir[][2] = {
	1, 0,
	0, 1,
	-1, 0,
	0, -1
};

string solve( VVI board, int sy, int sx, int gy, int gx )
{
	const int H = board.size(), W = board[0].size();

	int color = board[ sy ][ sx ];
	
	queue< PII > que;
	que.push( MP( sy, sx ) );

	set< PII > visited;
	visited.insert( MP( sy, sx ) );

	while ( !que.empty() )
	{
		auto cur = que.front();
		que.pop();

		if ( cur == MP( gy, gx ) )
		{
			return "OK";
		}

		REP( d, 0, 4 )
		{
			auto next = cur;

			next.fst += dir[d][0];
			next.snd += dir[d][1];

			if ( !( 0 <= next.fst && next.fst < H && 0 <= next.snd && next.snd < W ) || 
				 EXIST( visited, next ) ||
				 board[ next.fst ][ next.snd ] != color )
			{
				continue;
			}

			que.push( next );
			visited.insert( next );
		}
	}

	return "NG";
}			

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	while ( true )
	{
		int w, h;
		cin >> w >> h;

		if ( !( w | h ) )
		{
			break;
		}

		int sx, sy, gx, gy, n;
		cin >> sx >> sy >> gx >> gy >> n;

		sx--;
		sy--;
		gx--;
		gy--;

		VVI board( h, VI( w, 0 ) );

		REP( i, 0, n )
		{
			int c, d, x, y;
			cin >> c >> d >> x >> y;

			x--;
			y--;

			if ( !d )
			{
				REP( j, 0, 2 )
				{
					REP( k, 0, 4 )
					{
						board[ y + j ][ x + k ] = c;
					}
				}
			}
			else
			{
				REP( j, 0, 4 )
				{
					REP( k, 0, 2 )
					{
						board[ y + j ][ x + k ] = c;
					}
				}
			}
		}

		cout << solve( board, sy, sx, gy, gx ) << endl;
	}

	return 0;
}