#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, i, a[210];
	cin >> n;
	n *= 2;
	for (i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	int b = 0, c = 0;
	for (i = 0; i < n; i += 2) {
		b += a[i];
	}
	for (i = 1; i < n - 1; i += 2) {
		c += a[i];
	}
	//c += a[0];
	cout << max(b, c) << endl;
	return 0;
}