#include <bits/stdc++.h>
using namespace std;
#define mid ((s + e) / 2)
#define makefast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define comp(x) (lower_bound(vec.begin(), vec.end(), x) - vec.begin())
#define lc (v * 2)
#define rc (v * 2 + 1)
long long M = 1e9 + 7;
//>>>>>>>>>>>>>>>>>>>

#define int long long

const int N = 1e6 + 7;

int n;

int pw(int a, int b) {
	int res = 1;
	while (b) {
		if (b % 2)
			res = (res * a) % M;
		b /= 2;
		a = (a * a) % M;
	}
	return res;
}
int f[N], rf[N];
int chs(int a, int b) {
	if (a > b)
		return 0;
	if (a < 0 || b < 0 || a >= N || b >= N) {
		cout << "FITA";
		exit(0);
	}
	return (((f[b] * rf[a]) % M) * rf[b - a]) % M;
}
int sm3[N], sm2[N];
int32_t main() {
	makefast;
	cin >> n >> M;
	f[0] = rf[0] = 1;
	for (int i = 1; i < N; i++) {
		f[i] = (f[i - 1] * i) % M;
		rf[i] = (rf[i - 1] * pw(i, M - 2)) % M;
	}
	sm3[0] = 1;
	for (int i = 1; i < 10000; i++)
		sm3[i] = (((sm3[i - 1] * chs(3, 3 * i)) % M) * pw(i, M - 2)) % M;
	sm2[n + 1] = 1;
	for (int i = n; i >= 0; i--) 
		sm2[i] = (((sm2[i + 1] * chs(2, 3 * n - 2 * (n - i))) % M) * pw(n - i + 1, M - 2)) % M;
	int res = 0;
	for (int b = 0; b <= n; b++) 
		for (int a = b; a + 2 * b <= 3 * n; a++) {
			if ((a + 2 * b) % 3)
				continue;
			int c = (3 * n - (a + 2 * b)) / 3;
			int t = sm2[n - b + 1];
			t = (t * chs(a, 3 * n - 2 * b)) % M; 
			t = (t * ((sm3[c] * pw(2, c)) % M)) % M;
			res = (t + res) % M;
		//	cout << a << " " << b << " " << c << " > " << t << " sm2 : " << sm2[n - b + 1] << " chs : " << chs(a, 3 * n - 2 * b) << " sm3 : " << sm3[c] << endl;
		}
	cout << res;
	return 0;
}
