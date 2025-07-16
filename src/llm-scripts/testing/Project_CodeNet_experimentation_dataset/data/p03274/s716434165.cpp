#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define ar array

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int > pii;
const ll MOD =1e9+7;

void solve(){
	int n,k,ans=1e9+10; cin >> n >> k;
	vi a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < n-k+1; ++i){
		if(a[i] > 0)
			ans = min(ans,a[i+k-1]);
		else if(a[i+k-1]<0)
			ans = min(ans,-a[i]);
		else
			ans =min(ans,-a[i]+a[i+k-1]+min(-a[i],a[i+k-1]));
	}
	cout << ans;
}
int main(){
	int t=1;
	//cin >> t;
	while(t--){
		solve();
		cout <<'\n';
	}
}
