#include<bits/stdc++.h>
#include<string>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define mod (ll)(1e9+7)
#define nax (ll)(1e5)
#define INFL LLONG_MAX
#define NINFL LLONG_MIN
#define INF INT_MAX
#define disp(a,n,arr) for(int i=a;i<(ll)n;i++) cout << arr[i] << " "; cout << "\n";
#define check cout << "Working\n";
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vpl vector<pl>
#define vpi vector<pi>
#define vb vector<bool>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(),a.end()
using namespace std;

int main() {
	FIO;
	int t = 1;
	//cin >> t;
	while (t--) {
		ll n,m;
		cin >> n >> m;
		vl v(n,0);
		for(int i=0;i<m;i++){
			ll l,r;
			cin >> l >> r;
			l--;
			v[l]++;
			if(r < n) v[r]--;
		}
		ll ans = 0;
		if(v[0] == m) ans++;
		for(int i=1;i<n;i++){
			v[i] += v[i-1];
			if(v[i] == m) ans++;
		}
		cout << ans << "\n";
	}


	return 0;
}
