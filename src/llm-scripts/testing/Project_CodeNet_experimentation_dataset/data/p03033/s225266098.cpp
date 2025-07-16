#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1LL << 60;

ll N, Q;
vector<tuple<ll, ll, ll>> v;
set<P> st;

int main() {
    cin >> N >> Q;
    v.resize(N);

    rep(i, N) {
        ll s, t, x;
        cin >> s >> t >> x;
        v[i] = make_tuple(x, s, t);
    }
    sort(v.begin(), v.end());

    rep(i, Q) {
        ll d; cin >> d;
        st.insert(P(d, i));        
    }

    vector<ll> ans(Q);

    rep(i, N) {
        ll x, l, r;
        tie(x, l, r) = v[i];

        auto iter = st.lower_bound(P(l - x, -1));
        while (iter != st.end()) {
            if (iter->first >= r - x) break; 
            ans[iter->second] = x;
            st.erase(iter++);
        }
    }

    rep(i, Q) {
        if (ans[i] == 0) {
            cout << -1 << endl;
        } else {
            cout << ans[i] << endl;
        }
    }
}