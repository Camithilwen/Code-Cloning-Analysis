#include<iostream>
#include<queue>
#include<cstring>

typedef std::pair<int, int> P;

int w, h;
int field[100][100];
int xs, ys, xg, yg;
int n;
const int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };

int main()
{
	while( std::cin >> w >> h, w | h )
	{
		memset( field, 0, sizeof( field ) );

		std::cin >> xs >> ys >> xg >> yg >> n;
		for( int i = 0; i != n; ++i )
		{
			int c, d, x, y;
			std::cin >> c >> d >> x >> y;
			for( int j = 0; j != 8; ++j )
			{
				int nx = x + ( d ? j % 2 : j / 2 ),
					ny = y + ( d ? j / 2 : j % 2 );

				field[ny-1][nx-1] = c;
			}
		}

		std::queue<P> que;
		int col = field[ys-1][xs-1];
		bool ans = false;
		que.push( P( xs, ys ) );

		while( !que.empty() )
		{
			P p = que.front(); que.pop();
			if( p.first == xg && p.second == yg )
			{
				ans = true;
				break;
			}

			field[p.second-1][p.first-1] = 0;

			for( int i = 0; i != 4; ++i )
			{
				int nx = p.first + dx[i],
					ny = p.second + dy[i];
				
				if( nx > 0 && nx <= w && ny > 0 && ny <= h && field[ny-1][nx-1] && field[ny-1][nx-1] == col )
					que.push( P( nx, ny ) );
			}
		}

		std::cout << ( ans ? "OK" : "NG" ) << std::endl;
	}

	return 0;
}