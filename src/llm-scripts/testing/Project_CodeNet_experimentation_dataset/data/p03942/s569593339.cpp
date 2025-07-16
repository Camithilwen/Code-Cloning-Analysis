#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int MaxN = 1000000;

int n;
char s[MaxN + 2], t[MaxN + 2];

int q_l, q_r;
int q[MaxN + 1];

inline int solve()
{
	if (!strcmp(s + 1, t + 1))
		return 0;

	q_l = 1, q_r = 0;

	int l = 0, last = n + 1;
	int res = 0;
	for (int i = n, j = n; i; --i)
	{
		if (i > 1 && t[i] == t[i - 1])
			continue;

		while (j > i || (j && s[j] != t[i]))
			--j;
		if (j == 0)
			return -1;

		q[++q_r] = j + ++l;
		while (q_l <= q_r && q[q_l] - l >= last)
			++q_l;

		res = max(res, q_r - q_l + 1);

		last = i - 1;
	}

	return res;
}

int main()
{
	scanf("%d", &n);
	scanf("%s%s", s + 1, t + 1);

	cout << solve() << endl;

	return 0;
}