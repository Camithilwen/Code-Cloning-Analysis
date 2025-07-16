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

const int MAXN = 234567;
int A[MAXN];
int sum[MAXN];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    while (K--) {
        for (int i = 0; i < N; i++) {
            int l = max(0, i - A[i]);
            int r = min(N, i + A[i]) + 1;
            sum[l]++;
            sum[r]--;
        }
        int cur = 0;
        for (int i = 0; i < N; i++) {
            cur += sum[i];
            A[i] = cur;
            sum[i] = 0;
        }
        bool OK = false;
        for (int i = 0; i < N; i++) {
            if (A[i] != N)
                OK = true;
        }
        if (!OK) break;
    }
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);

    return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
by Benq;
*/
