#include <cstdio>
#include <algorithm>
int N, M, g[15][15], f[32768][15];
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0, u, v, w; i < M; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		u--, v--;
		g[u][v] = g[v][u] = w;
	}
	for (int i = 0; i < 1 << N; i++)
		for (int j = 0; j < N; j++)
			f[i][j] = 2000000000;
	for (int i = 1; i < 1 << N; i += 2)
		f[i][0] = 0;
	for (int i = 1; i < 1 << N; i++)
		for (int j = 0; j < N; j++)
			if (f[i][j] < 2000000000)
			{
				static int s[15];
				for (int k = 0; k < N; k++)
				{
					s[k] = 0;
					for (int l = 0; l < N; l++)
						if (i >> l & 1)
							s[k] += g[k][l];
				}
				for (int k = i; k < 1 << N; k = k + 1 | i)
				{
					int S = 0;
					for (int l = 0; l < N; l++)
						if (k - i >> l & 1)
							S += s[l];
					for (int l = 0; l < N; l++)
						if (k - i >> l & 1 && g[j][l])
							f[k][l] = std::min(f[k][l], f[i][j] + S - g[j][l]);
				}
			}
	printf("%d\n", f[(1 << N) - 1][N - 1]);
	return 0;
}
