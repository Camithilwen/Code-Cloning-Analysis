#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;
typedef tuple<int, int, int> tp;

// input
int N, Q;
vector<tp> XST;
vector<int> D;

vector<int> ans;
set<P> ds;


void input() {
    cin >> N >> Q;
    XST = vector<tp>(N);
    rep(i, N) {
        int s, t, x;
        cin >> s >> t >> x;
        XST[i] = tp(x, s, t);
    }
    D = vector<int>(Q);
    rep(i, Q) cin >> D[i];
}


int main() {
    input();
    sort(XST.begin(), XST.end());
    rep(i, Q) ds.insert(P(D[i], i));
    ans = vector<int>(Q, -1);
    rep(i, N) {
        int x, s, t;
        tie(x, s, t) = XST[i];
        auto itr = ds.lower_bound(P(s - x, 0));
        while (itr != ds.end()) {
            if (itr->first >= t - x) break;
            ans[itr->second] = x;
            ds.erase(itr++);
        }
    }
    rep(i, Q) printf("%d\n", ans[i]);
}
