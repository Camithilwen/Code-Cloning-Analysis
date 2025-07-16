#include <iostream>
using namespace std;

char solve(int m,int e,int j){
	if( m == 100 || e == 100 || j == 100 )
		return 'A';
	if( (m+e)>=180 || (m+e+j)>=240)
		return 'A';
	if( (m+e+j)>=210 || ( (m+e+j)>=150 && (m>=80||e>=80) ) )
		return 'B';
	return 'C';
}

int main(){
	int n,m,e,j;
	while( cin >> n , n ){
		for(int i=0 ; i<n ; ++i ){
			cin >> m >> e >> j;
			cout << solve(m,e,j) << endl;
		}
	}
}