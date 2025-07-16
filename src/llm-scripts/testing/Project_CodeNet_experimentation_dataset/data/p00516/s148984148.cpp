#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);i++)
#define rep(i,n) FOR(i,0,n)
#define ZERO(a) memset(a,0,sizeof(a))
#define pb push_back

int rank[1020];

int main() {
    int n, m;
    ZERO(rank);
    cin >> n >> m;
    vector<int> v;
    rep(i,n) {
        int cost; scanf("%d",&cost);
        v.pb(cost);
    }

    rep(i,m) {
        int c; scanf("%d",&c);
        rep(j,n) if(c >= v[j]) {
            rank[j+1]++; break;
        }
    }

    int ans = 0, ma = 0;
    rep(i,1001) if(ma < rank[i]) {
        ma = rank[i];
        ans = i;
    }
    cout << ans << "\n";

    return 0;
}