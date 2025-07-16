#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int k, t;
	cin >> k >> t;
	vector<int>a(t);
	for (int i = 0; i < t; i++)cin >> a.at(i);
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	if (a.at(0) <= ceil((double)k / 2))cout << 0 << endl;
	else {
		if (k % 2 == 0)cout << 1 + 2 * (a.at(0) - ceil((double) k/2 ) - 1) << endl;
		else cout << 2 * (a.at(0) - ceil((double)k / 2)) << endl;
	}
}