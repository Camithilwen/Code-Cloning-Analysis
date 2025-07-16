#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;

int main(void){
    cin >> n;
    vector<vector<pair<lli, lli>>> t(n);
    rep(i, n){
        lli ai;
        cin >> ai;
        rep(j, ai){
            lli x, y;
            cin >> x >> y;
            t[i].push_back({x-1, y});
        }
    }
    lli ans = 0;
    rep(b, (1<<n)){
        bool ok = true;
        rep(j, n){
            if(b>>j&1){
                rep(k, t[j].size()){
                    lli u = t[j][k].second;
                    lli v = b>>t[j][k].first&1;
                    if(u != v){
                        ok = false;
                    }
                }
            }
        }
        if(ok){
            ans = max(ans, (lli)__builtin_popcount(b));
        }
    }
    cout << ans << endl;
    return 0;
}
