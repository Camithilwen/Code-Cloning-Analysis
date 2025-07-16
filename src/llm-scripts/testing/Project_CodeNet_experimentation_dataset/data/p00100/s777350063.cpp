#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const double PI = acos(-1);
const int inf = 2e9;
const long long INF = 2e18;
const long long MOD = 1e9+7;

#define sx(s) (s).size()
#define pb push_back
#define fi first
#define se second
#define REP(i,n) for (int i = 0; i < n; i++)
#define ALL(a) begin(a),end(a)

int main(void) {
    int n;
    while (cin >> n, n) {
        vector<pair<int,ll>> s(4000, {inf, 0});
        vector<bool> ip(4000,false);
        REP(i,n) {
            ll e,p,q;
            cin >> e >> p >> q;
            e--;
            if (ip[e]) {
                s[e].se += p*q;
            }
            else {
                s[e] = make_pair(i,p*q);
                ip[e] = true;
            }
        }
        vector<pair<int,int>> ans;
        REP(i, 4000) {
            if (s[i].se >= 1000000) {
                ans.pb({s[i].fi, i+1});
            }
        }
        sort(ALL(ans));
        REP(i,ans.size()) cout << ans[i].se << endl;
        if (ans.size() == 0) cout << "NA" << endl;
    }
    return 0;
}
