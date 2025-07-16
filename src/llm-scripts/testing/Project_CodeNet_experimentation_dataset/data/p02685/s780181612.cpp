#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define MOD 998244353
#define INIT -1

long long int fact[200010] = {};

long long int mypow(long long int x, long long int n)
{
   if (n == 0)
      return 1;
   long long int tmp = mypow(x, n / 2);
   long long int res = (tmp * tmp) % MOD;
   if (n % 2 == 1)
      res = (res * x) % MOD;
   return res;
}

long long int comb(int n, int r)
{
   long long int res = fact[n];
   res = (res * mypow(fact[r], MOD - 2)) % MOD;
   res = (res * mypow(fact[n - r], MOD - 2)) % MOD;
   return res;
}

int main()
{
   long long int n, m, k;
   cin >> n >> m >> k;

   fact[0] = 1;
   for (int i = 1; i <= n - 1; i++)
   {
      fact[i] = (fact[i - 1] * i) % MOD;
   }

   long long int ans = 0;
   for (int i = 0; i <= k; i++)
   {
      ans += (m * ((comb(n - 1, i) * mypow(m - 1, n - 1 - i)) % MOD)) % MOD;
      ans %= MOD;
   }
   cout << ans << endl;
}