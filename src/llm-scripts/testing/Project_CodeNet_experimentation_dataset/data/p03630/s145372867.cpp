#include <bits/stdc++.h>

#define For(i, a, b) for (register int i = (a), i##_end = (b); i <= i##_end; ++ i)  
#define getc getchar_unlocked
#define inf (0x3f3f3f3f)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define y1 igniubi

using namespace std;

inline int read() {
	int _ = 0, __ = getc(), ___ = 1; 
	for(; !isdigit(__); __ = getc()) if(__ == '-') ___ = -1;
	for(; isdigit(__); __ = getc()) _ = (_ << 3) + (_ << 1) + (__ ^ 48);
	return _ * ___;
}

const int N = 2e3 + 10;

int n, m, a[N][N], b[N][N], f[N][N], S[N], w[N], ans, top;

int main() {
	//freopen("speech.in", "r", stdin);
	//freopen("speech.out", "w", stdout);
	
	n = read(), m = read();
	For(i, 1, n) {
		char ss[N];
		scanf("%s", ss + 1);
		For(j, 1, m) {
			a[i][j] = ss[j] == '#';
			if(i > 1 && j > 1 && !((a[i][j] + a[i - 1][j] + a[i][j - 1] + a[i - 1][j - 1]) & 1)) 
				b[i - 1][j - 1] = 1;
		}
	}
	For(i, 1, n) For(j, 1, m) if(b[i][j]) f[i][j] = f[i][j - 1] + 1;

	For(j, 1, m) {
		top = 0;
		For(i, 1, n) {
			int kuan = 0;
			for(; top && f[S[top]][j] >= f[i][j]; -- top) {
				kuan += w[S[top]];
				ans = max(ans, min(n, kuan + 1) * min(m, f[S[top]][j] + 1));
			}
			w[i] = kuan + 1, S[++ top] = i;
		}
		int kuan = 0;
		for(; top; -- top) {
			kuan += w[S[top]];
			ans = max(ans, min(n, kuan + 1) * min(m, f[S[top]][j] + 1));
		}
	}

	printf("%d\n", max(max(n, m), ans));

	return 0;
}
