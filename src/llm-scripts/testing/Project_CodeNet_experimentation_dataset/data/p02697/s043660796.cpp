#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T = int> void print(vector<T> v){for(auto a:v)cout<<a<<" ";cout<<endl;}

/*
*/

ll n,m;

int main(void){
	cin>>n>>m;
	if(n%2==1){
		rep(i,m)cout<<i+1<<" "<<n-i<<endl;
	}else{
		rep(i,min(m,n/4))cout<<i+1<<" "<<n/2-i<<endl;
		m-=n/4;
		if(m>0){
			rep(i,m)cout<<i+n/2+2<<" "<<n-i<<endl;
		}
	}
	return 0;
}