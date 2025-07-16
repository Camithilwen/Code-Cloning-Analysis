#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using P = pair<int,int>;

int main() {
    int h, w;
    cin >> h >> w;
    map<int,int> s;
    multiset<int> vals;
    rep(i,w) s[i] = i;
    rep(i,w) vals.insert(0);
    rep(i,h) {
        int l, r;
        cin >> l >> r;
        --l;
        auto it = s.lower_bound(l);
        int mr = -1;
        while (it != s.end() && it->first <= r) {
            mr = max(mr, it->second);
            int x = it->first - it->second;
            vals.erase(vals.find(x));
            s.erase(it++);
        }
        if (mr != -1 && r < w) {
            vals.insert(r - mr);
            s[r] = mr;
        }
        int ans = -1; 
        if (vals.size() > 0) {
            ans = *vals.begin() + (i+1);
        }
        cout << ans << endl;
    }
    return 0;
}