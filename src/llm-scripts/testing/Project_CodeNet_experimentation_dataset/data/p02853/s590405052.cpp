#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x, y;
	cin >> x >> y;
	int total = 0;
	if (x <= 3)
		total += 4 - x;
	if (y <= 3)
		total += 4 - y;
	if (x == 1 && x == y) {
		total += 4;
	}
	total *= int(1e5);
	cout << total;
}
