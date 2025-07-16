#include<algorithm>
#include<cstdio>


using namespace std ;


int sports[ 1000 + 1 ] ;

int cnt[ 1000 + 1 ] ;
int CNT[ 1000 + 1 ] ;

int cmp ;

int N ,M ;


int ans()
{
	sort( cnt + 1 ,cnt + N + 1 ) ;

	return ( find_if( CNT ,CNT + N + 1 ,[]( int cmpair ){ return cmpair == cnt[ N ] ; } ) - CNT ) ;
}



int main( void )
{
	scanf( "%d %d" ,&N ,&M ) ;

	int i ;
	for( i = 1 ; i <= N ; ++i )
	{
		scanf( "%d" ,&cmp ) ;

		sports[ i ] = cmp ;
	}

	for( i = 0 ; i < M ; ++i )
	{
		scanf( "%d" ,&cmp ) ;

		++cnt[ ( find_if( sports + 1 ,sports + N + 1 ,[]( int cmpair){ return cmp >= cmpair ; } ) - sports ) ] ;
	}


	copy( cnt ,cnt + N + 1 ,CNT ) ;


	printf( "%d\n" ,ans() ) ;


	return 0 ;
}