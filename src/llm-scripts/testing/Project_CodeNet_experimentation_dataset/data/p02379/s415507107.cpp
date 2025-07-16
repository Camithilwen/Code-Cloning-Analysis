#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using VI = vector<int>;
using PI = pair<int, int>;

int main() {
	double x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << setprecision(12) << fixed << hypot(abs(x1 - x2), abs(y1 - y2)) << endl;
	return 0;
}

