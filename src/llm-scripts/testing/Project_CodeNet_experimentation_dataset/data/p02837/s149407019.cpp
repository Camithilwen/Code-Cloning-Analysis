#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    vector<vector<int> > x(n), y(n);
    rep(i, n){
        cin >> a[i];
        rep(j, a[i]){
            int X, Y;
            cin >> X >> Y;
            X--;
            x[i].push_back(X);
            y[i].push_back(Y);
        }
    }
    rep(bit, 1<<n){
        bitset<16> tmp(bit);
        if((int)tmp.count() < ans) continue;
        bool ok = true;
        rep(i, n) {
            // 正直な人
            if(tmp.test(i)){
                rep(j, a[i]) {
                    // x[i][j]は正直者だと正直者が言っているのに実際には正直者ではない
                    if(tmp.test(x[i][j]) && y[i][j] == 0) {
                        ok = false;
                        break;
                    }
                    if(!tmp.test(x[i][j]) && y[i][j] == 1) {
                        ok = false;
                        break;
                    }
                }
            }
        }
        if(ok) chmax(ans, (int)tmp.count());
    }
    cout << ans << endl;
}