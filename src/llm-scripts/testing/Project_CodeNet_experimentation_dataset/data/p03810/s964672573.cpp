#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

#define fi first
#define se second

typedef long long ll;
typedef double ff;
typedef std::pair<int, int> pii;

const int kN = 1e5 + 5;

int a[kN], n;
int Gcd(int x, int y) { return y ? Gcd(y, x % y) : x; }
void Div() {
	int g = a[1];
	for(int i = 2; i <= n; ++i) g = Gcd(g, a[i]);
	for(int i = 1; i <= n; ++i) a[i] /= g;
}

int main() {
	int cur = 0; rd(n);
	for(int i = 1; i <= n; ++i) rd(a[i]);
	while(true) {
		int cnt = 0, ecnt = 0, p; bool flag = false;
		for(int i = 1; i <= n; ++i) {
			if(a[i] % 2 == 0) ++cnt;
			else p = i, ++ecnt;
			if(a[i] == 1) flag = true;
		}
		if(flag) return printf((cnt % 2 == 1) ^ cur ? "First" : "Second"), 0;
		if(cnt % 2 == 1) return printf(cur ? "Second" : "First"), 0;
		if(ecnt > 1 && cnt % 2 == 0) return printf(cur ? "First" : "Second"), 0;
		--a[p]; Div(); cur ^= 1;
	}
	return 0;
}