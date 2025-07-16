#include <cstdio>
#include <cstring>

#define Rep(i, n) for (int i = 1; i <= n; i ++)
#define Rep0(i, n) for (int i = 0; i <= n; i ++)

using namespace std;

typedef long long LL;
const int N = 110;

int d[N], cd;
LL f[N][N][2][2];

LL dfs(int l, int r, int g0, int g1, int gf)
{
	if (l < r) return (g0 == g1);
	if (l == r) {
		if (!(d[l] + g1 - g0 * 10)) return 10 - gf;
		return 0;
	}
	if (f[l][r][g0][g1] != -1) return f[l][r][g0][g1];
	LL ret = 0;
	Rep0(i, 9) {
		int tmp = d[r] + i + g1, tg1 = 0;
		if (tmp >= 10) tmp -= 10, tg1 = 1;
		if (!tmp && gf) continue;
		if (d[l] + tmp - g0 * 10 == i)
			ret += dfs(l - 1, r + 1, 0, tg1, 0); 
		if (d[l] + tmp - g0 * 10 + 1 == i)
			ret += dfs(l - 1, r + 1, 1, tg1, 0);
	}
	return f[l][r][g0][g1] = ret;
}

int main()
{
	int D;
	scanf("%d", &D);
	while (D) d[++ cd] = D % 10, D /= 10;
	
	memset(f, -1, sizeof(f));
	LL ans = 0;
	for (int i = cd; i <= 18; i ++){
		ans += dfs(i, 1, 0, 0, 1);
	//	printf("%d %lld\n", i, dfs(i, 1, 0, 0, 1));
	}
	printf("%lld\n", ans);
	
	return 0;
}
/*
45936
*/