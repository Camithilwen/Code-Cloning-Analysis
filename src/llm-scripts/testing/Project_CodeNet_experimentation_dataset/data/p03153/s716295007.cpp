#pragma GCC optimize(2)
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 2e5 + 5;
int n, d, a[maxn];
ll dp[maxn];

int main() {
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; ++ i)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; ++ i) dp[i] = a[i];
	for (int i = 0; i + 1 < n; ++ i)
		dp[i + 1] = min(dp[i + 1], dp[i] + d);
	for (int i = n - 1; i; -- i)
		dp[i - 1] = min(dp[i - 1], dp[i] + d);
	ll ans = 0;
	for (int i = 0; i < n; ++ i) ans += a[i];
	for (int i = 1; i < n - 1; ++ i) ans += dp[i];
	printf("%lld\n", ans + 1LL * d * (n - 1));
	return 0;
}
