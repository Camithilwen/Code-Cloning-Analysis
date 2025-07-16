#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    set<pair<int, int>> st;
    multiset<int> mst;
    for (int i = 0; i < w; i++) {
        st.emplace(i, i);
        mst.emplace(0);
    }
    st.emplace(w, w);
    int inf = 1e9;
    mst.emplace(inf);
    for (int i = 0; i < h; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        vector<pair<int, int>> v;
        int c = -1;
        for (auto it = st.lower_bound({a, -1}); it != st.end(); it++) {
            pair<int, int> p = *it;
            if (a <= p.first && p.first <= b) {
                c = max(c, p.second);
                v.emplace_back(p);
            } else {
                break;
            }
        }
        for (auto p : v) {
            st.erase(p);
            mst.erase(mst.find((p.first == w ? inf : p.first - p.second)));
        }
        if (c != -1) {
            st.emplace(b, c);
            if (b == w) {
                b = inf;
                c = 0;
            }
            mst.emplace(b - c);
        }
        int res = *mst.begin();
        if (res >= 1e8) {
            cout << -1 << '\n';
        } else {
            cout << res + i + 1 << '\n';
        }
    }
    return 0;
}