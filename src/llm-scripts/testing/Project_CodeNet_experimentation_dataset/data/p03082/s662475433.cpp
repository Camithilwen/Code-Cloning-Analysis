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
const ll N = 211;
const ll INF = 5e16;
const ll P = 1e9 + 7;

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
		最小的用掉后答案就不会变了。 
		设 f[i][0/1] 表示做了 i 次， 
		最小的被用掉/没被用掉的答案。 

		枚举 s[n] 在什么时候被用掉。 
		对于每个 pos, 其他有 (n - 1)! 种排列 
		方式。 
		但只有前 pos - 1 个会对答案造成贡献， 
		所以考虑怎么选择这前 pos - 1 个。 
		每次操作就是把 X % s[i] 
		
		前面的思路都是对的！就是不会设计状态了。 
		
		设 f[i][j] 表示做了 i 次，当前数为 j 。 
		f[i][j % a[i]] = f[i - 1][j] * (n - i + 1)
	*/
	
	const ll M = 100011;
	
	ll n, X, Ans, s[N], f[N][M];
	
	inline void Add ( ll &a, ll b ) { (a += b) >= P && (a -= P); }
	
	int main() {
		n = read(), X = read();
		For ( i, 1, n ) s[i] = read();
		sort(s + 1, s + n + 1, greater <ll> ());
		
		f[0][X] = 1;
		For ( i, 1, n ) For ( j, 0, X ) 
			(f[i][j % s[i]] += f[i - 1][j]) %= P,
			(f[i][j] += f[i - 1][j] * (n - i)) %= P;
		For ( i, 1, X ) Add(Ans, f[n][i] * i % P);
		return wln(Ans), 0;
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




