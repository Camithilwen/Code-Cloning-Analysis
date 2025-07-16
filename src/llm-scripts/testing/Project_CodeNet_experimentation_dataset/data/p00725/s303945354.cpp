#include<iostream>
#include<algorithm>
using namespace std ;

int W , H , sx , sy ;
int ans ;
char p ;
int dx[] = {-1,0,1,0} ;
int dy[] = {0,1,0,-1} ;
int table[23][23] ;

void DFS( int x , int y , int cnt ){
	if( cnt+1 >= ans ) return ;
	
	for( int i=0 ; i<4 ; i++ ){
		int nx = x + dx[i] , ny = y + dy[i] ;
		
		if( table[ny][nx] == 1 ){ continue ; }
		else { while( table[ny][nx] != 4 ){
			
			if( table[ny][nx] == 1 ){
				table[ny][nx] = 0 ;
				DFS( nx-dx[i] , ny-dy[i] , cnt+1 ) ;
				table[ny][nx] = 1 ;
				break ;
			}
			else if( table[ny][nx] == 3 ){
				ans = min( ans , cnt+1 ) ;
				return ;
			}
			
			nx += dx[i] ;
			ny += dy[i] ;
		}}
	}
	
	return ;
}

int main(){
	
	while( cin >> W >> H , W ){
		for( int i=0 ; i<=H+1 ; i++ ){
			for( int j=0 ; j<=W+1 ; j++ ){
				if( i==0 || j==0 || i==H+1 || j==W+1 ) table[i][j] = 4 ;
				else{ 
					cin >> table[i][j] ;
					if( table[i][j] == 2 ){
						sx = j ; 
						sy = i ;
					}
				}
			}
		}
		
		ans = 11 ;
		DFS( sx , sy , 0 ) ;
		if( ans == 11 ) ans = -1 ;
		cout << ans << endl ;
	}
	
return 0;
}