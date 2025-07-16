#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f40;
const long long mod=1e9+7;
const long double PI = acos(0);
template <class T>void UNIQUE(vector<T> &x){
	sort(all(x));
	x.erase(unique(all(x)), x.end());
}

// }}} End Header
int main() {
	int n, ans = 0;
	cin >> n;
	vector<ll> l(n);
	map<ll, ll> dict;
	rep(i,n){
		cin >> l[i];
		dict[l[i]]++;
	}
	UNIQUE(l);
	if(l.size()<3){
		cout << 0 << endl;
		return 0;
	}
	rep(i,l.size()-2){
		loop(j, i+1, l.size()-1){
			loop(k, j+1, l.size()){
				if(l[i]+l[j] > l[k]){
					//cout << l[i] << l[j] << l[k] << endl;
					ans+=(dict[l[i]]*dict[l[j]]*dict[l[k]]);
				}		
			}
		}
	}
	cout << ans << endl;

	return 0;
}