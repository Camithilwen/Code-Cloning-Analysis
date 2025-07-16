#include<iostream>
#include<string>

using namespace std;

typedef long long ll;

int main() {
	int n;
	string s;
	cin >> n >> s;

	int q;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;

		ll ans = 0;
		ll cm = 0, cc = 0;
		int left = 0, right = 0;
		ll plus = 0;
		for (; left < n; left++) {
			while (right < n && right - left < k) {
				if (s[right] == 'M')cm++;
				if (s[right] == 'C')plus += cm, cc++;
				right++;
			}

			if (s[left] == 'D')ans += plus;

			if (s[left] == 'M')plus -= cc, cm--;
			if (s[left] == 'C')cc--;
		}
		cout << ans << endl;
	}

	return 0;
}