#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;

#define ge (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
#define ri read_int()
#define rl read_ll()
#define FILE(s) freopen(s"in", "r", stdin), freopen(s"out", "w", stdout)

template<typename T>
inline void read(T &x) {
	char ch, t = 0; x = 0;
	while(!isdigit(ch = ge)) t |= ch == '-';
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = ge;
	x = t ? -x : x;
}
inline int read_int() { int x; return read(x), x; }
inline ll read_ll() { ll x; return read(x), x; }

template<typename T>
inline void chkmin(T&a, T b) { a = a < b ? a : b; }

const int MAXN = 110;

int a[MAXN];
int js[MAXN];

int main() {
#ifdef LOCAL
	FILE("");
#endif
	int cnt = 0;
	int n = ri;
	int m = ri;
	if(m == 1) {
		if(n == 1) {
			cout << 1 << endl;
			cout << 1 << endl;
			cout << 1 << endl;
		} else {
			cout << n << endl;
			cout << 2 << endl;
			cout << 1 << ' ' << n - 1 << endl;
		}
	}
	else {
		for(int i = 1; i <= m; i++) {
			a[i] = ri;
			if(a[i] & 1)
				js[cnt++] = i;
		}
		if(cnt > 2) puts("Impossible");
		else {
			if(js[0] && js[0] != 1) swap(a[1], a[js[0]]);
			if(js[1] && js[1] != m) swap(a[m], a[js[1]]);
			for(int i = 1; i <= m; i++) printf("%d ", a[i]); puts("");
			a[1]++, a[m]--;
			if(!a[m]) --m;
			printf("%d\n", m);
			for(int i = 1; i <= m; i++) printf("%d ", a[i]); puts("");
		}
	}
	return 0;
}
