#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
using namespace std;

const int maxn = 100005;
int a[maxn], n;

inline int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int solve() {
	int flag1 = 0, cnt1 = 0, cnt0 = 0;
	rep (i, 1, n)
		if (a[i] & 1) {
			flag1 |= (a[i] == 1);
			cnt1++;
		}
		else cnt0++;
	if (cnt0 & 1) return 1;
	if (cnt1 != 1) return 0;
	if (flag1) return cnt0 & 1;
	rep (i, 1, n)
		if (a[i] & 1) a[i]--;
	int g = a[1];
	rep (i, 2, n)
		g = gcd(g, a[i]);
	rep (i, 1, n)
		a[i] /= g;
	return solve() ^ 1;
}

int main() {
	scanf("%d", &n);
	rep (i, 1, n) scanf("%d", &a[i]);
	puts(solve() ? "First" : "Second");
	return 0;
}