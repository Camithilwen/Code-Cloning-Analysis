#include "bits/stdc++.h"
using namespace std;

#define FOR( i, m, n )	for( int (i) = (m); (i) < (n); i++ )
#define REP( i, n )		FOR( i, 0, n )
#define ALL( x )		(x).begin(), (x).end()

void shellSort( vector<int>& a );
void insertSort( vector<int>& a, int h );
void printArray( vector<int>& a );

int main() {
	int n; cin >> n;
	vector<int> a( n );
	REP( i, n ) cin >> a[i];

	shellSort( a );
	printArray( a );

}


void shellSort( vector<int>& a ) {
	int h = 1, h_tmp, h_cnt = 0;
	for( h_tmp = 1; h_tmp < a.size(); h_tmp = h_tmp * 3 + 1 ) {
		h = h_tmp;
		h_cnt++;
	}

	cout << ( a.size() == 1 ? h_cnt + 1 : h_cnt ) << endl;
	
	while( h > 0 ) {
		if( h / 3 != 0 ) cout << h << " ";
		else			 cout << h << endl;
		insertSort( a, h );
		h /= 3;
	}
}

void insertSort( vector<int>& a, int h ) {
	static int cnt = 0;
	int tmp, j;
	FOR( i, h, a.size() ) {
		tmp = a[i];
		for( j = i; j >= h && a[j - h] > tmp; j -= h ) {
			cnt++;
			a[j] = a[j - h];
		}
		a[j] = tmp;
	}

	if( h == 1 ) cout << cnt << endl;
}

void printArray( vector<int>& a ) {
	REP( i, a.size() ) cout << a[i] << endl;
}
