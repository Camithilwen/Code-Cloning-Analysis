#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int count = 0;
	map<int, int> mp;
	for (int i = 0; i < 3; i++) {
		int a;
		cin >> a;
		if (mp[a])
			count++;
		mp[a] = 1;
	}
	if (count == 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}