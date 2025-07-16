#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
	
	int n; cin >> n;
	vector<int> a(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int sum = 0;
	for (int i = 1; i <= n + 1; i++) {
		sum +=abs(a[i] - a[i - 1]);
	}
	for (int i = 1; i <= n; i++) {
		int tmp = sum;
		tmp -= abs(a[i] - a[i - 1]);
		tmp -= abs(a[i + 1] - a[i]);
		tmp += abs(a[i + 1] - a[i - 1]);
		cout << tmp << endl;
	}
    return 0;
}