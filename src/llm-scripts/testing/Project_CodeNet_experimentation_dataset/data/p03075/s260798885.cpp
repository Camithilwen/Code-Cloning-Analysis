#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	vector<int>a(5);
	for (int i = 0; i < 5; i++)cin >> a.at(i);
	sort(a.begin(), a.end());
	int k;
	cin >> k;
	for (int i = 0; i < 4; i++) {
		for (int j = i; j < 5; j++) {
			if (a.at(j) - a.at(i) <= k)continue;
			else {
				cout << ":(" << endl;
				return 0;
			}
		}
	}
	cout << "Yay!" << endl;
}