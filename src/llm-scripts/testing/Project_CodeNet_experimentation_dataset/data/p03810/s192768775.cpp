#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mpcy(a, b) memcpy(a, b, sizeof(a))
#define rg register
using namespace std;
typedef long long LL;
const int MAXN = 100005;

template <typename T> inline void read(T &AKNOI) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    AKNOI = flag * x;
}

template <typename T> inline void cmin(T &x, T y) {
    if (x > y) x = y;
}

template <typename T> inline void cmax(T &x, T y) {
    if (x < y) x = y;
}

int n, a[MAXN];

void output(int win) {
	puts(win? "First" : "Second");
	exit(0);
}

int gcd(int x, int y) {
	return (y == 0)? x : gcd(y, x % y);
}

void play(int player) {
	int even = 0;
	for (int i=1;i<=n;++i) {
		even += !(a[i] & 1);
	}
	if (even & 1) output(1 ^ player);
	if (n - even > 1) output(0 ^ player);
	int d = 0;
	for (int i=1;i<=n;++i) {
		if (a[i] == 1) output(0 ^ player);
		d = gcd(d, a[i] - (a[i] & 1));
	}
	for (int i=1;i<=n;++i) {
		a[i] /= d;
	}
	play(player ^ 1);
}

void solve() {
	read(n);
	for (int i=1;i<=n;++i) {
		read(a[i]);
	}
	play(0);
}

int main() {
	solve();
	return 0;
}
