#include <bits/stdc++.h>
using namespace std;

const int MaxM = 110;
int N, M, A[ MaxM ], Sum, Num;

int main() {
	scanf( "%d%d", &N, &M );
	for( int i = 1; i <= M; ++i ) scanf( "%d", &A[ i ] );
	for( int i = 1; i <= M; ++i ) Sum += A[ i ];
	if( Sum != N ) {
		printf( "Impossible" );
		return 0;
	}
	for( int i = 1; i <= M; ++i )
		if( A[ i ] % 2 == 1 ) 
			++Num;
	if( Num > 2 ) {
		printf( "Impossible" );
		return 0;
	}
	if( Num == 0 ) {
		for( int i = 1; i <= M; ++i ) printf( "%d ", A[ i ] ); printf( "\n" );
		printf( "%d\n", M + 1 );
		printf( "%d ", A[ 1 ] - 1 );
		for( int i = 2; i <= M; ++i ) printf( "%d ", A[ i ] ); 
		printf( "%d\n", 1 );
		return 0;
	}
	if( Num == 2 ) {
		int a, b;
		for( int i = 1; i <= M; ++i )
			if( A[ i ] % 2 == 1 ) {
				a = A[ i ];
				break;
			}
		for( int i = M; i >= 1; --i ) 
			if( A[ i ] % 2 == 1 ) {
				b = A[ i ];
				break;
			}
		printf( "%d ", a );
		for( int i = 1; i <= M; ++i ) 
			if( A[ i ] % 2 == 0 ) 
				printf( "%d ", A[ i ] );
		printf( "%d\n", b );
		if( a > 1 ) {
			printf( "%d\n", M );
			printf( "%d ", a - 1 );
			for( int i = 1; i <= M; ++i )
				if( A[ i ] % 2 == 0 ) 
					printf( "%d ", A[ i ] );
			printf( "%d\n", b + 1 );
			return 0;
		}
		printf( "%d\n", M - 1 );
		for( int i = 1; i <= M; ++i ) 
			if( A[ i ] % 2 == 0 ) 
				printf( "%d ", A[ i ] );
		printf( "%d\n", b + 1 );
		return 0;
	}
	int t = 0;
	for( int i = 1; i <= M; ++i ) 
		if( A[ i ] % 2 == 1 ) {
			t = A[ i ];
			break;
		}
	printf( "%d ", t );
	for( int i = 1; i <= M; ++i ) 
		if( A[ i ] % 2 == 0 ) 
			printf( "%d ", A[ i ] );
	printf( "\n" );
	if( t > 1 ) {
		printf( "%d\n", M + 1 );
		printf( "%d ", t - 1 );
		for( int i = 1; i <= M; ++i ) 
			if( A[ i ] % 2 == 0 )
				printf( "%d ", A[ i ] );
		printf( "%d\n", 1 );
	} else {
		printf( "%d\n", M );
		for( int i = 1; i <= M; ++i ) 
			if( A[ i ] % 2 == 0 ) 
				printf( "%d ", A[ i ] );
		printf( "%d\n", 1 );
	}
	return 0;
}