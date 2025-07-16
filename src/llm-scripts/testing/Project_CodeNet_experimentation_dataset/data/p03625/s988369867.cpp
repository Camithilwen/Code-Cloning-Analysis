#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	ll n;
	cin >> n;
	vector<ll>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll x = 0,y = 0;
	ll index = 0;
	for (int i = n - 1; i > 0; i--) {
		if (a[i] == a[i - 1]) {
			x = a[i];
			index = i - 2;
			break;
		}
	}

	for (int i = index; i > 0; i--) {
		if (a[i] == a[i - 1]){
			y = a[i];
			break;
		}
	}
	cout << x * y << endl;
	return 0;
}
