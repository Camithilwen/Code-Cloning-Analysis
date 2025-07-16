#include <cstdio>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
int arr[3][100005], nxt[100005], rev[100005];
bool vis[100005];
int main()
try
{
	// freopen("AGC006-E.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", arr[i] + j);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (my_abs(arr[j][i] - arr[j + 1][i]) != 1)
				throw false;
		}
		nxt[i] = (arr[1][i] + 1) / 3 - 1;
		if ((nxt[i] ^ i) & 1)
			throw false;
		rev[i & 1] ^= arr[0][i] > arr[2][i];
	}
	for (int i = 0; i < n; i++)
	{
		if (vis[i])
			continue;
		rev[i & 1 ^ 1] ^= 1;
		int x = i;
		while (!vis[x])
		{
			vis[x] = true;
			rev[i & 1 ^ 1] ^= 1;
			x = nxt[x];
		}
	}
	if (rev[0] || rev[1])
		throw false;
	puts("Yes");
	return 0;
}
catch (bool)
{
	puts("No");
	return 0;
}
