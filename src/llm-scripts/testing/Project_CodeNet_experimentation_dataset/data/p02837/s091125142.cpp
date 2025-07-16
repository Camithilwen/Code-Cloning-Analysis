#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int kind[16];
	int unkind[16];
	
	for(int i=0; i<n; i++){
		int kind_p = 0;
		int unkind_p = 0;
		int t;
		cin>>t;
		while(t--){
			int a,b;
			cin>>a>>b;
			if(b) kind_p |=(1<<--a);
			else unkind_p|=(1<<--a);
		}
		kind[i] = kind_p;
		unkind[i] = unkind_p;
	}
	int maxpeople = 0;
	for(int i=0; i<(1<<n); i++){
		int totalkind = 0;
		int totalunkind = 0;
		for(int j=0; j<n; j++){
			if(i&(1<<j)){
				totalkind|=kind[j];
				totalunkind|=unkind[j];
			}
		}
		bool possible = true;
		for(int j=0; j<n; j++){
			if(totalkind&(1<<j) && (i&(1<<j))==0) possible = false;
			if(totalunkind&(1<<j) && i&(1<<j)) possible = false;
		}
		
		if(possible) maxpeople = max(maxpeople,__builtin_popcount(i));
	}
	//for(int i=0; i<n; i++) cout<<kind[i]<<" ";
	cout<<maxpeople;
}