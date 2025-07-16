#include <bits/stdc++.h>
#define gcd std::__gcd
#define EB emplace_back

typedef std::vector <int> vector;
const int N = 100054;

int n;
vector a;

inline bool judge(const vector &v) {
	int c[2] = {0}, g = 0; bool one = false; vector u(v);
	for (int x : v) ++c[x & 1], one |= x == 1;
	if (*c & 1) return true;
	if (one || c[1] > 1) return false;
	for (int &x : u) g = gcd(g, x &= -2);
	for (int &x : u) x /= g;
	return !judge(u);
}

int main() {
	int i, x;
	scanf("%d", &n), a.reserve(n);
	for (i = 1; i <= n; ++i) scanf("%d", &x), a.EB(x);
	return puts(judge(a) ? "First" : "Second"), 0;
}