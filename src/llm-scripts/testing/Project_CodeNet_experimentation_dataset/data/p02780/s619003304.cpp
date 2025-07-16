#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const int MOD = 998244353;
const ll INF = 1000000000000000000;

int p[200010];
double sum[200010];
int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> p[i];
	for (int i = 0; i < N; i++) {
		sum[i + 1] = sum[i] + (double)(p[i] * (p[i] + 1) / 2) / p[i];
	}
	double ans = 0.0;
	for (int i = 0; i < N - K + 1; i++) {
		ans = max(ans, sum[i + K] - sum[i]);
	}
	printf("%.10f\n", ans);
}