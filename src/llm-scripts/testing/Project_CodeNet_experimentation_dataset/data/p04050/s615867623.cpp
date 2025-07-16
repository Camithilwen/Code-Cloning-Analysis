#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <vector>
#define R register
#define IN inline
#define gc getchar()
#define ll long long
#define MX 105
template <class T>
IN void in(T &x)
{
	x = 0; R char c = gc;
	for (; !isdigit(c); c = gc);
	for (;  isdigit(c); c = gc)
	x = (x << 1) + (x << 3) + c - 48;
}
int n, sum;
std::vector <int> eve, odd;
int main(void)
{
	in(sum), in(n);
	int foo;
	for (R int i = 1; i <= n; ++i)
	{
		in(foo);
		if (foo & 1) odd.push_back(foo);
		else eve.push_back(foo);
	}
	if (n == 1)
	{
		if (sum == 1) printf("1\n1\n1");
		else printf("%d\n2\n%d %d", sum, 1, sum - 1);
		return 0;
	}
	if (odd.size() > 2) return puts("Impossible"), 0;
	else if (odd.size() == 2)
	{
		if (odd[0] > odd[1]) std::swap(odd[0], odd[1]);
		printf("%d ", odd[0]);
		for (auto i : eve) printf("%d ", i);
		printf("%d\n", odd[1]);
		odd[0]--, odd[1]++;
		if (!odd[0]) printf("%d\n", n - 1);
		else printf("%d\n%d ", n, odd[0]);
		for (auto i : eve) printf("%d ", i);
		printf("%d ", odd[1]);
	}
	else if (odd.size() == 1)
	{
		printf("%d ", odd[0]);
		for (auto i : eve) printf("%d ", i);
		puts("");
		odd[0]++, eve[eve.size() - 1]--;
		printf("%d\n", n);
		printf("%d ", odd[0]);
		for (auto i : eve) printf("%d ", i);
	}
	else
	{
		for (auto i : eve) printf("%d ", i);
		eve[0]++, eve[eve.size() - 1]--;
		printf("\n%d\n", n);
		for (auto i : eve) printf("%d ", i);
	}
}