#include <algorithm>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
typedef long long ll;
typedef long double ld;
 
const ll MOD = 1e9 + 7, INF = 1e18 + 1;
 
using namespace std;

ll er[1000001], p[1000000], ptr, n, d[1000][1000];

ll gcd (ll a, ll b)
{
	if (!b) return a;
	else return gcd (b, a % b);
}

int main ()
{
	for (ll i = 2; i <= 1000000; i++)
		if (!er[i])
		{
			p[ptr++] = i;
			for (ll j = i * i; j <= 1000000; j += i)
				er[j] = 1;
		}

	cin >> n;

	for (int i = 0; i < 2 * n; i += 2)
		for (int j = 0; i + j < 2 * n; j++)
			d[j][i + j] = p[i / 2];


	for (int i = 2; i < 2 * n; i += 2)
		for (int j = 0; i + j < 2 * n; j++)
			d[i + j][j] = p[i / 2 + (n + 1) / 2 - 1];


	for (int i = 0; i < 2 * n; i += 2)
		for (int j = 0; i >= j; j++)
			d[i - j][j] *= p[i / 2 + n];

	ll mx = 0;

	if (n == 2)
	{
		printf ("4 7\n23 10");
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!d[i][j])
			{
				ll lcm = 1;
				if (j) lcm = lcm / gcd (lcm, d[i][j-1]) * d[i][j-1];
				if (j < n - 1) lcm = lcm / gcd (lcm, d[i][j+1]) * d[i][j+1];
				if (i) lcm = lcm / gcd (lcm, d[i-1][j]) * d[i-1][j];
				if (i < n - 1) lcm = lcm / gcd (lcm, d[i+1][j]) * d[i+1][j];

				d[i][j] = lcm + 1;
			}

			printf ("%lld ", d[i][j]);
		}
		putchar ('\n');
	}
}