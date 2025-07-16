#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <unordered_map>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int MAXN = 345;
double dp[MAXN][MAXN][MAXN];
bool visit[MAXN][MAXN][MAXN];

double dfs(int c1, int c2, int c3, int N) {
    if (visit[c1][c2][c3]) return dp[c1][c2][c3];
    visit[c1][c2][c3] = 1;
    if (!c1 && !c2 && !c3) return 0.0;
    int c0 = N - c1 - c2 - c3;
    double res = (double)c0 / N;
    if (c1) res += (dfs(c1 - 1, c2, c3, N) + 1) * ((double)c1 / N);
    if (c2) res += (dfs(c1 + 1, c2 - 1, c3, N) + 1) * ((double)c2 / N);
    if (c3) res += (dfs(c1, c2 + 1, c3 - 1, N) + 1) * ((double)c3 / N);
    return dp[c1][c2][c3] = ((double)N / (N - c0) * res);
}

int main() {
    int N;
    scanf("%d", &N);
    vector<int> cnt(4, 0);
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        cnt[a]++;
    }
    printf("%.10lf\n", dfs(cnt[1], cnt[2], cnt[3], N));
    return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
by Benq;
*/
