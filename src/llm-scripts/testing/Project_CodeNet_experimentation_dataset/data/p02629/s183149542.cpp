#include "bits/stdc++.h"
using namespace std;

int main() {
	long long int n;
	cin >> n;

	string ans;

	do {
		ans.push_back(97 + (--n % 26));
		n /= 26;
	} while (n > 0);

	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}