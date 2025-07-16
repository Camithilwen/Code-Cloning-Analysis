
#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using vi = vector<int>;
using pi = pair<int, int>;
using vp = vector<pi>;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

#define P (1'000'000'007)

signed main() {
    int d, g;
    cin >> d >> g;

    vi vs;
    vp vc;

    rep(i, d) {
        int p, c;
        cin >> p >> c;

        vs.push_back(p - 1);
        vc.push_back(make_pair(p, (i + 1) * 100 * p + c));
    }
    
    int ans = INT_MAX;
    rep(i, 1 << d) {
        int cost = g;
        int res = 0;
        rep(j, d) {
            if (((1 << j) & i) > 0) {
                cost -= vc[j].second;
                res += vc[j].first;
            }
        }

        for (int j = d - 1; j >= 0; --j) {
            if (cost <= 0) break;
            if(((1 << j) & i) > 0) continue;
            int x = min(vs[j], 1 + (cost - 1) / ((j + 1) * 100));
            res += x;
            cost -= x * (j + 1) * 100;
        }

        if (cost <= 0) {
            chmin(ans, res);
        }
    }

    cout << ans;

    return 0;
}
