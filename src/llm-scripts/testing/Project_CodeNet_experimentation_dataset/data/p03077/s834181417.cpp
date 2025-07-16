#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll N, A, B, C, D, E;
    cin >> N >> A >> B >> C >> D >> E;
    ll ans = 5;
    ll mincap = min(min(min(A, B), min(C, D)), E);
    ans += N / mincap - 1;
    if (N % mincap != 0) ++ans;
    cout << ans << endl;
}
