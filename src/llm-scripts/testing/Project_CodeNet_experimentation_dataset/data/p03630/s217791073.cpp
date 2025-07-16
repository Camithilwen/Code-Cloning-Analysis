#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#define rep(i, a, b) for (int i = (a), _ = (b); i <= _; ++ i)
#define per(i, a, b) for (int i = (a), _ = (b); i >= _; -- i)
#define For(i, a, b) for (int i = (a), _ = (b); i < _; ++ i)
#define ri rd<int>
using namespace std;
const int maxN = 2007;

template<class T> inline T rd() {
	bool f = 1; char c = getchar(); for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	T x = 0; for (; isdigit(c); c = getchar()) x = x * 10 + c - 48; return f ? x : -x;
}

int n, m;
char s[maxN][maxN];
int a[maxN], b[maxN], c[maxN];
int mat[maxN][maxN];
int stack[maxN], Top, ans = 0;

int main() {

	n = ri(), m = ri();
	rep (i, 1, n) scanf("%s", s[i]+1);

	For (i, 1, n) {
		rep (j, 1, m) a[j] = s[i][j] == '.' ? 1 : 0;
		rep (j, 1, m) b[j] = s[i+1][j] == '.' ? 1 : 0;

		rep (k, 0, 1) {
			rep (j, 1, m) b[j] ^= k;
			per (j, m, 1) c[j] = (a[j] == b[j]) ? 1 + c[j+1] : 0;
			rep (j, 1, m) mat[i][j] = max(mat[i][j], c[j]);
		}
	}

	rep (j, 1, m) {
		Top = 0;
		For (i, 1, n) {
			for (; Top && mat[stack[Top]][j] >= mat[i][j]; --Top) {
				ans = max(ans, mat[stack[Top]][j] * (i - stack[Top-1]));
			}
			stack[++Top] = i;
		}
		for (; Top; --Top) { 
			ans = max(ans, mat[stack[Top]][j] * (n - stack[Top-1]));
		}
	}

	printf("%d\n", max(ans, m));

	return 0;
}
