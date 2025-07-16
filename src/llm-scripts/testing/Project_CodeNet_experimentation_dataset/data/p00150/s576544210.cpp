#include<iostream>
using namespace std ;

int table[10010] = {} ;

void f(){
	table[0] = 1 ;
	table[1] = 1 ;
	for( int i=2 ; i<=10000 ; i++ ){
		if( !table[i] ){
			for( int j=2 ; i*j<=10000 ; j++ ) table[i*j] = 1 ;
		}
	}
}

main(){
	f() ;
	
	int n ;
	while( cin >> n , n ){
		int p = 0 ;
		for( int i=5 ; i<=n ; i++ ){
			if( !table[i] && !table[i-2] ) p = i ;
		}
		
		cout << p-2 << " " << p << endl ;
	}
}