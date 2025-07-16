#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;
using namespace atcoder;

typedef long long ll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;

	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	fenwick_tree<ll> fw(n);
	rep(i, n) fw.add(i, a[i]);

	rep(i, q){
		int t;
		cin >> t;

		if(t == 0){
			ll p, x;
			cin >> p >> x;
			fw.add(p, x);
		}else{
			ll l, r;
			cin >> l >> r;
			cout << fw.sum(l, r) << endl;
		}
	}

}
