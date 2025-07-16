#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int l, r, n , m =0;
	
	cin>>n>>m;
	int mi= n; 
	int ma=-1;
	
	for(int i=0; i<m ; i++){
		
		cin>>l>>r;
	
		if(ma < l)ma= l;
		if(mi > r)mi=r;
		
		
	
		
	}
	
	cout<<max(mi-ma+1,0);
	
	return 0;
}