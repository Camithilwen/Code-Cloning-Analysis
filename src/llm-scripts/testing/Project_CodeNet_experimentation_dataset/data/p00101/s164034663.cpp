#include<bits/stdc++.h>
using namespace std ;

main(){
	int n ;
	string s ;
	char c[] = {'H','o','s','h','i','n','o'} ;
	
	cin >> n ;
	for( int k=0 ; k<=n ; k++ ){
		getline( cin , s ) ;
		
		for( int i=0 ; i<s.size() ; i++ ){
			int cnt = 0 ;
			if( s[i] == 'H' ){
				for( int j=0 ; j<s.size() && j<7 ; j++ ){
					if( s[i+j] == c[j] ) cnt++ ;
					else break ;
				}
				if( cnt==7 ) s[i+6] = 'a' ;
			}
		}
		
		if( k ) cout << s << endl ;
	}
}