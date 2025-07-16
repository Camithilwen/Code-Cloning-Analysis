/********************************************************************************
	
	Code by a weak man who named CYJian, and he hope the code can get more points.

	Algorithm: 

 ********************************************************************************/

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

const string S4[4] = {"abcc", "abdd", "ccab", "ddab"};
const string S5[5] = {"abbcc", "ad..a", "bd..a", "b.eez", "oorrz"};
const string S6[6] = {"oorrzz", ".a.b.c", ".a.b.c", "d.e.f.", "d.e.f.", "oorrzz"};
const string S7[7] = {".oorrzz", "oabb...", "oa.c...", "rddc...", "r...abb", "z...a.c", "z...ddc"};

char s[1010][1010];

inline void solve(int&n, int x) {
	if(x == 4)
		for(int i = 0; i < x; i++)
			for(int j = 0; j < x; j++)
				s[n + i][n + j] = S4[i][j];
	if(x == 5)
		for(int i = 0; i < x; i++)
			for(int j = 0; j < x; j++)
				s[n + i][n + j] = S5[i][j];
	if(x == 6)
		for(int i = 0; i < x; i++)
			for(int j = 0; j < x; j++)
				s[n + i][n + j] = S6[i][j];
	if(x == 7)
		for(int i = 0; i < x; i++)
			for(int j = 0; j < x; j++)
				s[n + i][n + j] = S7[i][j];
	n += x;
}

int main() {
	int n = ri;
	if(n <= 2) return puts("-1"), 0;
	if(n == 3) {
		puts("a..");
		puts("a..");
		puts(".bb");
		return 0;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			s[i][j] = '.';
	int x = n % 4, N = 1;
	if(x == 0) solve(N, 4);
	if(x == 1) solve(N, 5);
	if(x == 2) solve(N, 6);
	if(x == 3) solve(N, 7);
	while(N <= n) solve(N, 4);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)
			putchar(s[i][j]);
		puts("");
	}
	return 0;
}