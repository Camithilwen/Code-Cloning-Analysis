#include<bits/stdc++.h>
using namespace std;

const int N = 1000 * 100 + 10;
int n, a[N], tt = 0;
string ans[2] = {"First\n", "Second\n"};

void solve() {
	long long sum = 0;
	bool one = false;
	int cnt[2] = {0, 0};
	for (int i = 0; i < n; i++) {
		 one |= a[i] == 1;
		sum += a[i] - 1;
		cnt[a[i] & 1]++;
	}
	if (one) {
		cout << ans[(sum + 1 + tt) & 1];
		exit(0);
	}
	if (n == 1) {
		cout << ans[(sum + 1 + tt) & 1];
		exit(0);
	}
	if (cnt[0] & 1) {
		cout << ans[tt & 1];
		exit(0);
	}
	if (cnt[1] >= 2) {
		cout << ans[(1 + tt) & 1];
		exit(0);
	}
	for (int i = 0; i < n; i++)
		if (a[i] & 1) {
			a[i]--;
			break;
		}
	long long g = a[0];
	for (int i = 1; i < n; i++)
		g = __gcd(1LL * a[i], g);
	for (int i = 0; i < n; i++)
		a[i] /= g;
	tt++;
	solve();
}

int main() { 
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	solve();
	return 0;
}
