#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 1e5 + 10;
const int MOD = 1e9 + 7;
int N, M, K, Q;
ll xA[MAX], yA[MAX];

int main()
{
	int i, j, k;
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; ++i) scanf("%lld", &xA[i]);
	for (i = 1; i <= M; ++i) scanf("%lld", &yA[i]);
	ll xsum, ysum;
	xsum = ysum = 0;
	for (i = 1; i < N; ++i) xsum = (xsum + (xA[i + 1] - xA[i]) * (ll)(N - i) %MOD * (ll)i % MOD) % MOD;
	for (i = 1; i < M; ++i) ysum = (ysum + (yA[i + 1] - yA[i]) * (ll)(M - i) %MOD * (ll)i % MOD) % MOD;
	printf("%lld", xsum*ysum %MOD);
}