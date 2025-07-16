#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv)vprint(v);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll H, W;
    cin >> H >> W;
    vll A(H), B(H);
    rep(i, H) cin >> A[i] >> B[i];

    map<int, int> m;
    rep(i, W) m[i] = 0;
    multiset<int> ms;
    rep(i, W) ms.insert(0);
    vll ans(H, 0);
    rep(i, H){
        int a = A[i]-1;
        int b = B[i]-1;
        auto lb = m.lower_bound(a);
        auto ub = m.upper_bound(b);
        if(lb!=m.end() && lb!=ub){
            --ub;
            auto it = lb;
            int k = ub->first;
            int v = ub->second;
            while(it!=m.end() && it->first!=k){
                int v = it->second;
                ms.erase(ms.find(v));
                it = m.erase(it);
            }
            if(b<W-1 && m.count(b+1)==0){
                m[b+1] = v+b-k+1;
                ms.insert(v+b-k+1);
            }
            m.erase(k);
            ms.erase(ms.find(v));
        }
        if(ms.empty()) ans[i] = -1;
        else ans[i] = *ms.begin() + i + 1;
    }
    rep(i, H) cout << ans[i] << endl;
}
