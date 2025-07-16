#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

const ll INF = 1e15;

int main() {
    ll x, y;
    cin >> x >> y;

    ll ans = INF;
    if (x <= y) ans = min(ans, y - x);
    if (-x <= y) ans = min(ans, y+x+1);
    if (x <= -y) ans = min(ans, -y-x+1);
    if (-x <= -y) ans = min(ans, -y+x+2);
    cout << ans << endl;
    return 0;
}