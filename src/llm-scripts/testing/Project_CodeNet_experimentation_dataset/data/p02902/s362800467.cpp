#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    cout << fixed << setprecision(16);

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> G(n);
    while(m--) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
    }

    vector<ll> idx(n, -1);
    set<ll> cyc;
    {
        ll x = 0;
        auto dfs = [&](auto dfs, ll cur, ll pre) -> ll {
            if(idx[cur] > -1) {
                cyc.insert(cur);
                return cur;
            }
            idx[cur] = x++;

            for(auto &v: G[cur]) {
                ll r = dfs(dfs, v, cur);
                if(r == cur) return -2;
                if(r == -2) return -2;
                if(r > -1) {
                    cyc.insert(cur);
                    return r;
                }
            }
            return idx[cur] = -1;
        };
        for(ll i=0; i<n; i++) {
            fill(idx.begin(), idx.end(), -1);
            if(dfs(dfs, i, -1) == -2) break;
        }
        if(cyc.size() == 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    ll t = *cyc.begin();
    for(ll i=0; i<n; i++) {
        ll m = -1, mm = -1, s = t;
        for(auto &v: G[s]) {
            if(!cyc.count(v)) continue;
            if(idx[v] < idx[s] && mm < idx[v])
                mm = idx[v], t = v;
            if(mm == -1 && m < idx[v])
                m = idx[v], t = v;
        }
    }

    set<ll> res;
    for(ll i=0; i<n; i++) {
        ll m = -1, mm = -1, s = t;
        for(auto &v: G[s]) {
            if(!cyc.count(v)) continue;
            if(idx[v] < idx[s] && mm < idx[v])
                mm = idx[v], t = v;
            if(mm == -1 && m < idx[v])
                m = idx[v], t = v;
        }
        res.insert(t);
    }

    cout << res.size() << endl;
    for(auto &e: res) cout << e+1 << endl;

}
