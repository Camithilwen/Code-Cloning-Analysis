#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	char ch; bool flag = false; res = 0;
	while (ch = getchar(), !isdigit(ch) && ch != '-');
	ch == '-' ? flag = true : res = ch ^ 48;
	while (ch = getchar(), isdigit(ch))
		res = res * 10 + ch - 48;
	flag ? res = -res : 0;
}

template <class T>
inline void put(T x)
{
	if (x > 9)
		put(x / 10);
	putchar(x % 10 + 48);
}

template <class T>
inline void CkMax(T &x, T y) {x < y ? x = y : 0;}
template <class T>
inline void CkMin(T &x, T y) {x > y ? x = y : 0;}
template <class T>
inline T Max(T x, T y) {return x > y ? x : y;}
template <class T>
inline T Min(T x, T y) {return x < y ? x : y;}

typedef long long ll;
const int N = 1e5 + 5;
int a[N], n, m, V, P, ans;
ll sum[N];

int main()
{
	read(n); read(m); read(V); read(P);
	for (int i = 1; i <= n; ++i)
		read(a[i]);
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; ++i)
	{
		int l = std::upper_bound(a + 1, a + n + 1, a[i]) - a,
			r = std::upper_bound(a + 1, a + n + 1, a[i] + m) - a - 1;
		if (l - 2 + n - r >= V - 1)
		{
			if (n - r + 1 <= P)
				++ans;
		}
		else
		{
			V -= l - 1 + n - r;
			int tl = 0, tr = r - l + 1, res = -1;
			while (tl <= tr)
			{
				int mid = tl + tr >> 1;
				if (V <= mid || 1ll * (r - l + 1 - mid) * (a[i] + m) - (sum[r - mid] - sum[l - 1]) >= 1ll * (V - mid) * m)
					res = mid, tr = mid - 1;
				else
					tl = mid + 1;
			}
			if (~res)
			{
				if (n - r + 1 + res <= P)
					++ans;
			}
			V += l - 1 + n - r;
		}
	}
	put(ans), putchar('\n');
	
	return 0;
}