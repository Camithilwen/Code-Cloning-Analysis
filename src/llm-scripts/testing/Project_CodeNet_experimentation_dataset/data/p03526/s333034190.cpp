#include <iostream>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define f first
#define s second

typedef long long LLI;



int n;


pair<int, pair<int, int> > p[5001];
long long dp[5001][5001];

const long long inf = 1e15;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d %d", &p[i].s.f, &p[i].s.s);
		p[i].f = p[i].s.f + p[i].s.s;
	}
	sort(p, p + n);
	
	for(int i = 0; i < 5001; ++i) {
		dp[i][0] = 0;
		for(int j = 1; j < 5001; ++j) dp[i][j] = inf;
	}
	

	int ans = 1;

	dp[0][1] = p[0].s.s;

	for(int i = 1; i < n; ++i) {
		for(int j = 1; j <= n; ++j) {
			dp[i][j] = dp[i-1][j];
			if(p[i].s.s + dp[i-1][j-1] < dp[i][j] && p[i].s.f >= dp[i-1][j-1]) dp[i][j] = p[i].s.s + dp[i-1][j-1];
			if(dp[i][j] < inf) ans = max(ans, j);
		}
	}
	printf("%d\n", ans);
	return 0;
}
