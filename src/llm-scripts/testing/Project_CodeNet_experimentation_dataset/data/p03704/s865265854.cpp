
#include <cstdio>
#include <cstring>

using namespace std;
const int Max_L(50);
typedef long long int LL;

int L, len, D[Max_L], N[Max_L], X[Max_L];
char input[Max_L];
LL Ans;

int work(int p, int x)
{
	int Ret(0);
	for (int c = (p == len - 1 ? 1 : 0);c <= 9;++c)
		if (0 <= c - x && c - x <= 9)
			++Ret;
	return Ret;
}

bool check()
{
	for (int i = len - 1, j;i >= 0;--i)
	{
		X[j = i] = N[i];
		while (X[j] < 0)
		{
			if (j == len - 1)
				return false;
			X[j] += 10, --X[++j];
		}
	}
	for (int i = 0;i <= len - 1;++i)
		if (X[i] != D[i])
			return false;
	return true;
}

void dfs(int p, int a, int b, int v, LL Ret = 1LL)
{
	if (!Ret)
		return;
	if (a <= b)
	{
		if (a == b)
			Ret *= work(a, 0);
		if (check())
			Ans += Ret;
		return;
	}
	int x = (D[p] + v) % 10;
	if (x == 0)
		if (D[p] + v == 0)
			N[p] = 0, N[len - 1 - p] = 0, dfs(p + 1, a - 1, b + 1, 0, Ret * work(a, 0));
		else
			N[p] = 0, N[len - 1 - p] = 0, dfs(p + 1, a - 1, b + 1, 1, Ret * work(a, 0));
	else
	{
		N[p] = x, N[len - 1 - p] = -x, dfs(p + 1, a - 1, b + 1, 0, Ret * work(a, x));
		N[p] = x - 10, N[len - 1 - p] = 10 - x, dfs(p + 1, a - 1, b + 1, 1, Ret * work(a, x - 10));
	}
}

int main()
{
	scanf("%s", input), L = strlen(input);
	for (int i = 0;i <= L - 1;++i)
		D[i] = input[L - 1 - i] - '0';
	for (len = L;len <= 19;++len)
		memset(N, 0, sizeof(N)), dfs(0, len - 1, 0, 0);
	printf("%lld", Ans);
	return 0;
}