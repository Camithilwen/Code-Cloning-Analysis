#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i-1] <= a[i]) continue;
        ans += a[i-1] - a[i];
        a[i] = a[i-1];
    }
    cout << ans << endl;
    return 0;
}