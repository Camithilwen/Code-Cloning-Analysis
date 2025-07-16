#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll K;cin >> K;
	ll x = K / 50;
	ll y = K % 50;
	vector<ll> ans;
	cout << 50 << endl;
	for (int i = 0;i < 51;i++) {
		if (i + y != 50)
			ans.push_back(i);
	}
	for (int i = 0;i < 50;i++) {
		cout << ans[i] + x << " ";
	}
}