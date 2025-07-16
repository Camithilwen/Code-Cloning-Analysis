#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	ll mi = 1e9, sum = 0;
	vector<ll> a(n);
	int cnt = 0;
	bool zero = false;
	rep(i,n){
		cin >> a[i];
		if(a[i] < 0){
			++cnt;
			chmin(mi, -a[i]);
			sum -= a[i];
		}
		else if(a[i] == 0) zero = true;
		else{
			chmin(mi, a[i]);
			sum += a[i];
		}
	}
	ll ans = sum;
	if(!zero && (cnt%2 == 1)) ans -= 2 * mi;
	cout << ans << endl;
	return 0;
}