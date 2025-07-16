#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;

namespace zyt
{
	template<typename T>
	inline bool read(T &x)
	{
		char c;
		bool f = false;
		x = 0;
		do
			c = getchar();
		while (c != EOF && c != '-' && !isdigit(c));
		if (c == EOF)
			return false;
		if (c == '-')
			f = true, c = getchar();
		do
			x = x * 10 + c - '0', c = getchar();
		while (isdigit(c));
		if (f)
			x = -x;
		return true;
	}
	template<typename T>
	inline void write(T x)
	{
		static char buf[20];
		char *pos = buf;
		if (x < 0)
			putchar('-'), x = -x;
		do
			*pos++ = x % 10 + '0';
		while (x /= 10);
		while (pos > buf)
			putchar(*--pos);
	}
	typedef long long ll;	
	const int N = 1e5 + 10;
	int n, m, x[N], to[N], arr[N], id[N], ans[N];
	ll k;
	void trans(int *a, const int *b)
	{
		static int tmp[N];
		for (int i = 1; i < n; i++)
			tmp[i] = a[b[i]];
		memcpy(a + 1, tmp + 1, sizeof(int[n - 1]));
	}
	int work()
	{
		read(n);
		for (int i = 0; i < n; i++)
			read(x[i]), id[i] = to[i] = i;
		for (int i = n - 1; i > 0; i--)
			x[i] -= x[i - 1];
		read(m), read(k);
		for (int i = 1; i <= m; i++)
			read(arr[i]), --arr[i];
		for (int i = 1; i <= m; i++)
			swap(to[arr[i]], to[arr[i] + 1]);
		while (k)
		{
			if (k & 1)
				trans(id, to);
			trans(to, to);
			k >>= 1;
		}
		ll last;
		write(last = x[0]), putchar('\n');
		for (int i = 1; i < n; i++)
			write(last += x[id[i]]), putchar('\n');
		return 0;
	}
}
int main()
{
	return zyt::work();
}