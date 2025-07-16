#include<iostream>
#include<stdio.h>
using namespace std ;

int n , m ;
int data[101][101][2] ;

void f(){
	for( int k=1 ; k<=m ; k++ ){
		for( int i=1 ; i<=m ; i++ ){
			for( int j=1 ; j<=m ; j++ ){
				if( data[i][j][0] > data[i][k][0] + data[k][j][0] ){
					data[i][j][0] = data[i][k][0] + data[k][j][0] ;
				}
				if( data[i][j][1] > data[i][k][1] + data[k][j][1] ){
					data[i][j][1] = data[i][k][1] + data[k][j][1] ;
				}
			}
		}
	}
}

int main(){
	
	int a , b ;
	int k , r ;
	
	while(1){
		cin >> n >> m ;
		if( n==0 && m==0 ) break ;
		
		for( int i=0 ; i<101 ; i++ ){
			for( int j=0 ; j<101 ; j++ ){
				data[i][j][0] = 100000000 ;
				data[i][j][1] = 100000000 ;
			}
			data[i][i][0] = 0 ;
			data[i][i][1] = 0 ;
		}
		
		for( int i=0 ; i<n ; i++ ){
			cin >> a >> b ;
			cin >> data[a][b][0] >> data[a][b][1] ;
			data[b][a][0] = data[a][b][0] ;
			data[b][a][1] = data[a][b][1] ;
		}
		
		f() ;
		
		/*for( int i=1 ; i<m ; i++ ){
			for( int j=1 ; j<m ; j++ ){
				printf("data[%d][%d][0] = %d\n" ,i ,j ,data[i][j][0] ) ;
				printf("data[%d][%d][1] = %d\n" ,i ,j ,data[i][j][1] ) ;
			}
		}*/
		
		cin >> k ;
		//cout << "k=" << k << endl ;
		
		for( int i=0 ; i<k ; i++ ){
			cin >> a >> b >> r ;
			cout << data[a][b][r] << endl ;
		}
	}
	
return 0 ;
}