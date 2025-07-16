#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Rep(n) for (ll _ = 0; _ < (ll)(n); _++)

int main(){
	int n; cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	deque<int> d;
	rep(j,n){
		int i = lower_bound(d.begin(), d.end(), a[j]) - d.begin();
		if(i == 0){
			d.push_front(a[j]);
		}else{
			d[i-1] = a[j];
		}
	}
	int ans = d.size();
	cout << ans << endl;
	return 0;
}