//Be Name Khoda, Besmellah Rahmane Rahim, In The Name Of God;
//#include<bits/stdc++.h>
#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>
#include <stdio.h>
#include <string.h>
#include<iomanip>
#include<unordered_map>
#include<unordered_set>

using namespace std;

const long long N = 2e3 + 5;
const long long mod = 1e9 + 7;
long long dp[N][N];
long long fact[N * N];
long long n, k;
//dp[i][j] = the number of ways when i zero has come and j colorful ball has come


void pre()
{
	fact[0] = 1;
	for (long long i = 1; i < N * N; i++)
	{
		fact[i] = fact[i - 1] * i;
		fact[i] = fact[i] % mod;
	}
}

long long power(long long a, long long b)
{
	if (!b)
	{
		return 1;
	}
	long long ans = power(a, b / 2);
	ans = ans * ans;
	ans = ans % mod;
	if (b % 2)
	{
		ans = ans * a;
		ans = ans % mod;
	}
	return ans % mod;
}

long long choose(long long a, long long b)
{
	if (a > b)
	{
		return 0;
	}
	long long ans = fact[b];
	ans = ans * power(fact[a], mod - 2);
	ans = ans % mod;
	ans = ans * power(fact[b - a], mod - 2);
	ans = ans % mod;
	return ans;
}


int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	pre();
	cin >> n >> k;
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			// the i + j * (k - 1) + 1th ball 
			if (j > i)
			{
				continue;
			}
			if (i == j) // this ball only can be zero
			{
				dp[i + 1][j] += dp[i][j];
				dp[i + 1][j] %= mod;
				continue;
			}
			else
			{
				//this ball is zero
				dp[i + 1][j] += dp[i][j];
				dp[i + 1][j] %= mod;
				// this ball is colorful
				dp[i][j + 1] += dp[i][j] * choose(k - 2, n * k - i - j * (k - 1) - 1);
				dp[i][j + 1] %= mod;
			}
		}
	}
	if (k > 1)
	{
		cout << (dp[n][n] * fact[n]) % mod << endl;
	}
	else
	{
		cout << 1 << endl;
	}

}


