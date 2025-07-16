#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define fr first
#define sc second
#define pb push_back
const ll mod = 998244353;
const int N = 1e6+205;
ll cnt[N];
void solve(){
	int n,m; 
	cin>>n>>m; 
	for(int i=0;i<m;i++){
		int x,y; 
		cin>>x>>y; 
		cnt[x]++;
		cnt[y+1]--;
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		cnt[i] = cnt[i-1]+cnt[i];
		if(cnt[i]==m)ans++;
	}
	cout<<ans<<endl;
	
	
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
