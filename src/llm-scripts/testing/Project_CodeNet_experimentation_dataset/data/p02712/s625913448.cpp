	#include<bits/stdc++.h>
    using namespace std;
    #define 	ll 			long long
    #define 	w(t)		int t; cin>>t; while(t--)  
	#define 	AsmShuvo()  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
			
    int main()
    {
    AsmShuvo()
    	
    	ll N, sum=0, i;
		cin>>N;
			
		for(i=1; i<=N; i++){
		if(i%3 != 0 && i%5 != 0){
			sum = sum+i;
		    }
		}
		cout<<sum<<endl;
			

	}
	
