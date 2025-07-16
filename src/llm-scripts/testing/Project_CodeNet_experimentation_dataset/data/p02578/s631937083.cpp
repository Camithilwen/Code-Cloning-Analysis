#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

#define ll long long

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;
	vector<ll> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			if (a[i] < a[i - 1]) {
				sum += a[i - 1] - a[i];
				a[i] += a[i - 1] - a[i];
				
			}
		}
	}

	cout << sum;
	

	return 0;
}