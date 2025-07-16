#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int a[100100]; 
int main() {
	int n, k;
	cin >> n >> k;
	rep(i,n) cin >> a[i];
	
	sort(a,a+n);

	bool can = true;
	if (a[n-1] < k) can = false;
	int g = a[0];
	rep(i,n) g = __gcd(g,a[i]);
	if (k % g != 0) can = false;

	if (can) cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;
	return 0;
}