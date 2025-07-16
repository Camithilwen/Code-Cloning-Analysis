#include<bits/stdc++.h>
using namespace std; 
#define int long long

int M = 1000000007;

int mod(int a){
	return (a%M + M)%M;
}
int mul(int a, int b){
	return mod(mod(a) * mod(b));
}
int add(int a, int b){
	return mod(mod(a) + mod(b));
}
int sub(int a, int b){
	return mod(mod(a) - mod(b));
}
main(){
	int n; cin>>n;
	int a[n];
	for(auto &it : a) cin>>it;
	
	int sum=0, sum1=0;
	for(int i=0; i<n; i++){
		sum = add(sum,a[i]);
		//sum1 = add(sum1,mul(a[i],a[i]));
	}
	int ans=0;
    for(int i=0; i<n; i++){
		sum = sub(sum,a[i]);
		ans = add(ans,mul(sum,a[i]));
	}	 
	cout<<ans;
}