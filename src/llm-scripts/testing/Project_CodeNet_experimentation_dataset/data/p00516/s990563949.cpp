#include<iostream>
using namespace std;

int main(){
	
	int n,m;
	int judge;
	int max=0;
	
	cin >> n >> m ;
	
	int a[n];
	int b[1000]={};
	
	for( int i=0 ; i<n ; i++ ) cin >> a[i] ;
	for( int i=0 ; i<m ; i++ ){
		cin >> judge ;
		for( int j=0 ; j<n ; j++ ){
			if( a[j] <= judge ){
				b[j]++;
				if( max < b[j]) max=b[j];
				break;
			}
		}
	}
	
	for( int i=0 ; i<n ; i++ ){
		if( b[i] == max ){
			cout << i+1 << endl ;
			break;
		}
	}
	
return 0;
}