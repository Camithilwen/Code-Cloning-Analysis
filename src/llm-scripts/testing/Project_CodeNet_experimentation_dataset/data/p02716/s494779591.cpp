#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 10000000000000000
#define int long long

int dp[200010][3];
int A[200010];
int N;
int calc(int x, int remain_skip) {
    //cout << x << " " << remain_skip << endl;
    if(dp[x][remain_skip] != -INF2) return dp[x][remain_skip];
    if(x >= N) {
        if(remain_skip == 2) return -INF2;
        return 0;
    }
    int ret = -INF2;
    if(remain_skip > 0) ret = calc(x + 1, remain_skip - 1);
    ret = max(ret, calc(x + 2, remain_skip) + A[x]);
    return dp[x][remain_skip] = ret;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N) cin >> A[i];
    rep(i, 200010) rep(j, 3) dp[i][j] = -INF2;
    cout << calc(0, 1 + (N % 2 == 1)) << endl;

    return 0;
}
// 1 2 3 4