#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}

int main() {
	int n, m, x, y; cin >> n >> m >> x >> y;
	int x_max = x;
	int y_min = y;
	for(int i=0;i<n;i++){
		int a; cin >> a;
		x_max = max(x_max, a);
	}
	for(int i=0;i<m;i++){
		 int b; cin >> b;
		 y_min = min(y_min, b);
	}
	if(x_max<y_min){
		cout << "No War" << endl;
		return 0;
	}
	cout << "War" << endl;
	return 0;
}