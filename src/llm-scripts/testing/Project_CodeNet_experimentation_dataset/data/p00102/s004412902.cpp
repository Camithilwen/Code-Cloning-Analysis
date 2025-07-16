#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	
	while( cin >> n &&  n ){
		int* table = new int[ (n+1) * (n+1) ]();
		for( int i = 0; i < n; ++i ){
			int sum_col = 0;
			for( int j = 0; j < n; ++j ){
				int d;
				cin >> d;
				table[ i * (n+1) + j ] = d;
				table[ i * (n+1) + n ] += d;
				table[ n * (n+1) + j ] += d;
				table[ n * (n+1) + n ] += d;
			}
		}

		for( int i = 0; i < n+1; ++i ){
			for( int j = 0; j < n+1; ++j ){
				cout.width( 5 );
				cout << table[ i * (n+1) + j ];
			}
			cout << endl;
		}

		delete[] table;
	}
	return 0;
}