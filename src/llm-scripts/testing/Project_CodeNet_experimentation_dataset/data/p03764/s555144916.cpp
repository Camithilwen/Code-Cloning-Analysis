#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
int x[100010], y[100010];
int n, m;
int sumx[100010], sumy[100010];

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    rep(i, n) {
        cin >> x[i];
        sumx[i + 1] = (sumx[i + 1] + x[i] + sumx[i]) % mod;
    }
    rep(i, m) {
        cin >> y[i];
        sumy[i + 1] = (sumy[i + 1] + y[i] + sumy[i]) % mod;
    }
    int ansX = 0, ansY = 0;
    rep(i, n - 1) {
        ansX = (ansX + (-x[i] * (n - i - 1)) % mod + (sumx[n] - sumx[i + 1]) % mod + mod) % mod ;
        //cout << -x[i] * (n - i - 1)  <<" " << (sumx[n] - sumx[i + 1]) << endl;
    }
    rep(i, m - 1) {
        ansY = (ansY + (-y[i] * (m - i - 1)) % mod + (sumy[m] - sumy[i + 1]) % mod + mod) % mod;
    }
    cout << (ansX * ansY) % mod << endl;

    return 0;
}
