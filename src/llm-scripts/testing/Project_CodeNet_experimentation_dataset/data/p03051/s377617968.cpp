#include <cstdio>
#include <iostream>
#include <vector>
#define mod 1000000007
#define MN 1050000

std::vector<int> v[MN];

int n, a[MN];
int b[MN], c[MN];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = b[i - 1] ^ a[i];
		c[i] = c[i - 1] + (b[i] == 0 ? 1 : 0);
		v[b[i]].push_back(i);
	}
	int ans = 0;
	for(int j = 1; j < (1 << 20); j++)
	{
		int Sumj = 0, Sum0 = 1;
		int S = v[j].size();
		for(int k = 0; k < S; k++)
		{
			if(k) Sum0 = (Sum0 + 1ll * Sumj * (c[v[j][k]] - c[v[j][k - 1]])) % mod;
			Sumj = (Sum0 + Sumj) % mod;
		}
		if(b[n] == j) ans = (ans + Sum0) % mod;
		if(b[n] == 0) ans = (ans + Sumj) % mod;
	}
	if(b[n] == 0)
	{
		int k = 1; 
		for(int j = 1; j <= c[n] - 1; j++) k = k * 2 % mod; 
		ans = (ans + k) % mod;
	}
	printf("%d\n", ans);
}