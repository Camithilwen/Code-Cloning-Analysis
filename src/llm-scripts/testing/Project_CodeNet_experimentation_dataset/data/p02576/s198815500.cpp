#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n,x,t;
	cin>>n>>x>>t;
	
	ll k=n/x,r=n%x;
	
	if(r>0)r=1;
	
    cout<<k*t+r*t;
	

}