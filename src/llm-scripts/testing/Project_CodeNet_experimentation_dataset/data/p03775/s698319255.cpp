#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 1000000007;
const ll INF = 1e18;
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

int main(){
	ll n; cin >> n;
	int ans=log10(n)+1;
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0){
			ans=max(log10(i)+1,log10(n/i)+1);
		}
	}
	cout << ans << endl;
	return 0;
}