#include <bits/stdc++.h>
//#include <tr1/unordered_map>
//#include"Bignum/bignum.h"
//#define big bignum
#define lowbit(x) (x & -x)
#define debug(x) (cout << "#x = " << (x) << endl)
#define Set(x, i) memset (x, i, sizeof(x))
#define R register
#define For(i, j, k) for(R int i = (j); i <= (int) (k); ++i)
#define Rep(i, j, k) for(R int i = (j); i >= (int) (k); --i)
#define Cross(i, j, k) for(R int i = (j); i; i = (k))
using namespace std;
typedef long long ll;
const ll N = 21;
const ll INF = 5e16;

namespace IO {

	inline char gc() {
		static char buf[100000], *p1 = buf, *p2 = buf;
		return (p1 == p2) && (p2 = (p1 = buf) +
			fread(buf, 1, 100000, stdin), p1 == p2)? EOF: *p1++;
	}

	#define dd ch = getchar()
	inline ll read() {
		R ll x = 0; R int f = 0; R char dd;
		for (; !isdigit(ch); dd) f ^= (ch == '-');
		for (; isdigit(ch); dd)  x = x * 10 + (ch ^ 48);
		return f? -x: x;
	}
	#undef dd

	inline void write ( ll x ) {
		if (x < 0) x = -x, putchar('-');
		if (x > 9) write(x / 10); putchar(x % 10 | 48);
	}

	inline void wrn ( ll x ) { write(x), putchar(' '); }

	inline void wln ( ll x ) { write(x), putchar('\n'); }

	inline void wlnn ( ll x, ll y ) { wrn(x), wln(y); }

}

using IO::wln;
using IO::read;

namespace Cesare {
	
	/*
		f[i][S] 表示当前走到 i ，走过的路径 
		状态为 S 最大可以保留的权值和。 
		每次转移枚举加入一个点集还是一个点。 
		这基于一个性质：每次加入的一个点或点集必定 
		只与一条简单路径上的一个点相连，所以不会影 
		响简单路径数量。 

		f[j][S | (1 << j - 1)] = max f[i][S] + w[i][j]) 

		now <- 包含 j 但不包含 S 的所有状态 
		f[j][S | now] = max f[i][S] + g[now] + d[i][now] 
	*/
	
	ll n, m, Max, w[N][N];
	ll g[(1 << 16) + 3], d[N][(1 << 16) + 3], f[N][(1 << 16) + 3];
	
	inline void Cmax ( ll &a, ll b ) { (a < b) && (a = b); }
	
	int main() {
		n = read(), m = read();
		for (int i = 1, u, v; i <= m; ++i) 
			u = read(), v = read(), w[u][v] = w[v][u] = read();
		
		Set (f, -1);
		f[1][1] = 0, Max = (1 << n) - 1;
		For ( S, 0, Max ) For ( i, 1, n ) 
			if (S & (1 << i - 1)) For ( j, 1, i ) 
				if ((i ^ j) && (S & (1 << j - 1))) g[S] += w[i][j];
		For ( S, 0, Max ) For ( i, 1, n ) 
			if (!(S & (1 << i - 1))) For ( j, 1, n ) 
				if ((S & (1 << j - 1))) d[i][S] += w[i][j];
		
		For ( S, 0, Max ) For ( i, 1, n ) 
			if (S & (1 << i - 1) && f[i][S] >= 0) {
				ll nowS = Max ^ S;
				for (int now = nowS; now; now = nowS & (now - 1)) 
					Cmax(f[i][S | now], f[i][S] + g[now] + d[i][now]);
				// 转移点集 
				for (int j = 1; j <= n; ++j) 
					if (!(S & (1 << j - 1)) && w[i][j]) 
						Cmax(f[j][S | (1 << j - 1)], f[i][S] + w[i][j]);
				// 转移点 
			}
		return wln(g[Max] - f[n][Max]), 0;
	}
	
}

int main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	
	return Cesare :: main();
}

/*

*/




