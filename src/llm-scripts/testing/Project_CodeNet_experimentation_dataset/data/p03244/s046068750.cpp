#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int n;
    cin >> n;
    map<int,int> a, b;
    rep(i,n) {
        int v;
        cin >> v;
        if (i%2) a[v]++;
        else b[v]++;
    }
    priority_queue<P> ap, bp;
    for (auto p : a) {
        ap.emplace(p.second, p.first);
    }
    for (auto p : b) {
        bp.emplace(p.second, p.first);
    }
    vector<P> x, y;
    int cnt = 2;
    while (!ap.empty() && cnt > 0) {
        auto p = ap.top();
        ap.pop();
        x.push_back(p);
        cnt--;
    }
    cnt = 2;
    while (!bp.empty() && cnt > 0) {
        auto p = bp.top();
        bp.pop();
        y.push_back(p);
        cnt--;
    }
    int ans = INF;
    rep(i,x.size())rep(j,y.size()) {
        int now = 0;
        if (x[i].second == y[j].second) {
            now = n/2 + n/2 - max(x[i].first, y[j].first);
        }
        else {
            now = n - x[i].first - y[j].first;
        }
        ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}