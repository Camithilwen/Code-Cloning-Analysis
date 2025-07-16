#include <bits/stdc++.h>
using namespace std;
int main() {
	long long v, a, b, c, d, e;
	cin >> v >> a >> b >> c >> d >> e;
	long long slow = min({a, b, c, d, e});
	cout << (v + slow-1)/ slow + 4;
	return 0;
}