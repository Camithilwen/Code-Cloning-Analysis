#include<bits/stdc++.h>
#define	INF	0x3f3f3f3f
#define	LL	long long
#define	MAXN	210
#define	MAXS	100010
#define	mod	1000000007
using namespace std;
int n, x, w[MAXN];
int f[MAXN][MAXS];

template <typename T> void chkmin(T &x, T y){x = min(x, y);}
template <typename T> void chkmax(T &x, T y){x = max(x, y);}
template <typename T> void read(T &x){
	x = 0; int f = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}

void update(int &x, const int &y){x = (x + y >= mod) ? (x + y - mod) : (x + y);}
int mul(const int &x, const int &y){return 1ll * x * y % mod;}
int inc(const int &x, const int &y){return (x + y >= mod) ? (x + y - mod) : (x + y);}

int main(){
	read(n), read(x);
	for (int i = 1; i <= n; ++i)
		read(w[i]);
	sort(w + 1, w + 1 + n);
	for (int i = 0; i <= x; ++i)
		f[0][i] = i;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= x; ++j){
			if (!f[i - 1][j]) continue;
			update(f[i][j], mul(f[i - 1][j], i - 1));
			if (w[i] > j) {
				for (int t = 0; j + t <= x; t += w[i])
					update(f[i][j + t], f[i - 1][j]);
			}
		}
	printf("%d\n", f[n][x]);
	return 0;
}