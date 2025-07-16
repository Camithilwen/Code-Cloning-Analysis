#include <vector>
#include <iostream>
#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

int n, bit[262145];

vector<int> a, b;

void add(int i, int x)
{
	while (i <= n)
	{
		bit[i] += x; i += i & -i;
	}
}

int sum(int i)
{
	int ret = 0;

	while (i > 0)
	{
		ret += bit[i]; i -= i & -i;
	}
	
	return ret;
}

int sum(int l, int r)
{
	return sum(r - 1) - sum(l - 1);
}

int main()
{
	scanf("%d", &n);

	a.resize(n);

	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	b = a; sort(b.begin(), b.end());

	long long ret = 0;

	for (int i = 0; i < n; i++)
	{
		int ptr = lower_bound(b.begin(), b.end(), a[i]) - b.begin(); add(ptr + 1, 1);

		ret += sum(ptr + 2, n + 1);
	}

	printf("%lld\n", ret);

	return 0;
}