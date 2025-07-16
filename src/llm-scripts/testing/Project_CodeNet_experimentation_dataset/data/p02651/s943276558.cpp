#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, vector<ll>> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(ti,t){
        int n;
        cin >> n;
        vector<ll> a(n);
        rep(i,n) cin >> a[i];
        string s;
        cin >> s;
        if(s.back() == 1){
            cout << 1 << endl;
            continue;
        }
        vector<P> v;
        v.push_back(P(0, {}));
        for(int i = n-1; i >= 0; --i){
            if(v.back().first == (s[i] - '0')){
                v.back().second.push_back(a[i]);
            }
            else{
                int nex = 1 - v.back().first;
                v.push_back(P(nex, {a[i]}));
            }
        }
        for(auto &p : v){
            sort(p.second.begin(), p.second.end());
        }
        int sz = v.size();
        vector<ll> buf;
        bool f = true;
        rep(i,sz){
            if(v[i].first == 0){
                for(ll x : v[i].second) buf.push_back(x);
            }
            else{
                auto memo = buf;
                int sz2 = memo.size();
                int rank = 0;
                for(int j = 59; j >= 0; --j){
                    int pivot = -1;
                    for(int k = rank; k < sz2; ++k){
                        if(memo[k] >> j & 1){
                            pivot = k;
                            break;
                        }
                    }
                    if(pivot == -1) continue;
                    swap(memo[pivot], memo[rank]);
                    for(int k = 0; k < sz2; ++k){
                        if(k != rank && (memo[k] >> j & 1)) memo[k] ^= memo[rank];
                    }
                    for(ll &x : v[i].second){
                        if(x >> j & 1) x ^= memo[rank];
                    }
                    ++rank;
                }
                for(ll x : v[i].second){
                    if(x != 0){
                        f = false;
                        break;
                    }
                }
                if(!f) break;
            }
        }
        cout << !f << endl;
    }
    return 0;
}
