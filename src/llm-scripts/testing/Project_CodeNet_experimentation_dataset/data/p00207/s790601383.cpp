#include <iostream>

using namespace std;

int table[100][100];
int memo[100][100];

int w, h;
int xs, ys, xg, yg;
int n;

void solve(int xs, int ys, int c)
{
	if( memo[xs][ys] ) {
		return;
	}

	if( !( 0 < xs && xs < w+1 && 0 < ys && ys < h+1 && table[xs][ys] == c ) ) {
		memo[xs][ys] = 1;
		return;
	}
	
	if( xs == xg && ys == yg ) {
		memo[xs][ys] = 1;
		cout << "OK" << endl;
		throw "OK";
	}

	memo[xs][ys] = 1;	

	solve(xs+1, ys, c);
	solve(xs, ys+1, c);	
	solve(xs-1, ys, c);
	solve(xs, ys-1, c);

	return;
}

int main(int argc, char* argv[])
{
	while(1) {

		for( int i = 0; i < 100; i++ ) {
			for( int j = 0; j < 100; j++ ) {
				table[i][j] = 0;
				memo[i][j] = 0;
			}
		}		

		cin >> w >> h;

		if( w == 0 && h == 0 )
			break;
			
		cin >> xs >> ys;
		cin >> xg >> yg;
		cin >> n;

		for( int i = 0; i < n; i++ ) {

			int c; cin >> c;
			int d; cin >> d;
			int x, y; cin >> x >> y;

			if( d == 0 ) {

				table[x][y] = c;
				table[x][y+1] = c;

				table[x+1][y] = c;
				table[x+1][y+1] = c;

				table[x+2][y] = c;
				table[x+2][y+1] = c;

				table[x+3][y] = c;
				table[x+3][y+1] = c;																
				

			} else {

				table[x][y] = c;
				table[x+1][y] = c;

				table[x][y+1] = c;
				table[x+1][y+1] = c;

				table[x][y+2] = c;
				table[x+1][y+2] = c;
				
				table[x][y+3] = c;
				table[x+1][y+3] = c;								
			}
		}

		try {
			if( table[xs][ys] )
				solve(xs, ys, table[xs][ys]);
			cout << "NG" << endl;
		} catch(...) {
		}
	}

    return 0;
}