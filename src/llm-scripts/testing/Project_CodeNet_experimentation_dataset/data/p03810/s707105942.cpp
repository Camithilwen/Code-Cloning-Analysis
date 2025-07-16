#include <cstdio>
#include <cstring>
#include <algorithm>

inline int read()
{
	int data = 0, w = 1;
	char ch = getchar();
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') w = -1, ch = getchar();
	while (ch >= '0' && ch <= '9') data = data * 10 + (ch ^ 48), ch = getchar();
	return data * w;
}

const int N(100010);
int a[N], cnt[2], n;

void trans()
{
	for (int i = 1; i <= n; i++) if (a[i] & 1) --a[i]; int g = a[1];
	for (int i = 2; i <= n; i++) g = std::__gcd(g, a[i]);
	for (int i = 1; i <= n; i++) a[i] /= g;
}

int check()
{
	cnt[0] = cnt[1] = 0;
	for (int i = 1; i <= n; i++) ++cnt[a[i] & 1];
	if (cnt[0] & 1) return 1; else if (cnt[1] > 1) return 0;
	else
	{
		for (int i = 1; i <= n; i++) if (a[i] == 1) return cnt[0] & 1;
		return trans(), check() ^ 1;
	}
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	puts(check() ? "First" : "Second");
	return 0;
}
