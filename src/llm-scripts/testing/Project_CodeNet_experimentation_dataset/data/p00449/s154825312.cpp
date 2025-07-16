#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <iterator>

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
#define FOR( v, c ) for ( auto &v : c )

#define EACH( it, c ) for ( auto it = c.begin(); it != c.end(); ++it )
#define ALL( c ) (c).begin(), (c).end()

#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define EXIST( c, e ) ( (c).find( e ) != (c).end() )

#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define DEBUG( x ) cerr << __FILE__ << ":" << __LINE__ << ": " << #x << " = " << ( x ) << endl

const int INF = INT_MAX / 2;

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	while ( true )
	{
		int n, k;
		cin >> n >> k;

		if ( !( n | k ) )
		{
			break;
		}

		VVI G( n, VI( n, INF ) );
		REP( i, 0, n )
		{
			G[i][i] = 0;
		}

		REP( i, 0, k )
		{
			int q, a, b, e;
			cin >> q;
			switch ( q )
			{
				case 0:
					cin >> a >> b;
					a--;
					b--;
					cout << ( G[a][b] == INF ? -1 : G[a][b] ) << endl;
					break;
				case 1:
					cin >> a >> b >> e;
					a--;
					b--;
					G[a][b] = min( G[a][b], e );
					G[b][a] = min( G[b][a], e );

					REP( i, 0, n )
					{
						G[i][a] = min( G[i][a], G[i][b] + G[b][a] );
						G[i][b] = min( G[i][b], G[i][a] + G[a][b] );
					}

					REP( i, 0, n )
					{
						REP( j, 0, n )
						{
							G[i][j] = min( G[i][j], min( G[i][a] + G[a][j], G[i][b] + G[b][j] ) );
						}
					}
			}
		}
	}

	return 0;
}