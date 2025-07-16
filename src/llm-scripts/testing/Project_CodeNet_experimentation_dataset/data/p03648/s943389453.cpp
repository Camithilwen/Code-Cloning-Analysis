#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;

int main() {
	ll K;
	cin >> K;
	cout << 50 << endl;
	vector<ll> a(50);
	for (int i = 0; i < 50; i++) {
		a[i] = i + K / 50 - K % 50;
		if (i < K % 50) a[i] += 51;
	}
	for (int i = 0; i < 50; i++) cout << a[i] << " ";
	cout << endl;
 }