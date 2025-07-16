#include <bits/stdc++.h>

using namespace std;

const int N=55;

void maxi(int &a, int b) {
	a = max(a,b);
}

using ll = long long;
ll MOD = 1e9 +7;

ll add(ll x, ll y) {
	return ((x + y) % MOD);
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	vector<ll> X;
 	vector<ll> Y;
	int n, m; cin >> n >> m;
	for (int i=0; i < n; i++) {
		ll x; cin >> x;
		X.push_back(x);
	}
	for (int i=0; i < m; i++) {
		ll y; cin >> y;
		Y.push_back(y);
	}
	ll x_total = 0;
	for (int k=0; k <n; k++) {
		x_total += add(X[k]*k, -(n-k-1)*X[k]);	
		x_total %= MOD;
	}
	//ll x_check =0;
	//for (int i=0; i < n; i++) {
	//	for (int j=i+1; j < n; j++) {
	//		x_check += (X[j] - X[i]);
	//	}
	//}
	//assert(x_check == x_total);
	ll y_total = 0;
	for (int k=0; k < m; k++) {
		y_total += add(Y[k]*k, -(m-k-1)*Y[k]);	
		y_total %= MOD;
	}
	//ll y_check = 0;
	//for (int i=0; i < m; i++) {
	//	for (int j=i+1; j < m; j++) {
	//		y_check += (Y[j] - Y[i]);
	//	}
	//}
	//assert(y_check == y_total);
	ll total = (x_total*y_total) % MOD;
	if (total < 0) {
		total += MOD;
	}
	cout << total << endl;
}

