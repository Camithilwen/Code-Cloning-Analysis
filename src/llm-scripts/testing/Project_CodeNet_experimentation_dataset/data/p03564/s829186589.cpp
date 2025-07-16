#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+6;
int k,n;
void solve(){
	cin>>n>>k; 
	int st = 1;
	for(int i=1;i<=n;i++){
		if(st*2<st+k)st*=2;
		else st+=k;
	}
	cout<<st<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
