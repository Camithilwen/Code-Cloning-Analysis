#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;


int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    REP(i, n){
        REP(j, m){
            cin >> a.at(i).at(j);
            a.at(i).at(j)--;
        }
        reverse(ALL(a.at(i)));
    }

    ll ans = n;
    vector<bool> use(m, true);
    REP(_, m){
        vector<ll> count(m, 0);
        REP(i, n){
            while(!use.at(a.at(i).back())){
                a.at(i).pop_back();
            }
            count.at(a.at(i).back())++;
        }
        const ll max_idx = max_element(ALL(count)) - count.begin();
        ans = min(ans, count.at(max_idx));
        use.at(max_idx) = false;
    }
    cout << ans << endl;
    return 0;
}
