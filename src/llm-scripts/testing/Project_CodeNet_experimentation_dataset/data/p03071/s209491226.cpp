#include "bits/stdc++.h"
using namespace std;

int main() {
	int A,B;
	cin >> A>>B;
	int ans = 0;
	for (int n = 0;n<2; ++n) {
		if (A > B) {
			ans += A;
			--A;
		}
		else {
			ans += B;
			--B;
		}
	}
	cout << ans<<endl;
	return 0;
}