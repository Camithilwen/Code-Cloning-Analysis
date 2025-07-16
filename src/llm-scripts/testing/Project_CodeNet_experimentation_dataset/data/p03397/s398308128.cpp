#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 3e5 + 10;
const int Mod = 1e9 + 7;

void Chkadd(int &x, const int &y) { if ((x += y) >= Mod) x -= Mod; }

char s[maxn];
int F[7], G[7];

int main()
{
	int n = fread(s, 1, maxn, stdin);
	while (s[n - 1] != '0' && s[n - 1] != '1' && s[n - 1] != '?') -- n;
	int *f = F, *g = G;
	f[0] = 1;
	for (int i = 0; i < n; ++ i)
	{
		swap(f, g);
		fill(f, f + 7, 0);
		if (s[i] != '1')
		{
			Chkadd(f[1], g[0]);
			Chkadd(f[2], g[1]);
			Chkadd(f[1], g[2]);
			Chkadd(f[4], g[3]);
			Chkadd(f[6], g[4]);
			Chkadd(f[5], g[5]);
			Chkadd(f[4], g[6]);
		}
		if (s[i] != '0')
		{
			Chkadd(f[3], g[0]);
			Chkadd(f[0], g[1]);
			Chkadd(f[1], g[2]);
			Chkadd(f[5], g[3]);
			Chkadd(f[3], g[4]);
			Chkadd(f[5], g[5]);
			Chkadd(f[4], g[6]);
		}
	}
	Chkadd(f[5], f[3]);
	printf("%d\n", f[5]);
	return 0;
}
