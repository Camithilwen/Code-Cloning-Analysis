#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, cnt = 0; cin >> n;
    ll x; cin >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    rep(i,n) {
        if (x >= a[i]) {
            if (i == n-1 && x == a[i]) cnt++;
            else if (i != n-1) {
                x -= a[i];
                cnt++;
            }
        }
        else break; 
    }
    cout << cnt << endl;
    return 0;
}