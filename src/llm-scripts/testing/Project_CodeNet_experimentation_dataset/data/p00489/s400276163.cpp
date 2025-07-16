#include<iostream>
using namespace std ;
int main()
{
	int n ;
	int a ,b ,c ,d ;
	cin >> n ;
	int t[ 101 ] = { 0 } ;
	for( int i = 0 ; i < n * ( n - 1 ) / 2  ; i++ )
	{
		cin >> a >> b >> c >> d ;
		
		if( c == d )
		{
			t[ a ]++ ;
			t[ b ]++ ;
			continue ;
		}
		t[ c > d ? a : b ] += 3 ;
	}
	for( int i = 1 ; i <= n ; i++ )
	{
		int juni = 1 ;
		for( int j = 1 ; j <= n ; j++ )
		{
			if( i == j )
				continue ;
			if( t[ i ] < t[ j ] )
			{
				juni++ ;
			}
		}
		cout << juni << endl ;
	}
	return 0 ;
}