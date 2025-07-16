
#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
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

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

signed main() {
    int n, m;
    cin >> n >> m;

    int fl[100001];
    memset(fl, 0, sizeof(int) * 100001);

    int pe = 0;
    int ac = 0;

    rep(i, m) {
        int p; string s;
        cin >> p >> s;

        if (s == "AC") {
            if (fl[p] >= 0) {
                ++ac;
                pe += fl[p];
                fl[p] = -1;
            }
        } else {
            if (fl[p] >= 0) ++fl[p];
        }
    }

    cout << ac << " " << pe;

    return 0;
}
