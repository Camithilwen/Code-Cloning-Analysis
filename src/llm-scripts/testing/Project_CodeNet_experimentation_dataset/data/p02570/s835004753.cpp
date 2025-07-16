#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll max(ll a, ll b){
	if(a>b)return a;
	else return b;
}

int main(){
    int d,t,s;
    cin>>d>>t>>s;
    if(t*s>=d){
    	cout<<"Yes"<<endl;
	}else
	cout<<"No"<<endl;
}