
#include <cstdio>

using namespace std;
typedef long long int LL;
const int Max_N(100050);

namespace io
{
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush (){fwrite (obuf, 1, oS - obuf, stdout);oS = obuf;}
	inline void putc (char x){*oS ++ = x;if (oS == oT) flush ();}
	template <class I>
	inline void gi (I &x) {for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;}
	template <class I>
	inline void print (I x){
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;while(x) qu[++ qr] = x % 10 + '0',  x /= 10;while (qr) putc (qu[qr--]);}
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io::gi;
using io::putc;
using io::print;

int N, S, X[Max_N], V[Max_N];
LL P[Max_N], Ans;

void solve(int l, int r)
{
	if (l == r)
	{
		V[++V[0]] = X[l], V[++V[0]] = S;
		return;
	}
	if (S < X[l])
	{
		V[++V[0]] = X[r], solve(l, r - 1);
		return;
	}
	if (S > X[r])
	{
		V[++V[0]] = X[l], solve(l + 1, r);
		return;
	}
	if (P[l] >= P[r])
		V[++V[0]] = X[r], P[l] += P[r], solve(l, r - 1);
	else
		V[++V[0]] = X[l], P[r] += P[l], solve(l + 1, r);
}

constexpr int Abs(int x)
{
	return x >= 0 ? x : -x;
}

int main()
{
	gi(N), gi(S);
	for (int i = 1;i <= N;++i)
		gi(X[i]), gi(P[i]);
	solve(1, N);
	for (int i = V[0] - 1;i >= 1;--i)
		Ans += Abs(V[i + 1] - V[i]);
	print(Ans);
	return 0;
}