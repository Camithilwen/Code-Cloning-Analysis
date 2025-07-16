#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> VI;
typedef vector <VI> VVI;

const int dx[5] = { 0, 0, 0, 1, -1 };
const int dy[5] = { 0, 1, -1, 0, 0 };

int w, h;
int sx, sy, gx, gy;
VVI M;
int answer;

//==================================================
// Tõ
//==================================================
void dfs( int x, int y, int a, int d )
{
	if ( d > 10 ) return;

	if ( M[y][x] == 3 )
	{
		if ( answer == -1 )
			answer = d;
		else
			answer = min( answer, d );
	}
	if ( a > 0 )
	{
		int nx = x + dx[a];
		int ny = y + dy[a];
		if ( nx < 0 || nx >= w || ny < 0 || ny >= h )
			return;
		if ( M[ny][nx] == 1 )
		{
			M[ny][nx] = 0;
			dfs( x, y, 0, d );
			M[ny][nx] = 1;
		}
		else
			dfs( nx, ny, a, d );
	}
	else
	{
		for ( int i = 1; i < 5; i++ )
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ( nx < 0 || nx >= w || ny < 0 || ny >= h )
				continue;
			if ( M[ny][nx] == 0 || M[ny][nx] == 3 )
			{
				dfs( nx, ny, i, d+1 );
			}
		}
	}

}

int main( void )
{
	while ( cin >> w >> h && w && h )
	{
		//==================================================
		// Ï
		//==================================================
		M = VVI( h, VI( w, 0 ) );
		answer = -1;

		//==================================================
		// }bvÌüÍ
		//==================================================
		for ( int i = 0; i < h; i++ )
		{
			for ( int j = 0; j < w; j++ )
			{
				int& s = M[i][j];
				cin >> s;

				// X^[gES[
				if ( s == 2 )
				{
					sx = j;
					sy = i;
					s  = 0;
				}
				else if ( s == 3 )
				{
					gx = j;
					gy = i;
				}
			}
		}

		//==================================================
		// 
		//==================================================
		dfs( sx, sy, 0, 0 );

		//==================================================
		// oÍ
		//==================================================
		cout << answer << endl;
	}
	return 0;
}