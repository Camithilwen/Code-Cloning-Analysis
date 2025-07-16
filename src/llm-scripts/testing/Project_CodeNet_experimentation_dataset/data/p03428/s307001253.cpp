#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define REP(i,s,t) for( int i = s; i < t; i++ )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int x[N], y[N];
    rep(i, N) cin >> x[i] >> y[i];
    int cnt[N] = {};
    rep(i, 250000) {
        double maxd = -INF;
        int index = 0;
        double theta = (i/125000.0) * M_PI;
        rep(j, N) {
            if (maxd < x[j] * cos(theta) + y[j] * sin(theta)){
                index = j;
                maxd = x[j] * cos(theta) + y[j] * sin(theta);
            }
        }
        cnt[index]++;
    } 
    cout << fixed;
    rep(i, N) cout << cnt[i] / 250000.0 << endl;
    
    

    return 0;
}
