//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, t;
    cin >> k >> t;
    vi a(t);
    int ma = 0;
    rep(i, t) {
        cin >> a[i];
        ma = max(ma, a[i]);
    }

    if(ma <= k/2) {
        cout << 0 << endl;
    } else {
        if(k&1) {
            cout << ma-1-(k-ma) << endl;
        } else {
            cout << ma-1-(k-ma) << endl;
        }
    }
}