#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#define maxn 510
#define ll long long

using namespace std;

int n;
ll a[maxn][maxn], primes[2020];
bool st[1000010];
int cnt;

void getprimes()
{
	for (int i = 2; i <= 10000; i ++ )
	{
		if (!st[i]) primes[++cnt] = i;
		for (int j = 1; primes[j] * i <= 10000; j ++ )
		{
			st[primes[j] * i] = 1;
			if (i % primes[j] == 0) break;
		}
	}
}

ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
	if (!a || !b) return a + b;
	return a / gcd(a, b) * b;
}

int main()
{
	getprimes();
	scanf("%d", &n);
	
	if (n == 2)
	{
		puts("2 3");
		puts("5 4");
		return 0;
	}
	
	for (int i = 1; i <= n; i ++ )
		for (int j = (i + 1 & 1) + 1; j <= n; j += 2)
			a[i][j] = primes[(i + j) / 2] * primes[n + (i - j) / 2 + (n + 1) / 2];
	
	for (int i = 1; i <= n; i ++ )
		for (int j = ((i & 1) + 1); j <= n; j += 2)
			a[i][j] = lcm(lcm(a[i][j - 1], a[i - 1][j]), lcm(a[i + 1][j], a[i][j + 1])) + 1;
	
	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 1; j <= n; j ++ ) cout << a[i][j] << ' ';
		puts("");
	}
	
	return 0;
}