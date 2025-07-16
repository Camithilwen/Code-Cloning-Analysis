#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	while (cin >> n) {
		long long stool = 0;
		int prev = 0;
		for (int i = 0; i < n; ++i) {
			int aux;
			cin >> aux;
			if (aux <= prev) {
				stool += (prev - aux);
			} else {
				prev = aux;
			}
		}
		cout << stool << endl;
	}
	return 0;
}