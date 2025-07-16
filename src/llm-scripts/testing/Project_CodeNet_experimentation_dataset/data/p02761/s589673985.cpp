#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,m;
	cin>>n>>m;
	ll ch[3];
	for(ll i=0;i<3;i++){
		ch[i]=-1;
	}
	for(ll i=0;i<m;i++){
		ll x,z;
		cin>>x>>z;
		x--;
		if(ch[x]==-1){
			ch[x]=z;
		}
		else{
			if(ch[x]!=z){
				cout << -1;
				return 0;
			}
		}
	}
	if(ch[0]==0&&n!=1){
		cout <<-1;
		return 0;
	}
	for(ll i=0;i<n;i++){
		if(ch[i]==-1){
			if(i==0&&n!=1){
				cout << 1;
			}
			else{
			cout << 0;
			}
		}
		else{
		cout << ch[i];
		}
	}
	// your code goes here
	return 0;
}