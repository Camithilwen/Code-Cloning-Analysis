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
	
	int sum=0, sumsqr=0;
	for(int i=0; i<n; i++){
		sum = add(sum,a[i]);
		sumsqr = add(sumsqr, a[i]*a[i]);
	}
	int ans = mod(mul(sum,sum)-sumsqr);
	if(ans%2==0) cout<<ans/2;
	else cout<<mod((ans + M)/2);
}