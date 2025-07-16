#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef vector <int> VI;
typedef set <int> SI;

int get_digit( int n )
{
	int count = 0;
	while ( n >= 10 )
	{
		n /= 10;
		count++;
	}
	return count + 1;
}

int ten_pow( int n )
{
	int answer = 1;
	for ( int i = 0; i < n; i++ ) answer *= 10;
	return answer;
}

int main( void )
{
	int n, k;
	while ( cin >> n >> k && n && k )
	{
		VI cards(n);
		for ( int i = 0; i < n; i++ ) cin >> cards[i];
		sort( cards.begin(), cards.end() );

		SI h;
		for ( int i = 0; i < 1<<n; i++ )
		{
			int cnt = 0;
			for ( int j = 0; j < n; j++ )
			{
				if ( i & 1 << j ) cnt++;
			}
			if ( cnt != k ) continue;

			VI C;
			for ( int j = 0; j < n; j++ )
			{
				if ( i & 1 << j ) C.push_back( cards[j] );
			}

			do {
				int m = 0;
				for ( VI::iterator it = C.begin(); it != C.end(); it++ )
				{
					if ( m == 0 ) m += *it;
					else
					{
						m *= ten_pow( get_digit( *it ) );
						m += *it;
					}
				}
				h.insert( m );
			} while ( next_permutation( C.begin(), C.end() ) );
		}

		cout << h.size() << endl;

	}
	return 0;
}