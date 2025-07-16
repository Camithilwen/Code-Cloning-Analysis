#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	int ans = INT_MAX;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		
		int cnt = 0;
		while (n%2==0) {
			if (n / 2) {
				cnt++;
				n /= 2;
			}
			else {
				break;
			}
		}

		ans = min(ans, cnt);
	}

	cout << ans << endl;
}