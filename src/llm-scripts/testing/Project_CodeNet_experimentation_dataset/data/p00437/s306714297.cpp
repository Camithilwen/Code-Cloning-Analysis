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

VI solve( int a, int b, int c )
{
	const int N = a + b + c;
	VI parts( N, 2 );

	int m;
	cin >> m;

	VVI nums( m, VI( 3 ) );
	VI rs( m );

	REP( i, 0, m )
	{
		REP( j, 0, 3 )
		{
			cin >> nums[i][j];
			nums[i][j]--;
		}
		cin >> rs[i];

		if ( !rs[i] )
		{
			continue;
		}

		REP( j, 0, 3 )
		{ 
			parts[ nums[i][j] ] = 1;
		}
	}

	REP( i, 0, m )
	{
		if ( rs[i] )
		{
			continue;
		}

		int count = 0;
		REP( j, 0, 3 )
		{
			count += parts[ nums[i][j] ] == 1;
		}

		if ( count != 2 )
		{
			continue;
		}

		REP( j, 0, 3 )
		{
			if ( parts[ nums[i][j] ] == 1 )
			{
				continue;
			}
			parts[ nums[i][j] ] = 0;
		}
	}

	return parts;
}

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );
	
	while ( true )
	{
		int a, b, c;
		cin >> a >> b >> c;

		if ( !( a | b | c ) )
		{
			break;
		}

		VI res( solve( a, b, c ) );
		FOR( r, res )
		{
			cout << r << endl;
		}
	}

	return 0;
}