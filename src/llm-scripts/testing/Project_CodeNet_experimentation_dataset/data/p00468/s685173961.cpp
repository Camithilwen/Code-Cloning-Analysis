#include <iostream>
#include <vector>
using namespace std;

typedef vector <bool> VB;
typedef vector <VB> VVB;

int main( void )
{
	int n, m;
	while ( cin >> n >> m && n && m )
	{
		VVB G( n+1, VB( n+1, false ) );
		for ( int i = 0; i < m; i++ )
		{
			int a, b; // a-bツづ債友ツ達
			cin >> a >> b;
			G[a][b] = G[b][a] = true;
		}

		VB F( n+1, false );
		for ( int i = 0; i <= n; i++ )
		{
			if ( G[1][i] )
			{
				F[i] = true;
			}
		}

		VB R( n+1, false );
		for ( int i = 0; i <= n; i++ )
		{
			if ( F[i] == false ) continue;
			for ( int j = 0; j <= n; j++ )
			{
				if ( j == 1 ) continue;
				if ( G[i][j] )
				{
					R[j] = true;
				}
			}
		}

		int answer = 0;
		for ( int i = 0; i <= n; i++ )
		{
			if ( F[i] || R[i] )
			{
				answer++;
			}
		}

		cout << answer << endl;

	}
	return 0;
}