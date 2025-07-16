#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;

#define REP( i, m, n ) for ( int i = (int)( m ); i < (int)( n ); i++ )
#define UREP( i, m, n ) for ( unsigned int i = (unsigned int)( m ); i < (unsigned int)( n ); i++ )

#define ITER( c ) __typeof( (c).begin() )
#define IREP( c, it ) for ( ITER(c) it = c.begin(); it != c.end(); ++it )
#define ALL( c ) (c).begin(), (c).end()
#define RALL( c ) (c).rbegin(), (c).rend()

#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define EXIST( c, e ) ( (c).find( e ) != (c).end() )

#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define DEBUG( x ) cerr << __FILE__ << ":" << __LINE__ << ": " << #x << " = " << ( x ) << endl

int main()
{
	string buffer;

	while ( getline( cin, buffer ) )
	{
		UREP( i, 0, buffer.length() )
		{
			if ( buffer[i] == ',' )
			{
				buffer[i] = ' ';
			}
		}

		vector<int> l;
		l.PB( 0 );
		istringstream iss( buffer );

		REP( i, 0, 10 )
		{
			int input;
			iss >> input;
			l.PB( l.back() + input );
		}

		int v1, v2, res;
		iss >> v1 >> v2;

		UREP( i, 0, 11 )
		{
			if ( l[i] / (double)v1 < ( l.back() - l[i] ) / (double)v2 )
			{
				res = i;
			}
			else
			{
				res++;
				break;
			}
		}

		cout << res << endl;
	}

	return 0;
}