
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

const int N = 5010;
const ll INF = 1e18;
ll dp[N][N];

int main() {
    int n;
    cin >> n;
    vector<PL> a(n);
    REP(i,n){
        cin >> a[i].first >> a[i].second;
        a[i].first += a[i].second;
    }
    sort(ALL(a));
    VL h(n), p(n);
    REP(i,n){
        h[i] = a[i].first - a[i].second;
        p[i] = a[i].second;

        // cout << h[i] << " " << p[i] << endl;
    }

    REP(i,n+1) REP(j,n+1) dp[i][j] = INF;

    dp[0][0] = 0;
    REP(i,n) REP(j,n){
        dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        if (dp[i][j] <= h[i]) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + p[i]);
    }

    int ans = 0;
    REP(i,n+1) if (dp[n][i] < INF) ans = i;
    cout << ans << endl;


    return 0;
}



