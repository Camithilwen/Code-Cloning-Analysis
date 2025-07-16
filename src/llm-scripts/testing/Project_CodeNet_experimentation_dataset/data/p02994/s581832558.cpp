#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> d(n);
    for (int i = 1; i <= n; i++) {
        d[i-1] = l+i-1;
    }
    int all = 0;
    rep(i,n) all += d[i];
    int ans = 0;
    int mn = 10000;
    rep(i,n) {
        int dall = all-d[i];
        if (abs(all-dall) < mn) {
            mn = abs(all-dall);
            ans = dall;
        }
    }
    cout << ans << endl;
    return 0;
}