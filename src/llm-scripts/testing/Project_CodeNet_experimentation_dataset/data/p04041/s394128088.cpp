#include <bits/stdc++.h>

#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

#define Grt ch = getchar()
#define DeBug(x) std::cout << #x << '=' << x << std::endl

typedef long long ll;
const int MaxN = 45, MaxS = 1 << 18, mod = 1e9 + 7;

namespace IO
{
	char buf[1<<15], *fs, *ft;
	inline char getc() { return ft == fs && (ft = (fs = buf) + fread(buf, 1, 1<<15, stdin), ft == fs) ? 0 : *fs++; }
	template <typename T> inline void read(T &x)
	{
		x = 0;
		T f = 1, Grt;
		while (!isdigit(ch) && ch ^ '-') Grt;
		if (ch == '-') f = -1, Grt;
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), Grt;
		x *= f;
	}

	template <typename T, typename... Args>
	inline void read(T &x, Args &...args) { read(x); read(args...); }

	char Out[1<<24], *fe = Out;
	inline void flush() { fwrite(Out, 1, fe - Out, stdout); fe = Out; }
	template <typename T> inline void write(T x, char str)
	{
		if (!x) *fe++ = 48;
		if (x < 0) *fe++ = '-', x = -x;
		T num = 0, ch[20];
		while (x) ch[++ num] = x % 10 + 48, x /= 10;
		while (num) *fe++ = ch[num --];
		*fe++ = str;
	}
}

using IO::read;
using IO::write;

template <typename T> inline bool chkMin(T &a, const T &b) { return a > b ? (a = b, true) : false; }
template <typename T> inline bool chkMax(T &a, const T &b) { return a < b ? (a = b, true) : false; }
template <typename T> inline T min(T a, T b) { return a < b ? a : b; }
template <typename T> inline T max(T a, T b) { return a > b ? a : b; }

ll f[MaxN][MaxS], ans = 1;
int main()
{
	int n, x, y, z; read(n, x, y, z);
	int state = (1 << (x + y + z - 1)) |  (1 << (y + z - 1)) | (1 << (z - 1));
	int sum = (1 << (x + y + z)) - 1;
	f[0][0] = 1;
	for (int i = 1; i <= n; ++ i)
	{
		(ans *= 10) %= mod;
		for (int s = 0; s <= sum; ++ s) if (f[i - 1][s])
			for (int c = 1, now; c <= 10; ++ c)
			{
				now = (s << c) | (1 << (c - 1)), now &= sum;
				if ((now & state) != state) f[i][now] = (f[i][now] + f[i - 1][s]) % mod;
			}
	}
	for (int s = 0; s <= sum; ++ s) ans = (ans - f[n][s] + mod) % mod;
	write(ans, '\n');
	IO::flush();
	return 0;
}