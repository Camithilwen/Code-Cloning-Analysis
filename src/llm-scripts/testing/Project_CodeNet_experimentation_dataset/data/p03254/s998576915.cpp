#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());
	int ans = 0, sum = 0;
	for (int i = 0; i < n; i++) {
      	if (sum + a[i] > x) break;
		sum += a[i];
		ans++;
      	if (i==n-1 && x > sum) ans--;
	}
  
	cout << ans << endl;
}