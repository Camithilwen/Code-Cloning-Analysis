#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP1(i,a,b) for (int i = a; i <= (int)(b); i++)
using namespace std;
const int MOD=998244353;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> c(n),d(n);
    REP(i,n) cin >> d[i], c[d[i]]++;
    if ( d[0]!=0 || c[0]>1 ) { cout << 0 << '\n'; return 0; }
    int ans=1;
    REP1(i,1,n-1) {
        if ( c[i-1]==0 && c[i]==0 ) continue;
        REP(j,c[i]) ans=(long long)ans*c[i-1]%MOD;
    }
    cout << ans << '\n';
    return 0;
}