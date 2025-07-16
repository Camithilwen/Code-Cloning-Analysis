// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

// begin fast read template by CYJian (source: https://www.luogu.com.cn/paste/i11c3ppx)

namespace io {
	const int __SIZE = (1 << 21) + 1;
	char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55]; int __f, qr, _eof;
	#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush () { fwrite (obuf, 1, oS - obuf, stdout), oS = obuf; }
	inline void gc (char &x) { x = Gc(); }
	inline void pc (char x) { *oS ++ = x; if (oS == oT) flush (); }
	inline void pstr (const char *s) { int __len = strlen(s); for (__f = 0; __f < __len; ++__f) pc (s[__f]); }
	inline void gstr (char *s) { for(__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)  __c = Gc();
		for(; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc()) *s = __c; *s = 0; }
	template <class I> inline bool gi (I &x) { _eof = 0;
		for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc()) { if (__c == '-') __f = -1; _eof |= __c == EOF; }
		for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc()) x = x * 10 + (__c & 15), _eof |= __c == EOF; x *= __f; return !_eof; }
	template <class I> inline void print (I x) { if (!x) pc ('0'); if (x < 0) pc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10; while (qr) pc (qu[qr --]); }
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
} using io::pc; using io::gc; using io::pstr; using io::gstr; using io::gi; using io::print;

// end fast read template by CYJian

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

uint8_t can[30][200005];
int p2;
int a[200005], b[200005];
int n;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    gi(n);
	p2 = 1; rep(i, n-1) p2 = 2*p2%MOD;
	rep(i, n) gi(a[i]);
	rep(i, n) gi(b[i]);
	rep(l, 30) {
		int bv = 0;
		rep(i, n) bv = (bv*2+(bool)(b[i]&(1<<l)))%MOD;
		rep(x, 2) {
			int av = 0;
			rep(i, n) av = (av*2+(x^(bool)(a[i]&(1<<l))))%MOD;
			rep(k, n) {
				if(av == bv) can[l][k]=(x+1);
				av = (av+MOD-p2*(x^(bool)(a[k]&(1<<l))))%MOD;
				av = (av*2+(x^(bool)(a[k]&(1<<l))))%MOD;
			}
		}
	}
	rep(k, n) {
		int x = 0;
		rep(l, 30) {
			if(!can[l][k]) { x = -1; break; }
			x |= ((can[l][k]-1)<<l);
		}
		if(x != -1) print(k), pc(' '), print(x), pc('\n');
	}
}
