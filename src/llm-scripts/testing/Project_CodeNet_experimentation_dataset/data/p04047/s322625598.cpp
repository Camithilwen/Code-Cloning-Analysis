#include<iostream>
#include<algorithm>
using namespace std;

int a[210] = { 0 }, n;

int main() {
	cin >> n;
	int len = 2 * n, ans = 0;
	for (int i = 0; i < len; i++) cin >> a[i];
	sort(a, a + len);
	for (int i = 0; i < len; i += 2) ans += a[i];
	cout << ans << endl;
	return 0;
}