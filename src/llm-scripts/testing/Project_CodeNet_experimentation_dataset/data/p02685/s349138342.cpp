#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 2e5 + 5, mod = 998244353;

int fact[N], rev[N];

int mult(int a, int b) {
	return (1LL * a * b) % mod;
}

int pw(int a, int b) {
	if(!b)
		return 1;
	int ans = pw(a, b / 2);
	ans = mult(ans, ans);
	if(b & 1)
		ans = mult(ans, a);
	return ans;
}

void prep() {
	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = mult(fact[i - 1], i);
	rev[N - 1] = pw(fact[N - 1], mod - 2);
	for (int i = N - 2; ~i; i--)
		rev[i] = mult(rev[i + 1], i + 1);
}

int sum(int a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
	if(a < 0)
		a += mod;
	return a;
}

int c(int n, int k) {
	if(k > n)
		return 0;
	return mult(fact[n], mult(rev[k], rev[n - k]));
}

int n, m, k;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	prep();
	cin >> n >> m >> k;
	int ans = 0;
	for (int i = 0; i <= k; i++)
		ans = sum(ans, mult(m, mult(pw(m - 1, n - 1 - i), c(n - 1, i))));
	cout << ans << "\n";
}
