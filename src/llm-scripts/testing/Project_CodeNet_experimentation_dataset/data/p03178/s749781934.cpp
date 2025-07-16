#include<bits/stdc++.h>
using namespace std ;

// MY TOOLS
#define let long long int
#define async ios_base::sync_with_stdio(false);cin.tie(NULL);

//


int dp[10001][101][2] ;
int mod = 1e9 + 7 ;
void self_add( int &a, int b ){
	a += b ;
	if( a >= mod ) a -= mod ;
}
int SIZE ;
int generate_top_down( string num, int idx, int sum, int D, int bound ){
	if( idx == SIZE ) return ( sum % D == 0 ) ;
	int &check = dp[idx][sum][bound] ;
	if( check != -1 ) return check ;
	int N = ( num[idx]-'0' ) ;
	int up_to = ( bound == 1 ) ? N : 9 ;
	int payload = 0, new_bound ;
	for( int digit = 0 ; digit <= up_to ; digit++ ){
		new_bound = ( digit == N ) ? bound : 0 ;
		self_add( payload, generate_top_down( num, idx+1, (sum+digit)%D, D, new_bound ) ) ; 
	}
	return check = payload ; 
}



// main
// write your code here
int main(){
	async ;
	memset( dp, -1, sizeof(dp) ) ;
	string K ; int D ;
	cin >> K >> D ;
	SIZE = K.size() ;
	int ans = generate_top_down( K, 0, 0, D, 1 ) - 1 ;
	if( ans == -1 ) {
		cout << mod - 1 ;
	}
	else{
		cout << ans ;
	}
    return 0 ;
}
