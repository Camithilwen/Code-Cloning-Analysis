#include<bits/stdc++.h>
//#include<tr1/unordered_map>
//#include"Bignum/bignum.h"
//#define lll bignum
#define ls(x) ( x << 1 )
#define rs(x) ( x << 1 | 1 )
//#define mid ( ( l + r ) >> 1 )
#define lowbit(x) ( x & -x )
#define debug(x) (cout << "#x = " << x << endl)
#define re register
#define For(i, j, k) for(re int i = (j); i <= (k); i++)
#define foR(i, j, k) for(re int i = (j); i >= (k); i--)
#define Cross(i, j, k) for(re int i = (j); i; i = (k))
using namespace std;
typedef long long ll;
const ll N = 100011;
const ll inf = 0x3f3f3f3f3f3f;

ll n, m, k, x, a[N], b[N], c[N], B[N];
double res = 0;

namespace IO {

	#define dd ch = getchar()
	inline ll read() {
		ll x = 0; bool f = 0; char dd;
		for (; !isdigit (ch); dd) f ^= (ch == '-');
		for (; isdigit (ch); dd)  x = (x << 3) + (x << 1) + (ch ^ 48);
		return f? -x: x;
	}
	#undef dd

	inline void write( ll x ) {
		if ( x < 0 ) putchar ( '-' ), x = -x;
		if ( x > 9 ) write ( x / 10 ); putchar ( x % 10 | 48 );
	}

	inline void wrn ( ll x ) { write (x); putchar ( ' ' ); }

	inline void wln ( ll x ) { write (x); putchar ( '\n' ); }

	inline void wlnn ( ll x, ll y ) { wrn (x), wln (y); }

}

using namespace IO;

inline void Redouble ( ll x ) {
	for (; x; x >>= 1) {
		if (x & 1) {
			For ( i, 1, n ) B[i] = a[b[i]]; 
			For ( i, 1, n ) a[i] = B[i];
		}
		For ( i, 1, n ) B[i] = b[b[i]]; 
		For ( i, 1, n ) b[i] = B[i];
	}
}

int main() 
{
	n = read(); 
	For ( i, 1, n ) a[i] = read(), b[i] = i;
	foR ( i, n, 1 ) a[i] = a[i] - a[i - 1];
	m = read(), k = read();
	For ( i, 1, m ) x = read(), swap ( b[x], b[x + 1] );
	Redouble (k);
	For ( i, 1, n ) 
		res += a[i], printf ("%.1lf\n", res);
	return 0;
}

/*

*/

